#ifndef CONVERTERGPS_H
#define CONVERTERGPS_H

#include <QObject>

class ConverterGPS : public QObject
{
    Q_OBJECT

    double latDecimal = 0;
    double lonDecimal = 0;

    QString timeMeasrm;

public:
    explicit ConverterGPS(QObject *parent = nullptr);

public slots:

    void convertCoord(QString m_lat, QString m_NS, QString m_lon, QString m_EW);

signals:

    void sendGPStoLabel(double latDecimal, double lonDecimal);
    void sendTimeToLabel(QString timeMeasrm);

};

#endif // CONVERTERGPS_H
