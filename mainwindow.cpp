#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , game(new GameLogic(this))
{
    ui->setupUi(this);

    connect(game, &GameLogic::logMessage, this, &MainWindow::addToLog);

    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::onNewGame);
    connect(ui->checkButton, &QPushButton::clicked, this, &MainWindow::onCheck);
    connect(ui->gameMenuButton, &QPushButton::clicked, this, &MainWindow::onGameMenu);
    connect(ui->recordsMenuButton, &QPushButton::clicked, this, &MainWindow::onRecordsMenu);

    ui->stackedWidget->setCurrentIndex(0);
    ui->inputLineEdit->setEnabled(false);
    ui->checkButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

