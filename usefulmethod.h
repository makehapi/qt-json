#ifndef USEFULMETHOD_H
#define USEFULMETHOD_H

#include <QObject>

class UsefulMethod : public QObject
{
    Q_OBJECT
public:
    explicit UsefulMethod(QObject *parent = nullptr);
    static QString getStringFromFile(QString filePath);
    static QByteArray getContentFromFile(QString filePath);
    static QString getApplicationPath();

signals:

public slots:
};

#endif // USEFULMETHOD_H
