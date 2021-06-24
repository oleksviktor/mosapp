#ifndef LOGIC_H
#define LOGIC_H

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QObject>

#include "mainwindow.h"
#include "network.h"

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic( QObject *parent = nullptr );

signals:
private:
    MainWindow *w;

private slots:
    void onLoadImage();
    void onLoadImageSuccess();

    void onRequest();
    void onRequestSuccess();
    void onRequestFailed();

    void onPreparetoQuit();
};

#endif   // LOGIC_H
