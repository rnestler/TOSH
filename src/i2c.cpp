#include "i2c.h"
#include <linux/i2c-dev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <cstdio>

I2c::I2c(QObject *parent) :
    QObject(parent)
{
}

void I2c::i2cWrite(QString devName, unsigned char address, QByteArray data)
{
    int file;
    QByteArray tmpBa = devName.toUtf8();
    const char* devNameChar = tmpBa.constData();
    fprintf(stderr, "writing to address 0x%02x: ", address);
    for (int i=0; i<data.length(); i++)
    {
        fprintf(stderr, "%02x ", (u_int8_t)data.at(i));
    }
    fprintf(stderr, "\n");
    if ((file = open (devNameChar, O_RDWR)) < 0)
    {
        fprintf(stderr,"open error\n");
        emit i2cError();
        return;
    }
    if (ioctl(file, I2C_SLAVE, address) < 0)
    {
        close(file);
        fprintf(stderr,"ioctl error\n");
        emit i2cError();
        return;
    }
    /* write the data */
    if (write( file, data.begin(), data.length() ) != data.length())
    {
        close(file);
        fprintf(stderr,"write error\n");
        emit i2cError();
        return;
    }
    close(file);
    fprintf(stderr,"write ok\n");
}

QByteArray I2c::i2cRead(QString devName, unsigned char address, int count)
{
    int file;
    char buf[200];
    QByteArray readResult = QByteArray(count, '0');
    QByteArray tmpBa = devName.toUtf8();
    const char* devNameChar = tmpBa.constData();
    fprintf(stderr, "reading from address %02x count %d\n", address, count);
    if ((file = open (devNameChar, O_RDWR)) < 0)
    {
        fprintf(stderr,"open error\n");
        emit i2cError();
        return "";
    }
    if (ioctl(file, I2C_SLAVE, address) < 0)
    {
        close(file);
        fprintf(stderr,"ioctl error\n");
        emit i2cError();
        return "";
    }
    /* Read data */
    if (read( file, buf, count ) != count)
    {
        close(file);
        fprintf(stderr,"read error\n");
        emit i2cError();
        return "";
    }
    close(file);
    /* copy buf to readResult */
    int i;
    fprintf(stderr, "read ");
    for (i=0; i<count ; i++)
    {
        readResult[i] = buf[i];
        fprintf(stderr, "%02x ", buf[i]);
    }
    fprintf(stderr, "\n");
    return readResult;
}

