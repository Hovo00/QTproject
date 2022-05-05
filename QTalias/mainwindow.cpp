#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setBackground();
    this->myfile = new QFile("/Users/test/Alias/myfile.txt");

}

MainWindow::~MainWindow()
{
    myfile->close();
    delete this->ui;
    delete this->myfile;
    delete this->timer;
}

void MainWindow::setBackground(){

    ui->centralwidget->setStyleSheet("background-color:indigo;");
    ui->centralwidget->show();

    ui->stackedWidget->setStyleSheet("background-color:indigo;");
    ui->stackedWidget->show();

    ui->label->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_3->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_4->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_5->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_6->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_7->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");

    ui->label_2->setStyleSheet("QLabel {background-color :indigo;color:red;}");
    ui->label_8->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_9->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_10->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_11->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_12->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_13->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_14->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_15->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_16->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_17->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_18->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_19->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_20->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_21->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_22->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");
    ui->label_23->setStyleSheet("QLabel {background-color :indigo;color:magenta;}");

    ui->pushButton->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_9->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_8->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_10->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_11->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_12->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    ui->pushButton_13->setStyleSheet("QPushButton {background-color :darkindigo;color:magenta;}");
    ui->pushButton_14->setStyleSheet("QPushButton {background-color :darkindigo;color:magenta;}");
    ui->pushButton_15->setStyleSheet("QPushButton {background-color :darkindigo;color:magenta;}");

    ui->lineEdit_2->setStyleSheet("QLineEdit {background-color :black;color:white;}");
    ui->lineEdit_3->setStyleSheet("QLineEdit {background-color :black;color:white;}");
    ui->lineEdit_4->setStyleSheet("QLineEdit {background-color :black;color:white;}");
    ui->lineEdit_6->setStyleSheet("QLineEdit {background-color :black;color:white;}");
    ui->lineEdit_5->setStyleSheet("QLineEdit {background-color :black;color:white;}");
    ui->lineEdit_7->setStyleSheet("QLineEdit {background-color :black;color:white;}");
    ui->lineEdit_8->setStyleSheet("QLineEdit {background-color :darkindigo;color:white;}");
    ui->lineEdit_9->setStyleSheet("QLineEdit {background-color :darkindigo;color:white;}");

    ui->lineEdit->setStyleSheet("QLineEdit {background-color :darkindigo;color:white;}");
    buttonsToDef();
}

void MainWindow::on_pushButton_clicked()
{
    openFileAndInit();
    this->ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    auto temp1 = ui->lineEdit_9->text().toInt();
    auto temp2 = ui->lineEdit_8->text().toInt();

    if(temp1 <= 200 && temp1 >= 10 && temp2 <= 400 && temp1 >= 20){
        this->ui->stackedWidget->setCurrentIndex(1);
        SecondTeamName = ui->lineEdit_2->text();
        FirstTeamName = ui->lineEdit_7->text();
        DefaultSeconds = ui->lineEdit_8->text().toInt();
        Seconds = DefaultSeconds;
        DefaultScore = ui->lineEdit_9->text().toInt();
        ui->label_5->setText(FirstTeamName);
        this->timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()),this,SLOT(timePrint()));
        timer->start(1000);
        }
}

void MainWindow::timePrint(){
    QString str = QString::number(Seconds);
    ui->label_4->setText(str);
    if (Seconds == 0) {
        updatePlayerResults();
        printPlayerResults();
        CurrTeamScore = 0;
    }
    --Seconds;
    }

void MainWindow::on_pushButton_9_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    if (clicked3){
        this->ui->pushButton_3->setStyleSheet("QPushButton {background-color :magenta;color:indigo}");
        this->clicked3 = false;
        --CurrTeamScore;
    }
    else{
        this->ui->pushButton_3->setStyleSheet("QPushButton {background-color :yellow;color:indigo}");
        this->clicked3 = true;
        if (allclicked()){
            generNewWords();
        }
        ++CurrTeamScore;
    }
    ui->label_7->setText(QString::number(CurrTeamScore));
}


void MainWindow::on_pushButton_4_clicked()
{

    if (clicked4){

        this->ui->pushButton_4->setStyleSheet("QPushButton {background-color :magenta;color:indigo}");
        this->clicked4 = false;
        --CurrTeamScore;
    }
    else{
        this->ui->pushButton_4->setStyleSheet("QPushButton {background-color :yellow;color:indigo}");
        this->clicked4 = true;
        if (allclicked()){
            generNewWords();
        }
        ++CurrTeamScore;
    }
    ui->label_7->setText(QString::number(CurrTeamScore));
}


void MainWindow::on_pushButton_5_clicked()
{
    if (clicked5){

        this->ui->pushButton_5->setStyleSheet("QPushButton {background-color :magenta;color:indigo}");
        this->clicked5 = false;
        --CurrTeamScore;
    }
    else{
        this->ui->pushButton_5->setStyleSheet("QPushButton {background-color :yellow;color:indigo}");
        this->clicked5 = true;
        if (allclicked()){
            generNewWords();
        }
        ++CurrTeamScore;
    }
    ui->label_7->setText(QString::number(CurrTeamScore));

}



void MainWindow::on_pushButton_6_clicked()
{
    if (clicked6){

        this->ui->pushButton_6->setStyleSheet("QPushButton {background-color :magenta;color:indigo}");
        this->clicked6 = false;
        --CurrTeamScore;
    }
    else{
        this->ui->pushButton_6->setStyleSheet("QPushButton {background-color :yellow;color:indigo}");
        this->clicked6 = true;
        if (allclicked()){
            generNewWords();
        }
        ++CurrTeamScore;
    }
    ui->label_7->setText(QString::number(CurrTeamScore));
}

void MainWindow::on_pushButton_7_clicked()
{
    if (clicked7){

        this->ui->pushButton_7->setStyleSheet("QPushButton {background-color :magenta;color:indigo}");
        this->clicked7 = false;
        --CurrTeamScore;
    }
    else{
        this->ui->pushButton_7->setStyleSheet("QPushButton {background-color :yellow; color:indigo}");
        this->clicked7 = true;
        if (allclicked()){
            generNewWords();
        }
        ++CurrTeamScore;
    }
    ui->label_7->setText(QString::number(CurrTeamScore));
}

bool MainWindow::allclicked(){
    if (clicked4 && clicked5 && clicked6 && clicked7 && clicked3)
        return true;
    else
        return false;
}

void MainWindow::generNewWords(){
    for(int i = 0; i < 5; ++i){
        if (index == 0) index = wordc - 1;
        int rand = QRandomGenerator::global()->generate() % (index + 1);
        buttons[i]->setText(words[rand]);
        qSwap(words[rand],words[index--]);
    }
    buttonsToDef();
}
void MainWindow::buttonsToDef(){
    this->ui->pushButton_3->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    this->ui->pushButton_4->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    this->ui->pushButton_5->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    this->ui->pushButton_6->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    this->ui->pushButton_7->setStyleSheet("QPushButton {background-color :magenta;color:indigo;}");
    this->ui->label_7->setText(QString::number(0));
    this->clicked3 = false;
    this->clicked4 = false;
    this->clicked5 = false;
    this->clicked6 = false;
    this->clicked7 = false;

}
void MainWindow::openFileAndInit(){
    if (!myfile->open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"title", "file not open");
    }
    else {
        while(!myfile->atEnd()){
            QString temp = myfile->readLine();
            this->words.append(temp);
            ++index;
        }
        wordc = index + 1;
        buttons.append(ui->pushButton_3);
        buttons.append(ui->pushButton_4);
        buttons.append(ui->pushButton_5);
        buttons.append(ui->pushButton_6);
        buttons.append(ui->pushButton_7);
        generNewWords();
        myfile->close();
    }


}
void MainWindow::addUserInputWords(const QString& word){
    if (!myfile->open(QIODevice::Append | QIODevice::Text)){
        QMessageBox::warning(this,"title", "file not open");
    }
    else {
        QTextStream add(myfile);
        add<<word<<Qt::endl;
        myfile->close();
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    //addUserInputWords();
    this->ui->stackedWidget->setCurrentIndex(4);


}
bool MainWindow::isWordAlreadyInFile(const QString& word){

    if (!myfile->open(QFile::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this,"title", "file not open");
        return true;
    }
    else {
        QTextStream check(myfile);
        while(!check.atEnd()){

            if (check.readLine() == word){

                return true;
            }
        }
        myfile->close();
        return false;
    }
}


void MainWindow::on_lineEdit_returnPressed()
{
    QString word = ui->lineEdit->text();

    if(isWordAlreadyInFile(word)){
        QMessageBox::information(this,"title", "Word already exists");
    }
    else{
        addUserInputWords(word);
        QMessageBox::information(this,"title", "Word was added to dict ");
        ui->lineEdit->clear();
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

int MainWindow::GameOver(){
    if (FirstTeamScore > SecondTeamScore && FirstGameCount == SecondGameCount && FirstTeamScore >= DefaultScore){
        return 1;
    }
    if (SecondTeamScore > FirstTeamScore && SecondTeamScore >= DefaultScore){
        return 2;
    }
    return 0;
}

void MainWindow::on_pushButton_13_clicked()
{
    generNewWords();
    Seconds = DefaultSeconds;
    CurrTeamScore = 0;
    this->ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_lineEdit_8_editingFinished()
{
    bool flag;
    double v = ui->lineEdit_8->text().toDouble(&flag);
    if (v < 10 || v > 200){
    QMessageBox::information(this,"title", "Input seconds 10 - 200 ");
    ui->lineEdit_8->setText(QString::number(this->DefaultSeconds));
    }
}


void MainWindow::on_lineEdit_9_editingFinished()
{
    bool flag;
    double v = ui->lineEdit_9->text().toDouble(&flag);
    if (v < 20 || v > 400){
    QMessageBox::information(this,"title", "Input score 20 - 400 ");
    ui->lineEdit_9->setText(QString::number(this->DefaultScore));
    }
}
void MainWindow::updatePlayerResults(){

    Seconds = DefaultSeconds;
    if (FirstGameCount - SecondGameCount == 0){
        FirstTeamScore += CurrTeamScore;
        ++FirstGameCount;
        ui->label_5->setText(SecondTeamName);
        }
    else{
        SecondTeamScore += CurrTeamScore;
        ++SecondGameCount;
        ui->label_5->setText(FirstTeamName);
        }
}

void MainWindow::printPlayerResults(){

    this->ui->label_13->setText(QString::number(this->FirstGameCount));
    this->ui->label_15->setText(QString::number(this->FirstTeamScore));
    this->ui->label_17->setText(QString::number(this->SecondGameCount));
    this->ui->label_19->setText(QString::number(this->SecondTeamScore));
    this->ui->label_10->setText(this->FirstTeamName);
    this->ui->label_11->setText(this->SecondTeamName);


    this->ui->stackedWidget->setCurrentIndex(2);
    if (GameOver()){
        if( GameOver() == 1){
            this->ui->label_23->setText(FirstTeamName);
        }
        else{
            this->ui->label_23->setText(SecondTeamName);

        }
        this->ui->stackedWidget->setCurrentIndex(6);

       }
}

void MainWindow::on_pushButton_11_clicked()
{
    myfile->close();
    QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(5);

}


void MainWindow::on_pushButton_14_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_15_clicked()
{
    myfile->close();
    QApplication::quit();

}



