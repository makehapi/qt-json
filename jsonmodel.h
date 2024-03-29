#ifndef JSONMODEL_H
#define JSONMODEL_H
#include <QString>
#include <QList>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
class JsonBaseModel:public QObject{
public:
    JsonBaseModel(const QByteArray &jsonContent);
    JsonBaseModel(QString json);
    JsonBaseModel();
protected:
    QJsonDocument doc;
    virtual void printModel() = 0;
};

class JsonArrayObjectArrayModel:public JsonBaseModel{
public:
    JsonArrayObjectArrayModel(const QByteArray &jsonContent);
    QString type;
    QObject value;
    void printModel();
};

class JsonArrayModel:public JsonBaseModel{
public:
    JsonArrayModel(const QJsonObject &jsonObj);
    JsonArrayModel(const QByteArray &jsonContent);
    JsonArrayModel(const JsonArrayModel &jsonArrayModel);
    void operator=(const JsonArrayModel &jsonArrayModel);
    QList<int> intArray;
    QList<double> doubleArray;
    QList<QString> stringArray;
    QVariantList complexArray;
    QList<JsonArrayObjectArrayModel> objectArray;
    void printModel();
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
