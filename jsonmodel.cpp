#include "jsonmodel.h"
#include <QDebug>

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
JsonBaseModel::JsonBaseModel(){
}
JsonArrayObjectArrayModel::JsonArrayObjectArrayModel(const QByteArray &jsonContent):JsonBaseModel (jsonContent){
}
JsonArrayModel::JsonArrayModel(const QByteArray &jsonContent):JsonBaseModel (jsonContent){

}
JsonArrayModel::JsonArrayModel(const QJsonObject &jsonObj):JsonBaseModel (){
   intArray = jsonObj.value("int").toArray();
   doubleArray = jsonObj.value("double").toArray();
   stringArray = jsonObj.value("string").toArray();
   complexArray = jsonObj.value("complexArray").toArray();
   objectArray = jsonObj.value("object").toArray();
}
JsonArrayModel::JsonArrayModel(const JsonArrayModel &jsonArrayModel){
   intArray = jsonArrayModel.intArray;
   doubleArray = jsonArrayModel.doubleArray;
   stringArray = jsonArrayModel.stringArray;
   complexArray = jsonArrayModel.complexArray;
   objectArray = jsonArrayModel.objectArray;
}
void JsonArrayModel::operator=(const JsonArrayModel &jsonArrayModel){
   intArray = jsonArrayModel.intArray;
   doubleArray = jsonArrayModel.doubleArray;
   stringArray = jsonArrayModel.stringArray;
   complexArray = jsonArrayModel.complexArray;
   objectArray = jsonArrayModel.objectArray;
}
void JsonArrayModel::printModel(){

}
JsonModel::JsonModel(const QByteArray &jsonContent):JsonBaseModel (jsonContent){
   QJsonObject jsonObj = this->doc.object();
   type = jsonObj.value("type").toInt();
   image1 = jsonObj.value("image1").toString();
   image2 = jsonObj["image2"].toString();
   color1 = jsonObj["color1"].toString();
   color2 = jsonObj["color3"].toString();

   intValue = jsonObj["int"].toInt();
   intString = jsonObj["intString"].toInt();
   doubleValue = jsonObj["double"].toDouble();
   doubleString = jsonObj["doubleString"].toDouble();
   string = jsonObj["string"].toString();

   array = JsonArrayModel(jsonObj.value("array").toObject());
}

void JsonModel::printModel(){
   qDebug()<<type<<image1<<image2<<color1<<color2<<intValue<<"\n";
}

