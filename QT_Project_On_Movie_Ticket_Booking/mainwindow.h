#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mydb.h"
#include "book.h"
#include "cancel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateUI();
private slots:
    void on_btnBook_clicked();

    void on_btnCancel_clicked();

    void on_btnReset_clicked();

private:
    Ui::MainWindow *ui;
    book *ptrBook;
    cancel *ptrCancel;
};

#endif // MAINWINDOW_H
