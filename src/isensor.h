#ifndef SENSOR_H
#define SENSOR_H

class ISensor
{
public:
    virtual ~ISensor(){}

signals:
    virtual void gotData() = 0;
};

#endif // SENSOR_H
