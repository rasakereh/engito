#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <vector>

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(std::vector<std::string> &playerNames, QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    std::vector<QLabel *> lblPlayers;
    std::vector<QLineEdit *> txtPlayers;
    std::vector<std::string> playerNames;
    
    void groupWidgets();
    void monitorEvents(std::vector<std::string> &playerNames);
    void startGame(std::vector<std::string> &playerNames);
    void getPlayerNames(std::vector<std::string> &playerNames);
};

#endif // MAINWINDOW_H
