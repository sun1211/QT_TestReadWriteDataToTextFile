#include "readwritetextdata.h"

ReadWriteTextData::ReadWriteTextData(QWidget *parent)
    : QWidget(parent)
{
    /*
     *     dataToShow               writeBtn
     *
     *                  readBtn
     *
     *                  dataToShow
     *
     */

    dataToShow = new QLabel(this);
    dataToWrite = new QLineEdit(this);
    readBtn = new QPushButton("Read",this);
    writeBtn = new QPushButton("Write",this);


    QHBoxLayout *topLay = new QHBoxLayout();
    topLay->addWidget(dataToWrite);
    topLay->addWidget(writeBtn);

    QVBoxLayout *mainLay  = new QVBoxLayout(this);
    mainLay->addLayout(topLay);
    mainLay->addWidget(readBtn);
    mainLay->addWidget(dataToShow);

    connect(readBtn,SIGNAL(clicked(bool)),this,SLOT(Read_on_click()));
    connect(writeBtn,SIGNAL(clicked(bool)),this,SLOT(Write_on_click()));



}

ReadWriteTextData::~ReadWriteTextData()
{

}

void ReadWriteTextData::Read_on_click()
{
    QString strData = "";
    //create a dialog to get the path or use default to test
    QString urlData = "/sdcard/DataX.txt";

    QFile FileToRead(urlData);

    FileToRead.open(QIODevice::ReadOnly|QIODevice::Text);
    if(FileToRead.isOpen()){
        QTextStream readFile(&FileToRead);
        while(!readFile.atEnd()){
//            strData += readFile.readAll();
            strData += readFile.readLine();
        }
    }

    dataToShow->setText(strData);
    qDebug() << "read: " << strData;

}

void ReadWriteTextData::Write_on_click()
{
    QString urlData = "/sdcard/DataX.txt";
    QFile *FileToWrite = new QFile(urlData);

    FileToWrite->open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream WriteData(FileToWrite);
//    for(int i = 0; i < 100; i++){
//       WriteData << QString::number(i) << endl;
//    }
    WriteData << dataToWrite->text() << endl;
    qDebug() << "Write: " << dataToWrite->text();

}
