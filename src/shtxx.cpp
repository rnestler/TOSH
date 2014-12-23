#include "shtxx.h"
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <cstdio>
#include <QObject>
#include <QString>
#include <QColor>

#include <QCoreApplication>
#include <QSettings>

Shtxx::Shtxx(QObject *parent) :
        QObject(parent)
{
}

void Shtxx::tohVddSet(bool onOff)
{
    int fd;
    fd = open("/sys/devices/platform/reg-userspace-consumer.0/state", O_WRONLY);
    if (!(fd < 0))
    {
        if(write(fd, onOff? "1": "0", 1) != 1) {
            fprintf(stderr, "Vdd set failed\n");
        }
        else {
            fprintf(stderr, "Vdd set OK\n");
        }
        close(fd);
    }
    else {
        fprintf(stderr, "Vdd failed to open.\n");
    }
    emit tohVddStatusChanged();
}

void Shtxx::update()
{
    char writeData[] = {0x7C, 0xA2};
    _I2c.i2cWrite("/dev/i2c-1", 0x70, QByteArray(writeData,2) );
    QByteArray data = _I2c.i2cRead("/dev/i2c-1", 0x70, 6);
    _Temperature = QString::number(-45.0 + 175.0 * ((data[0]<<8)+data[1])/65536.0);
    _Humidity = QString::number(100.0 * ((data[3]<<8)+data[4])/65536.0);

    emit gotData();
}

