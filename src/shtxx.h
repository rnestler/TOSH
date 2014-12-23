#ifndef I2CIF_H
#define I2CIF_H

#include "i2c.h"

class Shtxx : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sensorTemperature READ getTemperature NOTIFY gotData)
    Q_PROPERTY(QString sensorHumidity READ getHumidity NOTIFY gotData)
public:
    explicit Shtxx(QObject *parent = 0);

    QString getTemperature()
    { return _Temperature; }

    QString getHumidity()
    { return _Humidity; }


    Q_INVOKABLE void update();
    Q_INVOKABLE void tohVddSet(bool onOff);

signals:
    void tohVddStatusChanged();
    void gotData();
    void i2cError();

public slots:

private:
    I2c _I2c;
    void i2cWrite(QString devName, unsigned char address, QString data);
    QByteArray i2cRead(QString devName, unsigned char address, int count);

    QString _Temperature;
    QString _Humidity;
};

#endif // I2CIF_H
