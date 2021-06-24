#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QBoxLayout>
#include <QCborStreamWriter>
#include <QDate>
#include <QDateTime>
#include <QImage>
#include <QJsonDocument>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QSettings>
#include <QWidget>

#include "network.h"

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow( QObject *parent = nullptr );
    ~MainWindow();

    void show();

    QByteArray getData();

    QLabel *getImageLabel();

    void saveSettings();
    void loadSettings();
    void lockInterface();

signals:
    void loadImage();
    void sendRequest();

private:
    QImage *image;
    QLabel *imageLabel;
    QLabel *headerLabel;
    QPushButton *loadImageButton;
    QVBoxLayout *mainLayout;
    QWidget *centralWidget;

    QLineEdit *locationId;
    QLineEdit *date;
    QLineEdit *fullName;
    QLineEdit *email;
    QLineEdit *bdate;
    QLineEdit *phone;
    QLineEdit *band;
    QLineEdit *nickName;
    QLineEdit *captchaValue;

    QPushButton *makeRequestButton;
};
#endif   // MAINWINDOW_H
