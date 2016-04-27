#ifndef READWRITETEXTDATA_H
#define READWRITETEXTDATA_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QTime>
#include <QTimer>
#include <QDebug>

class ReadWriteTextData : public QWidget
{
    Q_OBJECT

public:
    ReadWriteTextData(QWidget *parent = 0);
    ~ReadWriteTextData();
    void readData();
    void WriteData();

    QPushButton *readBtn;
    QPushButton *writeBtn;
    QLineEdit *dataToWrite;
    QLabel *dataToShow;

public slots:
    void Read_on_click();
    void Write_on_click();
};

#endif // READWRITETEXTDATA_H
