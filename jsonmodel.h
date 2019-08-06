#ifndef JSONMODEL_H
#define JSONMODEL_H
#include <QString>
#include <QList>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
class JsonBaseModel:public QObject{
public:
    JsonBaseModel(const QByteArray &jsonContent);
    JsonBaseModel(QString json);
protected:
    QJsonDocument doc;
    virtual void printModel() = 0;
};

class JsonArrayObjectArrayModel:public JsonBaseModel{
public:
    JsonArrayObjectArrayModel(const QByteArray &jsonContent);
    QString type;
    QObject value;
};

class JsonArrayModel:public JsonBaseModel{
public:
    JsonArrayModel(const QJsonObject &jsonObj);
    QList<int> intArray;
    QList<double> doubleArray;
    QList<QString> stringArray;
    QVariantList complexArray;
    QList<JsonArrayObjectArrayModel> objectArray;
};

class JsonModel:public JsonBaseModel
{
public:
    JsonModel(const QByteArray &jsonContent);
    int type;
    QString image1;
    QString image2;
    QString color1;
    QString color2;
    int intValue;
    int intString;
    double doubleValue;
    double doubleString;
    float floatValue;
    float floatString;
    QString string;
    JsonArrayModel array;
    void printModel();
};


#endif // JSONMODEL_H
