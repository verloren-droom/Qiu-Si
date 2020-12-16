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

    // 设置中心控件
    sa_content = new QScrollArea(this);
    mainContent = new QLabel(sa_content);
    setCentralWidget(sa_content);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(mainContent);
    sa_content->setWidget(mainContent);
    sa_content->ensureWidgetVisible(mainContent, 5, 5);
    sa_content->setLayout(lay);

//    mainContent->setReadOnly(true);

    setWindowFlag(Qt::X11BypassWindowManagerHint);
}

void QiuSi::InitSet()
{
    QFont font = mainContent->font();
    QPalette fontPal = mainContent->palette();
    font.setItalic(ValueStore::fontItalic);
    font.setBold(ValueStore::fontBold);
    font.setPointSize(ValueStore::fontSize);
    mainContent->setPalette(fontPal);
    mainContent->setStyleSheet(QString("color: %1;background-color: %2").arg(ValueStore::fontColor).arg(ValueStore::themeColor));
    setStyleSheet(QString("background: %1").arg(ValueStore::themeColor));
    mainContent->setFont(font);
}

void QiuSi::InitBar(bool display)
{
    // 菜单栏
    if (display)
    {
        mainMenu = menuBar();
        setMenuBar(mainMenu);

        // 文件菜单
        fileMenu = mainMenu->addMenu("File");
        OpenFile();
        OpenNewWindow();
        QuitApp();

        // 工具菜单
        toolsMenu = mainMenu->addMenu("Tools");
        changeFontSize();
        OptionsApp();

        // 帮助菜单
        helpMenu = mainMenu->addMenu("Help");
        AboutApp();
    }

    setContextMenuPolicy(Qt::ActionsContextMenu);
//    setWindowFlags(Qt::CustomizeWindowHint);
}

QFont QiuSi::QiusiFont()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    return font;
}

QPalette QiuSi::QiusPalette()
{
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(192, 44, 56));
    return palette;
}

//void QiuSi::paintEvent(QEvent *ev)
//{

//}

// 打开文件
void QiuSi::OpenFile()
{
    openAction = fileMenu->addAction("Open File...");

    connect(openAction, &QAction::triggered, [=]{
        GetFile();
    });

    // 设置打开文件快捷键
    openAction->setShortcutContext(Qt::WidgetShortcut);
    openAction->setShortcut(QKeySequence::Open);
    sc_open = new QShortcut(QKeySequence::Open, this);
    connect(sc_open, &QShortcut::activated, [=]{
        GetFile();
    });
}

void QiuSi::OpenNewWindow()
{
    // 打开新的窗口
    openNewAction = fileMenu->addAction("Open New...");

    connect(openNewAction, &QAction::triggered, [=]{
        NewWindow();
    });

    openNewAction->setShortcutContext(Qt::WidgetShortcut);
    openNewAction->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_O);
    sc_openNew = new QShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_O, this);
    connect(sc_openNew, &QShortcut::activated, [=]{
        NewWindow();
    });

}

// 获得文件
bool QiuSi::GetFile()
{
    // 文件后缀
    suffixList << "txt" << "cpp" << "h" << "png" << "jpg" << "mp3";

    // 获取打开文件路径
    QFileDialog fileDia(this);
    path = fileDia.getOpenFileName(this, "Open File...", "D:/", "TXT Files(*.txt);;CPP Files(*.h *.cpp);;Image Files(*.png *.jpg);;Media File(*.mp3)");
    setWindowTitle(path);
//    FilterFile(path);

    // 获取打开文本行数
//    totalLine = mainContent->document()->lineCount();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QFileInfo currentFileInfo(file);
    QString fileSuffix {currentFileInfo.suffix()};
    file.close();

    // 筛选文件类型
    switch (suffixList.indexOf(fileSuffix))
    {
    case 0:case 1:case 2:
        OpenTxtFile(&file);
        break;
    case 3:case 4:
        OpenImageFile(path);
        break;
    case 5:
        OpenMusicFile(path);
        break;
    default:
        QMessageBox::warning(this, "Error opening file", "Unknown file type");
        break;
    }

    return true;
}

// 打开文本类型设置
void QiuSi::OpenTxtFile(QFile *txt)
{
    // 设置文本鼠标光标可选择，并在右上显示
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

// 打开图片类型设置
void QiuSi::OpenImageFile(QString filePath)
{
    setWindowTitle(filePath + " - Picture Viewer");
    QImage img(filePath);

    mainContent->setAlignment(Qt::AlignCenter);
    mainContent->setPixmap(QPixmap::fromImage(img)/*.scaled(mainContent->size())*/);
//    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint/* | Qt::Dialog | Qt::FramelessWindowHint*/);
//    sa_content->setMinimumSize(mainContent->size() - QSize(10, 10));
}

void QiuSi::OpenMusicFile(QString filePath)
{
    musicPlay = new QMediaPlayer(this);
    musicPlayList = new QMediaPlaylist(this);

    musicPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlayList->addMedia(QUrl::fromLocalFile(filePath));

    musicPlay->setPlaylist(musicPlayList);
    MusicPlayMode();
}

void QiuSi::MusicPlayMode()
{
    btn_musicPlay = new QPushButton(this);
    btn_musicPlay->setGeometry((this->width() - 100) / 2, this->height() - 50, 40, 40);
    btn_musicPlay->setIcon(QIcon(":icon/images/icon/play.png"));
//    btn_musicPlay->resize(50, 50);
    btn_musicPause = new QPushButton("Pause", this);
//    btn_musicPause->resize(50, 50);
    btn_musicPause->setGeometry((this->width() + 100) / 2, this->height() - 50, 40, 40);
    btn_musicPlay->show();
    btn_musicPause->show();

    connect(btn_musicPlay, &QPushButton::clicked, [=]{musicPlay->play();});
    connect(btn_musicPause, &QPushButton::clicked, [=]{musicPlay->pause();});
}

void QiuSi::NewWindow()
{
    newQiusi = new QiuSi;
    if (newQiusi->GetFile())
    {
        newQiusi->show();
        newQiusi->setAttribute(Qt::WA_DeleteOnClose);
    }
}

// 退出程序
void QiuSi::QuitApp()
{
    quitAction = fileMenu->addAction("Quit");

    connect(quitAction, &QAction::triggered, [=]{
        close();
    });

    // 设置退出快捷键
    sc_quit = new QShortcut(Qt::CTRL + Qt::Key_Q, this);
    quitAction->setShortcutContext(Qt::WidgetShortcut);
    quitAction->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(sc_quit, &QShortcut::activated, [=]{
        close();
    });
}

void QiuSi::changeFontSize()
{   
    addSizeAction = toolsMenu->addAction(QIcon(":icon/images/icon/add.png"), "Add");
    connect(addSizeAction, &QAction::triggered, [=]{
        DisplaySize();
        AddSize();

    });

    // 设置字体加大快捷键
    QKeySequence ks_add("Ctrl+=");
    sc_add = new QShortcut(ks_add, this);
    addSizeAction->setShortcut(QKeySequence("+"));
    connect(sc_add, &QShortcut::activated, [=]{
        DisplaySize();
        AddSize();
    });

    subSizeAction = toolsMenu->addAction(QIcon(":/icon/images/icon/remove.png"), "Sub");
    connect(subSizeAction, &QAction::triggered, [=]{
        SubSize();
        DisplaySize();
    });

    // 设置字体减小快捷键
    QKeySequence ks_sub("Ctrl+-");
    sc_sub = new QShortcut(ks_sub, this);
    subSizeAction->setShortcut(QKeySequence("-"));
    connect(sc_sub, &QShortcut::activated, [=]{
        SubSize();
        DisplaySize();
    });

    ValueStore::changeFontSize(ValueStore::fontSize);
}

void QiuSi::AddSize()
{
    QFont font;
    font.setPointSize(++ValueStore::fontSize);
    mainContent->setFont(font);
}

void QiuSi::SubSize()
{
    QFont font;
    font.setPointSize(--ValueStore::fontSize);
    mainContent->setFont(font);
}

void QiuSi::DisplaySize()
{
    lbl_displaySize = new QLabel(this);
    lbl_displaySize->setGeometry(width() - 100, 40, 100, 20);
    lbl_displaySize->setFont(QiusiFont());
    lbl_displaySize->setStyleSheet("background-color: #e2e1e4");
    lbl_displaySize->raise();
    lbl_displaySize->setText(QString("Size: %1").arg(QString::number(ValueStore::fontSize)));
    lbl_displaySize->show();

    QElapsedTimer *t = new QElapsedTimer;
    t->start();
    while (t->elapsed() < 1000)
        HiddenSize();
}

void QiuSi::HiddenSize()
{
    lbl_displaySize->setVisible(false);
    lbl_displaySize->setText("");
}

void QiuSi::OptionsApp()
{
    optionsAction = toolsMenu->addAction(QIcon(":icon/images/icon/settings.png"), "Options...");

    optionDia = new OptionsDia;
    optionDia->setWindowIcon(QiusiIcon());

    // 连接打开设置对话框
    connect(optionsAction, &QAction::triggered, [=]{
        optionDia->open();

        // 阻塞代码
        optionDia->exec();
    });
}

// 关于程序
void QiuSi::AboutApp()
{
    aboutAction = helpMenu->addAction(QIcon(":icon/images/icon/about.png"), "About Qiu-Si...");

    aboutDia = new AboutDia;
    aboutDia->setWindowIcon(QiusiIcon());

    // 连接打开关于窗口
    connect(aboutAction, &QAction::triggered, [=]{
//            QMessageBox::about(this, "Qiu-Si", "");
        aboutDia->open();

        // 阻塞代码
        aboutDia->exec();
    });
}

void QiuSi::mousePressEvent(QMouseEvent *ev)
{
    // 移动后部件所在的位置
    this->dPos = ev->globalPos() - this->pos();
}

void QiuSi::mouseMoveEvent(QMouseEvent *ev)
{
    // 移动位置
    move(ev->globalPos() - this->dPos);
}

QiuSi::~QiuSi()
{
    delete ui;
}
