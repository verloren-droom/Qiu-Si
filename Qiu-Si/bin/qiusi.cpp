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

inline QIcon QiuSi::UnifiedIcon()
{
    return QIcon(":/icon/images/icon/maple.png");
}

void QiuSi::InitUi()
{
    ui->setupUi(this);

    setWindowIcon(UnifiedIcon());

    InitBar();

    // 设置中心控件
    mainContent = new QLabel(this);
    setCentralWidget(mainContent);

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
    fontPal.setColor(QPalette::Text, QColor(100, 100, 100));
    mainContent->setPalette(fontPal);
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

QFont QiuSi::UnifiedFont()
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);
    return font;
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

// 获得文件
void QiuSi::GetFile()
{
    // 文件后缀
    suffixList << "txt" << "cpp" << "h" << "png" << "jpg";

    // 获取打开文件路径
    path = QFileDialog::getOpenFileName(this, "Open File...", "C:/", "TXT Files(*.txt);;CPP Files(*.h *.cpp);;Image Files(*.png *.jpg)");
    setWindowTitle(path);
//    FilterFile(path);

    // 获取打开文本行数
//    totalLine = mainContent->document()->lineCount();

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QFileInfo currentFileInfo(file);
    QString fileSuffix {currentFileInfo.suffix()};

    // 筛选文件类型
    switch (suffixList.indexOf(fileSuffix))
    {
    case 0:case 1:case 2:
        OpenTxtFile(&file);
        break;
    case 3:case 4:
        OpenImageFile(path);
        break;
    default:
        QMessageBox::warning(this, "Error opening file", "Unknown file type");
        break;
    }

    file.close();
}

// 打开文本类型设置
void QiuSi::OpenTxtFile(QFile *txt)
{
    // 设置文本鼠标光标可选择，并在右上显示
    mainContent->setTextInteractionFlags(Qt::TextSelectableByMouse);
    mainContent->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    txt->open(QIODevice::ReadOnly | QIODevice::Text);
//    int delayTime = 5;
//    QElapsedTimer timer;
//    timer.start();
    uchar* fPtr = txt->map(0, txt->size());
    QString txtStr;
    if (fPtr)
    {
//        DynamicProgressBar *progressBar = new DynamicProgressBar(txt->fileName());
        QCoreApplication::processEvents();
        txt->unmap(fPtr);
        while (!txt->atEnd())
        {
            txtStr += txt->readLine();
        }
        repaint();
    }
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
    QImage img(filePath);
    mainContent->setPixmap(QPixmap::fromImage(img)/*.scaled(mainContent->size())*/);
}

// 退出程序
void QiuSi::QuitApp()
{
    quitAction = fileMenu->addAction("Quit");

    connect(quitAction, &QAction::triggered, [=]{
        close();
    });

    // 设置退出快捷键
    QKeySequence ks_quit(QKeySequence("Ctrl+Q"));
    sc_quit = new QShortcut(ks_quit, this);
    quitAction->setShortcut(ks_quit);
    connect(sc_quit, &QShortcut::activated, [=]{
        close();
    });
}

void QiuSi::changeFontSize()
{
    addSizeAction = toolsMenu->addAction("Add");
    connect(addSizeAction, &QAction::triggered, [=]{
        AddSize();
    });

    // 设置字体加大快捷键
    QKeySequence ks_add("Ctrl+=");
    sc_add = new QShortcut(ks_add, this);
    addSizeAction->setShortcut(QKeySequence("+"));
    connect(sc_add, &QShortcut::activated, [=]{
        AddSize();
    });

    subSizeAction = toolsMenu->addAction("Sub");
    connect(subSizeAction, &QAction::triggered, [=]{
        SubSize();
    });

    // 设置字体减小快捷键
    QKeySequence ks_sub("Ctrl+-");
    sc_sub = new QShortcut(ks_sub, this);
    subSizeAction->setShortcut(QKeySequence("-"));
    connect(sc_sub, &QShortcut::activated, [=]{
        SubSize();
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

void QiuSi::OptionsApp()
{
    optionsAction = toolsMenu->addAction("Options...");

    optionDia = new OptionsDia;
    optionDia->setWindowIcon(UnifiedIcon());

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
    aboutAction = helpMenu->addAction("About Qiu-Si...");

    aboutDia = new AboutDia;
    aboutDia->setWindowIcon(UnifiedIcon());

    // 连接打开关于窗口
    connect(aboutAction, &QAction::triggered, [=]{
//            QMessageBox::about(this, "Qiu-Si", "");
        aboutDia->open();

        // 阻塞代码
        aboutDia->exec();
    });
}

QiuSi::~QiuSi()
{
    delete ui;
}
