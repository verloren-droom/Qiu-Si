#include "qiusi.h"
#include "ui_qiusi.h"

QiuSi::QiuSi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QiuSi)
//    , valueStore(new ValueStore)
{

    InitUi();
    InitSet();
}

inline QIcon QiuSi::QiusiIcon()
{
    return QIcon(":/icon/images/icon/maple.png");
}

void QiuSi::InitUi()
{
    ui->setupUi(this);

    setWindowIcon(QiusiIcon());

    InitBar();
//    setStyleSheet("color: #c02c38");

    // Central widget Settings
    InitMainContent();

    setStyleSheet(QString("QMenu::item:selected{"
                          "color: #c02c38;}"
                          "QMenu::item:hover{"
                          "color: #c02c38;}"));

//    mainContent->setReadOnly(true);

    setWindowFlag(Qt::X11BypassWindowManagerHint);
}

// Initialization MainConntent function
void QiuSi::InitMainContent()
{
    sa_content = new QScrollArea(this);
    mainContent = new QLabel(sa_content);
    setCentralWidget(sa_content);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(mainContent);
    sa_content->setWidget(mainContent);
    sa_content->ensureWidgetVisible(mainContent, 5, 5);
    sa_content->setLayout(lay);
}

// Initialization Settings function
void QiuSi::InitSet()
{
    QFont font = mainContent->font();
    QPalette fontPal = mainContent->palette();
    font.setItalic(ValueStore::instance()->fontItalic);
    font.setBold(ValueStore::instance()->fontBold);
    font.setPointSize(ValueStore::instance()->fontSize);
    mainContent->setPalette(fontPal);
    mainContent->setStyleSheet(QString("color: %1;background-color: %2").arg(ValueStore::fontColor).arg(ValueStore::themeColor));
    setStyleSheet(QString("background: %1").arg(ValueStore::themeColor));
    mainContent->setFont(font);
}

// Initialize the bar function
void QiuSi::InitBar(bool display)
{
    if (!display)
        return;

    // The menu bar
    mainMenu = menuBar();
    setMenuBar(mainMenu);

    // The file menu
    fileMenu = mainMenu->addMenu("File");
    OpenFile();
    OpenNewWindow();
    QuitApp();

    // The tools menu
    toolsMenu = mainMenu->addMenu("Tools");
    changeFontSize();
    VideoMode();
    OptionsApp();

    // The help menu
    helpMenu = mainMenu->addMenu("Help");
    AboutApp();

    currentStatus = statusBar();
    currentStatus->setSizeGripEnabled(false);

    setContextMenuPolicy(Qt::ActionsContextMenu);
//    setWindowFlags(Qt::CustomizeWindowHint);
}

// QiuSi default font
QFont QiuSi::QiusiFont()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    return font;
}

// QiuSi default paltette
QString QiuSi::QiusiTinct()
{
    return QString("#c02c38");
}

//void QiuSi::paintEvent(QEvent *ev)
//{

//}

// Open file function
void QiuSi::OpenFile()
{
    icon_open = new QIcon(":icon/images/icon/Open_64x64.png");
    icon_open->addPixmap(QPixmap(":icon/images/icon/Open_64x64.png"), QIcon::Active, QIcon::On);
    icon_open->addPixmap(QPixmap(":icon/images/icon/Open_64x64_click.png"), QIcon::Active, QIcon::Off);
    openAction = fileMenu->addAction("Open File...");
    openAction->setIcon(*icon_open);

    connect(openAction, &QAction::triggered, [=]{
        GetFile();
    });

    // Set the open file shortcut key
    openAction->setShortcutContext(Qt::WidgetShortcut);
    openAction->setShortcut(QKeySequence::Open);
    sc_open = new QShortcut(QKeySequence::Open, this);
    connect(sc_open, &QShortcut::activated, [=]{
        GetFile();
    });
}

// Open new window function
void QiuSi::OpenNewWindow()
{
    icon_openNew = new QIcon(":icon/images/icon/Add_64x64.png");
    icon_openNew->addPixmap(QPixmap(":icon/images/icon/Add_64x64.png"), QIcon::Active, QIcon::On);
    icon_openNew->addPixmap(QPixmap(":icon/images/icon/Add_64x64_click.png"), QIcon::Active, QIcon::Off);
    openNewAction = fileMenu->addAction(QIcon(":icon/images/icon/Add_64x64.png"), "Open New...");
    openNewAction->setIcon(*icon_openNew);

    connect(openNewAction, &QAction::triggered, [=]{
        NewWindow();
    });

    // Set the shortcut key to open a new window
    openNewAction->setShortcutContext(Qt::WidgetShortcut);
    openNewAction->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_O);
    sc_openNew = new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_O, this);
    connect(sc_openNew, &QShortcut::activated, [=]{
        NewWindow();
    });

}

// New window function
void QiuSi::NewWindow()
{
    newQiusi = new QiuSi;
    if (!newQiusi->GetFile())
        return;
    newQiusi->show();
    newQiusi->setAttribute(Qt::WA_DeleteOnClose);
}

// Get file function
bool QiuSi::GetFile()
{
//    openAction->setIcon(QIcon(":/icon/images/icon/Open_64x64_click.png"));

    // Defines an openable file suffix
    suffixList << "txt" << "cpp" << "h" << "png" << "jpg" << "mp3";

    // Gets the open file path
    QFileDialog fileDia(this);
    path = fileDia.getOpenFileName(this, "Open File...", "D:/", "TXT Files(*.txt);;CPP Files(*.h *.cpp);;Image Files(*.png *.jpg);;Media File(*.mp3)");
    setWindowTitle(path);
//    FilterFile(path);

//    totalLine = mainContent->document()->lineCount();

//    QFile file(path);
    file.setFileName(path);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QFileInfo currentFileInfo(file);
    QString fileSuffix {currentFileInfo.suffix()};
    file.close();

    // Filter file type
    switch (suffixList.indexOf(fileSuffix))
    {
    case 0:case 1:case 2:
        OpenTxtFile(&file);
        break;
    case 3:case 4:
        OpenImageFile(path);
        break;
    case 5:
        if (ShowVideoUi(currentFileInfo, false))
            OpenMusicFile(path);
        break;
    default:
        QMessageBox::warning(this, "Error opening file", "Unknown file type");
        break;
    }

    return true;
}

// Turn on the text type Settings function
void QiuSi::OpenTxtFile(QFile *txt)
{
    // Set text mouse cursor to be selected, and display on top right
    mainContent->setTextInteractionFlags(Qt::TextSelectableByMouse);
    mainContent->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    sa_content->setMinimumSize(mainContent->size());

    setWindowTitle(txt->fileName() + " - Text Viewer");
    if (!txt->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "not file" , "please select file.");
        return;
    }
    QString txtStr;
    txtStr = txt->readAll();
    mainContent->setText(txtStr);

//    datastruct.nDatas = txt->size()/4;
//    QDataStream in(txt);
//    in.setByteOrder(QDataStream::LittleEndian);  //设置排列的顺序
//    in.setFloatingPointPrecision(QDataStream::SinglePrecision); //单精度
//    datastruct.data = new float[datastruct.nDatas];     //总共的字数
//    for(int i=0; i < datastruct.nDatas; ++i){
//        in >> datastruct.data[i];                          //添加元素
//    }

    txt->close();
}

// Open the image type Settings function
void QiuSi::OpenImageFile(const QString &filePath)
{
    setWindowTitle(filePath + " - Picture Viewer");
    QImage img(filePath);

    mainContent->setAlignment(Qt::AlignCenter);
    mainContent->setPixmap(QPixmap::fromImage(img)/*.scaled(mainContent->size())*/);
//    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint/* | Qt::Dialog | Qt::FramelessWindowHint*/);
//    sa_content->setMinimumSize(mainContent->size() - QSize(10, 10));
}

bool QiuSi::ShowVideoUi(const QFileInfo &info, bool isShow)
{
    if (videoMode == Q_NULLPTR)
        videoMode = new QiuSiVideoMode(QiusiTinct(), path, this);

    if (isShow)
    {
        currentStatus->removeWidget(videoMode);
        currentStatus->removeWidget(currentInfo);
        videoMode->close();
        currentInfo->close();
        volumeContrl->close();
    }
    else
    {
        currentStatus->setFixedHeight(80);
        videoMode->show();
        currentInfo = new QiuSiStatusInfo(info.baseName(), ":icon/images/icon/music_64.png", this);
        currentInfo->show();
        volumeContrl = new QiuSiVolumeControl(QiusiTinct(), this);
        volumeContrl->show();
        currentStatus->addWidget(currentInfo);
        currentStatus->addWidget(videoMode);
        currentStatus->addWidget(volumeContrl);
    }
    return isShow;
}

// Open the music Play mode window function
void QiuSi::OpenMusicFile(const QString &filePath)
{
    if (videoMode->isVisible())
        return;
    videoMode->SetVideoPath(filePath);
}

// Exit the program function
void QiuSi::QuitApp()
{
    icon_quit = new QIcon(":icon/images/icon/Exit_64x64.png");
    icon_quit->addPixmap(QPixmap(":icon/images/icon/Exit_64x64.png"), QIcon::Active, QIcon::On);
    icon_quit->addPixmap(QPixmap(":icon/images/icon/Exit_64x64_click.png"), QIcon::Active, QIcon::Off);

    quitAction = fileMenu->addAction(QIcon(":icon/images/icon/Exit_64x64.png"), "Quit");
    quitAction->setIcon(*icon_quit);

    connect(quitAction, &QAction::triggered, [=]{
        close();
    });

    // Set the exit shortcut key
    sc_quit = new QShortcut(Qt::CTRL + Qt::Key_Q, this);
    quitAction->setShortcutContext(Qt::WidgetShortcut);
    quitAction->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(sc_quit, &QShortcut::activated, [=]{
        close();
    });
}

// Change font size function
void QiuSi::changeFontSize()
{   
    icon_add = new QIcon(":icon/images/icon/Plus_64x64.png");
    icon_add->addPixmap(QPixmap(":icon/images/icon/Plus_64x64.png"), QIcon::Active, QIcon::On);
    icon_add->addPixmap(QPixmap(":icon/images/icon/Plus_64x64_click.png"), QIcon::Active, QIcon::Off);

    addSizeAction = toolsMenu->addAction(QIcon(":icon/images/icon/Plus_64x64.png"), "Add");
    addSizeAction->setIcon(*icon_add);

    connect(addSizeAction, &QAction::triggered, [=]{
        AddSize();
        DisplaySizePrompt();
    });

    // Set font size to increase the shortcut key
    sc_add = new QShortcut(QKeySequence("Ctrl+="), this);
    addSizeAction->setShortcut(QKeySequence("+"));
    connect(sc_add, &QShortcut::activated, [=]{
        AddSize();
        DisplaySizePrompt();
    });

    icon_sub = new QIcon(":icon/images/icon/Minus_64x64.png");
    icon_sub->addPixmap(QPixmap(":icon/images/icon/Minus_64x64.png"), QIcon::Active, QIcon::On);
    icon_sub->addPixmap(QPixmap(":icon/images/icon/Minus_64x64_click.png"), QIcon::Active, QIcon::Off);

    subSizeAction = toolsMenu->addAction(QIcon(":icon/images/icon/Minus_64x64.png"), "Sub");
    subSizeAction->setIcon(*icon_sub);

    connect(subSizeAction, &QAction::triggered, [=]{
        SubSize();
        DisplaySizePrompt();
    });

    // Set the font reduction shortcut key
    sc_sub = new QShortcut(QKeySequence("Ctrl+-"), this);
    subSizeAction->setShortcut(QKeySequence("-"));
    connect(sc_sub, &QShortcut::activated, [=]{
        SubSize();
        DisplaySizePrompt();
    });

    ValueStore::instance()->changeFontSize(ValueStore::instance()->fontSize);
}

// Add font size function
void QiuSi::AddSize()
{
    QFont font;
    font.setPointSize(++ValueStore::instance()->fontSize);
    mainContent->setFont(font);
    emit changeSizeSignal();
}

// Reduce font size
void QiuSi::SubSize()
{
    QFont font;
    font.setPointSize(--ValueStore::instance()->fontSize);
    mainContent->setFont(font);
    emit changeSizeSignal();
}

// Displays font size prompts
void QiuSi::DisplaySizePrompt()
{
    lbl_displaySize = new QLabel(this);
    lbl_displaySize->setGeometry(width() - 120, 60, 100, 20);
    lbl_displaySize->setFont(QiusiFont());
    lbl_displaySize->setStyleSheet("background-color: #e2e1e4");
    lbl_displaySize->raise();
    lbl_displaySize->setText(QString("Size: %1").arg(QString::number(ValueStore::fontSize)));
    lbl_displaySize->show();

    QElapsedTimer *t = new QElapsedTimer;
    t->start();
    while (t->elapsed() < 1000)
        HiddenSizePrompt();
}

// Hidden font size prompts
void QiuSi::HiddenSizePrompt()
{
    lbl_displaySize->setVisible(false);
    lbl_displaySize->setText("");
}

// Switch audio playback mode
void QiuSi::VideoMode(const QString &path)
{
    icon_video = new QIcon(":icon/images/icon/Note_64x64.png");
    icon_video->addPixmap(QPixmap(":icon/images/icon/Note_64x64.png"), QIcon::Active, QIcon::On);
    icon_video->addPixmap(QPixmap(":icon/images/icon/Note_64x64_click.png"), QIcon::Active, QIcon::Off);

    videoModeAction = toolsMenu->addAction(QIcon(":icon/images/icon/Note_64x64.png"), "Video Model");
    videoModeAction->setIcon(*icon_video);

    videoMode = new QiuSiVideoMode(QiusiTinct(), path, this);
    videoMode->setHidden(true);

    connect(videoModeAction, &QAction::triggered, [=]{
        ShowVideoUi(file, videoMode->isVisible());
    });

    // Set the shortcut key to switch audio playback mode
    videoModeAction->setShortcutContext(Qt::WidgetShortcut);
    sc_music = new QShortcut(Qt::CTRL + Qt::Key_M, this);
    videoModeAction->setShortcut(Qt::CTRL + Qt::Key_M);
    connect(sc_music, &QShortcut::activated, [=]{
        ShowVideoUi(file, videoMode->isVisible());
    });
}

// Open setup function
void QiuSi::OptionsApp()
{
    icon_option = new QIcon(":icon/images/icon/Settings_64x64.png");
    icon_option->addPixmap(QPixmap(":icon/images/icon/Settings_64x64.png"), QIcon::Active, QIcon::On);
    icon_option->addPixmap(QPixmap(":icon/images/icon/Settings_64x64_click.png"), QIcon::Active, QIcon::Off);

    optionsAction = toolsMenu->addAction(QIcon(":icon/images/icon/Settings_64x64.png"), "Options...");
    optionsAction->setIcon(*icon_option);

    optionDia = new OptionsDia;
    optionDia->setWindowIcon(QiusiIcon());

    // Connect to open the Settings dialog
    connect(optionsAction, &QAction::triggered, [=]{
        optionDia->open();

        // Block of code
        optionDia->exec();
    });

    sc_option = new QShortcut(Qt::CTRL + Qt::Key_P, this);
    optionsAction->setShortcutContext(Qt::WidgetShortcut);
    optionsAction->setShortcut(Qt::CTRL + Qt::Key_P);
    connect(sc_option, &QShortcut::activated, [=]{
        optionDia->open();

        // Block of code
        optionDia->exec();
    });

    connect(optionDia, &OptionsDia::saveValue, this, &QiuSi::InitSet);
    connect(this, &QiuSi::changeSizeSignal, optionDia, &OptionsDia::fontSizeChange);
}

// About the program dialog
void QiuSi::AboutApp()
{
    aboutAction = helpMenu->addAction(QIcon(":icon/images/icon/about.png"), "About Qiu-Si...");

    aboutDia = new AboutDia;
    aboutDia->setWindowIcon(QiusiIcon());

    // Connect to open about window
    connect(aboutAction, &QAction::triggered, [=]{
        aboutDia->open();

        // Block of code
        aboutDia->exec();
    });
}

void QiuSi::mousePressEvent(QMouseEvent *ev)
{
    // The position of the component after it has been moved
    if (ev->button() == Qt::LeftButton)
        this->dPos = ev->globalPos() - this->pos();
}

void QiuSi::mouseMoveEvent(QMouseEvent *ev)
{
    // Mobile location
    if (ev->buttons() == Qt::LeftButton)
        move(ev->globalPos() - this->dPos);
}

QiuSi::~QiuSi()
{
    delete ui;
    delete icon_add;
    delete icon_open;
    delete icon_openNew;
    delete icon_option;
    delete icon_quit;
    delete icon_sub;
    delete icon_video;
}
