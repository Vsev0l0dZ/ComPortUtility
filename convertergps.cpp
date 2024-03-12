#include "mainwindow.h"
#include "convertergps.h"
#include "parsergps.h"
#include <QDebug>
#include <QTime>

ConverterGPS::ConverterGPS(QObject *parent) : QObject(parent)
{

}

void ConverterGPS::convertCoord(QString m_lat, QString m_NS, QString m_lon, QString m_EW)
{
    latDecimal = m_lat.midRef(0, 2).toDouble() + m_lat.midRef(2).toDouble() / 60;
    if (m_NS == "S")
        latDecimal *= -1;

//    qDebug() << "latDecimal:" << latDecimal;

    lonDecimal = m_lon.midRef(0,3).toDouble() + m_lon.midRef(3).toDouble() / 60;
    if (m_EW == "W")
        lonDecimal *= -1;

//    qDebug() << "lonDecimal: " << lonDecimal << '\n';

    emit sendGPStoLabel(latDecimal, lonDecimal);

    timeMeasrm = (QTime::currentTime()).toString();

    emit sendTimeToLabel(timeMeasrm);

//    qDebug() << QTime::currentTime();

}
