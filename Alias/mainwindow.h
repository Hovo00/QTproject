#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QFile>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QTextStream>
#include <QTimer>
#include <QCoreApplication>
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
    void timePrint();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_lineEdit_8_editingFinished();

    void on_lineEdit_9_editingFinished();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();


private:
    Ui::MainWindow *ui;
    bool clicked3 = false;
    bool clicked4 = false;
    bool clicked5 = false;
    bool clicked6 = false;
    bool clicked7 = false;
    QString FirstTeamName;
    QString SecondTeamName;
    int FirstTeamScore = 0;
    int FirstGameCount = 0;
    int SecondTeamScore = 0;
    int SecondGameCount = 0;
    int CurrTeamScore = 0;
    int DefaultSeconds = 100;
    int Seconds = 0;
    int DefaultScore = 100;
    int GameOver();
    bool allclicked();
    QFile *myfile;
    QTimer *timer;
    QVector<QString> words;
    QVector<QPushButton*> buttons;
    size_t wordc;
    size_t index = -1;
    void generNewWords();
    void setBackground();
    void buttonsToDef();
    void openFileAndInit();
    void addUserInputWords(const QString&);
    bool isWordAlreadyInFile(const QString&);
    void updatePlayerResults();
    void printPlayerResults();
    void initFile();

};
#endif // MAINWINDOW_H
