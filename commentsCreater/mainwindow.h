#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "comment.h"
#include <QClipboard>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_generate_clicked();


private:
    Ui::MainWindow *ui;
    QClipboard *clip;
    commentStruct comStruct;
    Comments Com ;
};

#endif // MAINWINDOW_H
