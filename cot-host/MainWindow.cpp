#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Logger.h"
#include "TextEditIODevice.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	_ui(new Ui::MainWindow),
	_wizard(new TestSettingsWizard(this))
{
	_ui->setupUi(this);
    connect(_ui->pushButton_st,&QPushButton::clicked, this, &MainWindow::newSettings);
	connect(_ui->pushButton_exit,&QPushButton::clicked, this, &QWidget::close);
    auto logDevice = new TextEditIODevice(_ui->textEdit_lg,this);
    Logger::setDevice(logDevice);
}

MainWindow::~MainWindow()
{
	delete _ui;
	delete _wizard;
}

void MainWindow::newSettings()
{
	_wizard->setWindowModality(Qt::WindowModal);
	_wizard->show();
}
