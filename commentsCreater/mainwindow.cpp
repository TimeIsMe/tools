#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->text_code->viewport()->installEventFilter(this);
    ui->label_result->setText("Ready");
    clip = QApplication::clipboard();
    ui->textEdit_author->setText("wml");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->textEdit_function_name->clear();
    ui->textEdit_author->clear();
    ui->textEdit_brief->clear();
    ui->textEdit_p1_c->clear();
    ui->textEdit_p2_c->clear();
    ui->textEdit_p3_c->clear();
    ui->textEdit_p4_c->clear();
    ui->textEdit_p1_n->clear();
    ui->textEdit_p2_n->clear();
    ui->textEdit_p3_n->clear();
    ui->textEdit_p4_n->clear();
    ui->text_code->clear();
    ui->textEdit_r_n->clear();
    ui->textEdit_r_c->clear();
    ui->label_result->setText("cleared");
}

void MainWindow::on_pushButton_generate_clicked()
{
    this->comStruct.function_name = ui->textEdit_function_name->toPlainText();
    this->comStruct.author = ui->textEdit_author->toPlainText();
    this->comStruct.brief = ui->textEdit_brief->toPlainText();
    this->comStruct.param[0].name = ui->textEdit_p1_n->toPlainText();
    this->comStruct.param[1].name = ui->textEdit_p2_n->toPlainText();
    this->comStruct.param[2].name = ui->textEdit_p3_n->toPlainText();
    this->comStruct.param[3].name = ui->textEdit_p4_n->toPlainText();
    this->comStruct.param[0].component = ui->textEdit_p1_c->toPlainText();
    this->comStruct.param[1].component = ui->textEdit_p2_c->toPlainText();
    this->comStruct.param[2].component = ui->textEdit_p3_c->toPlainText();
    this->comStruct.param[3].component = ui->textEdit_p4_c->toPlainText();
    this->comStruct.retval.name = ui->textEdit_r_n->toPlainText();
    this->comStruct.retval.component = ui->textEdit_r_c->toPlainText();
    ui->text_code->setText(Com.getComments(this->comStruct));
    ui->label_result->setText("generated");


}



bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->text_code->viewport()){
        if(event->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton){
                //qDebug() << __FILE__ << __LINE__ << QString::number(event->type());
                //qDebug() << ui->text_code->toPlainText().length();
                if(ui->text_code->toPlainText().length()>0){
                    clip->setText(ui->text_code->toPlainText());
                    ui->label_result->setText("had copied!");
                }

                return QWidget::eventFilter(obj,event);
            }
        }
    }
}









