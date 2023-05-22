#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString reverse_(QString str){

    QString reverse_Out;
    char one='1';
    char zero='0';
    for(int i=0;i<str.length();i++){
        if(str[i]==one){
            str[i]=zero;
        }
        else{
            str[i]=one;
        }
    }

    return reverse_Out+=str;
}
QString checksum(const QString& str){
    bool ok=true;
    int andHex=0;
    int total=0;
    int intValue=0;
    QString reversebinaryValue;
    QString hexValue="";
    QString dectoHex;

    QByteArray array=str.toUtf8();

    qDebug()<<"array value:"<<array;

   for (int i = 0; i < array.length()-1; i+=2)
   {
        QByteArray hexByte = array.mid(i, 2);

         intValue  = hexByte.toInt(&ok, 16);
        if (ok){

            total += intValue;
        }

   }



    int complement = total += 0xFF;

      dectoHex = QString::number(complement, 16).toUpper();
                 QString binaryValue = QString::number(complement, 2);
                 reversebinaryValue = reverse_(binaryValue);


      andHex = reversebinaryValue.toInt(&ok, 2) & 0xFF;
                hexValue = QString::number(andHex, 16).toUpper();



    return  hexValue;

}
void MainWindow::on_pushButton_calculate_clicked()
{

    HexString=ui->lineEdit_hexValue->text();
    HexString.length()%2==0?ui->lineEdit_checkSum->setText(checksum(HexString)):ui->lineEdit_checkSum->setText("No such hex value.");

}

