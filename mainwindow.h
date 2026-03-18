#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamelogic.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNewGame();
    void onCheck();
    void onGameMenu();
    void onRecordsMenu();
    void addToLog(const QString &text);

private:
    Ui::MainWindow *ui;
    GameLogic *game;
    bool isplaying = false;

    void updateRecords();
};
#endif // MAINWINDOW_H
