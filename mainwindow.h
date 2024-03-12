#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include "terminalwindow.h"
#include "parsergps.h"
#include "convertergps.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    TerminalWindow* terminalCOM1 = nullptr;
    TerminalWindow* terminalCOM2 = nullptr;

    ParserGPS* currGPSData = nullptr;
    ConverterGPS* decimalGPS = nullptr;

private:
    Ui::MainWindow *ui;

private slots:
        void on_GPSbuttonSend();
        void on_SVMbuttonSend();

        void on_Coordinates(double latDecimal, double lonDecimal);
        void on_TimeMeasrm(QString timeMeasrm);

public slots:


signals:
        void sendGPSdata(QString str);
        void sendSVMdata(QString str);

};
#endif // MAINWINDOW_H
