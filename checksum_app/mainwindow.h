#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QMessageBox>
#include <QStringConverter>
#include <QDebug>
#include <QRegularExpression>
#include <QList>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString HexString;
private slots:


    void on_pushButton_calculate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
