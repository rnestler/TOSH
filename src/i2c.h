#ifndef I2C_H
#define I2C_H

#include <QObject>

class I2c : public QObject
{
    Q_OBJECT
public:
    explicit I2c(QObject *parent = 0);
    void i2cWrite(QString devName, unsigned char address, QByteArray data);
    QByteArray i2cRead(QString devName, unsigned char address, int count);

signals:
    void i2cError();

public slots:

private:

};

#endif // I2C_H
