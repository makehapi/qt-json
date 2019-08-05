#ifndef JSONMODEL_H
#define JSONMODEL_H
#include <QString>
#include <QList>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
class JsonBaseModel{
public:
    JsonBaseModel(const QByteArray &jsonContent);
    JsonBaseModel(QString json);
protected:
    QJsonDocument doc;
};

class JsonArrayObjectArrayModel:public JsonBaseModel{
public:
    JsonArrayObjectArrayModel();
    QString type;
    QObject value;
};

class JsonArrayModel:public JsonBaseModel{
public:
    JsonArrayModel();
    QList<int> intArray;
    QList<double> doubleArray;
    QList<QString> stringArray;
    QVariantList complexArray;
    QList<JsonArrayObjectArrayModel> objectArray;
};

class JsonModel:public JsonBaseModel
{
public:
    JsonModel();
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
    QVariantList array;
};


#endif // JSONMODEL_H
