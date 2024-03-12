#include "parsergps.h"
#include "mainwindow.h"
#include <QDebug>
#include <iterator>


ParserGPS::ParserGPS(QObject *parent) : QObject(parent)
{

}

void ParserGPS::getDataGPS(QByteArray data){
    QString dataString = QString(data);
    //    qDebug() << dataString;
    QStringList packList = dataString.split(QLatin1Char('\n'));
    //    qDebug() << packList;
    QStringList gllList = packList.filter("$GNGLL");// получил list строк $GNGLL
    //    qDebug() << gllList;

    QString lastString = "\0";
    if(!gllList.empty()){
        lastString = gllList.last();
//        qDebug() << "lastString =" << lastString;

        QStringList gllStringList = lastString.split(QLatin1Char(','));

        QStringList::Iterator it = gllStringList.begin();

        ++it;
        m_lat = *it;
        ++it;
        m_NS = *it;
        ++it;
        m_lon = *it;
        ++it;
        m_EW = *it;

//        qDebug() << "Latitude =" << m_lat << m_NS
//                 << ", Longitude =" << m_lon << m_EW << '\n';

        emit sendGPStoConvrt(m_lat, m_NS, m_lon, m_EW);
    }
}

