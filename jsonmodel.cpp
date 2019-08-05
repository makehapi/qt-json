#include "jsonmodel.h"
#include <QDebug>

JsonArrayObjectArrayModel::JsonArrayObjectArrayModel(){

}

JsonArrayModel::JsonArrayModel(){

}

JsonModel::JsonModel()
{

}

JsonBaseModel::JsonBaseModel(const QByteArray &jsonContent){
    QJsonParseError *error = new QJsonParseError;
    doc = QJsonDocument::fromJson(jsonContent, error);
    if(error->error == QJsonParseError::NoError){

    }else {
        qDebug()<<error->errorString();
    }
    delete error;
}
JsonBaseModel::JsonBaseModel(QString json){
}
