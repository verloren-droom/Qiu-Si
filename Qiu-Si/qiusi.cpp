#include "qiusi.h"
#include "ui_qiusi.h"

QiuSi::QiuSi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QiuSi)
{
    InitUi();
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
    txt_content = new QTextEdit(this);
    setCentralWidget(txt_content);

    txt_content->setReadOnly(true);

    setWindowFlag(Qt::X11BypassWindowManagerHint);
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
        AddFontSize();
        SubFontSize();
        OptionsApp();

        // 帮助菜单
        helpMenu = mainMenu->addMenu("Help");
        AboutApp();
    }

    // 初始化工具栏
    InitNumBar();
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

void QiuSi::InitNumBar()
{
    numBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, numBar);
    numBar->setFloatable(false);
    numBar->setMovable(false);
    numBar->setOrientation(Qt::Vertical);
//    numBar->resize(20, txt_content->height());
}

// 打开文件
void QiuSi::OpenFile()
{
    openAction = fileMenu->addAction("Open File...");

    connect(openAction, &QAction::triggered, [=]{
        GetFile();
    });

    // 设置打开文件快捷键
    QKeySequence ks_open("Ctrl+O");
    sc_open = new QShortcut(ks_open, this);
    openAction->setShortcut(ks_open);
    connect(sc_open, &QShortcut::activated, [=]{
        GetFile();
    });
}

// 获得文件
void QiuSi::GetFile()
{
    // 获取打开文件路径
    path = QFileDialog::getOpenFileName(this, "Open File...", "C:/");
    QFile openFile(path);
    openFile.open(QIODevice::ReadOnly);
    QString txt = openFile.readAll();
    QTextStream in(&txt);
    txt_content->setText(txt);

    // 获取打开文本行数
    totalLine = txt_content->document()->lineCount();
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

void QiuSi::AddFontSize()
{
    addSizeAction = toolsMenu->addAction("Add +");
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
}

void QiuSi::AddSize()
{
    static int currentSize = txt_content->font().pointSize() + 1;
    QFont font;
    font.setPointSize(currentSize++);
    txt_content->setFont(font);
}

void QiuSi::SubFontSize()
{
    subSizeAction = toolsMenu->addAction("Sub -");
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
}

void QiuSi::SubSize()
{
    static int currentSize = txt_content->font().pointSize() - 1;
    QFont font;
    font.setPointSize(currentSize--);
    txt_content->setFont(font);
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
