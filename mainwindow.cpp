#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "terminalwindow.h"
#include "settingsdialog.h"
#include "parsergps.h"

#include <QLabel>
#include <QMessageBox>
#include <QTime>
#include <QFile>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    terminalCOM1 = new TerminalWindow(nullptr, "com1");// 2й параметр -  имя файла
    ui->TerminalCOM1Layout->addWidget(terminalCOM1);
    terminalCOM1->show();

    terminalCOM2 = new TerminalWindow(nullptr, "com2");
    ui->TerminalCOM2Layout->addWidget(terminalCOM2);
    terminalCOM2->show();

    currGPSData = new ParserGPS(nullptr);
    decimalGPS = new ConverterGPS(nullptr);

    connect(ui->COM1button, SIGNAL(clicked()), this, SLOT(on_GPSbuttonSend()));
    connect(ui->COM2button, SIGNAL(clicked()), this, SLOT(on_SVMbuttonSend()));

    connect(terminalCOM1, &TerminalWindow::receivedData, currGPSData, &ParserGPS::getDataGPS);

    connect(currGPSData, &ParserGPS::sendGPStoConvrt, decimalGPS, &ConverterGPS::convertCoord);

    connect(decimalGPS, &ConverterGPS::sendGPStoLabel, this, &MainWindow::on_Coordinates);
    connect(decimalGPS, &ConverterGPS::sendTimeToLabel, this, &MainWindow::on_TimeMeasrm);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_GPSbuttonSend()
{
//      emit sendGPSdata(ui->GPSline->text());
}


void MainWindow::on_SVMbuttonSend()
{
    terminalCOM2->writeData(QByteArray(ui->COM1line->text().toUtf8()));
}

void MainWindow::on_Coordinates(double latDecimal, double lonDecimal)
{
    ui->coordinates->setText(QString::number(latDecimal) + ", " + QString::number(lonDecimal));
}

void MainWindow::on_TimeMeasrm(QString timeMeasrm)
{
    ui->timeInterval->setText(timeMeasrm);
}




