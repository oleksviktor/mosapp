#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QBoxLayout>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QWidget>

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow( QObject *parent = nullptr );
    ~MainWindow();

    void show();

    QLabel *getImageLabel();

signals:
    void loadImage();

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
