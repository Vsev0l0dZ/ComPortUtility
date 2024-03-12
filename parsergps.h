#ifndef PARSERGPS_H
#define PARSERGPS_H

#include <QObject>
#include "convertergps.h"

class ParserGPS : public QObject
{
    Q_OBJECT

    QString m_lat;
    QString m_NS;
    QString m_lon;
    QString m_EW;

public:
    explicit ParserGPS(QObject *parent = nullptr);


signals:
    void sendGPStoConvrt(QString m_lat, QString m_NS, QString m_lon, QString m_EW);

public slots:

    void getDataGPS(QByteArray);
};


#endif // PARSERGPS_H
