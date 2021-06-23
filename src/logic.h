#ifndef LOGIC_H
#define LOGIC_H

#include <QDebug>
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
    void onSuccess();
};

#endif   // LOGIC_H
