#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usefulmethod.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QByteArray jsonContent = UsefulMethod::getContentFromFile(":/json/theme.json");
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonContent);
    QJsonObject jsonObj = jsonDoc.object();
    QVariant obj = jsonDoc.toVariant();
    QVariantMap objMap = jsonObj.toVariantMap();
    qDebug()<<"jsonDoc:\n"<<jsonDoc<<"\n"<<"jsonObj:\n"<<jsonObj<<"\n"<<"variant:\n"<<obj<<"variantMap:\n"<<objMap<<"\n";
}

MainWindow::~MainWindow()
{
    delete ui;
}
