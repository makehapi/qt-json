#include "usefulmethod.h"
#include <QFile>
#include <QCoreApplication>
#include <QDebug>

UsefulMethod::UsefulMethod(QObject *parent) : QObject(parent)
{

}

QString UsefulMethod::getStringFromFile(QString filePath){
    qDebug()<<"文件地址:"<<filePath<<"\n";
    return QString(UsefulMethod::getContentFromFile(filePath));
}

QByteArray UsefulMethod::getContentFromFile(QString filePath){
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"file does not exist\n";
        return QByteArray();
    }else {
        QByteArray content = file.readAll();
        file.close();
        return content;
    }
}

QString UsefulMethod::getApplicationPath(){
    return QCoreApplication::applicationDirPath();
}
