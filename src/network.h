#ifndef NETWORK_H
#define NETWORK_H

#include <QImage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QPixmap>

#define NETWORK Network::getInstance()

struct NetworkImage
{
    QPixmap pixmap;
    QString code;
};

class Network : public QObject
{
    Q_OBJECT
public:
    static Network *getInstance();

    void loadImage();

    void takePlace( const QByteArray &binaryData );

    const NetworkImage &getImage() const;

signals:
    void loadImageSuccess();
    void requestSuccess();
    void requestFailed();

private:
    static Network *_network;
    explicit Network( QObject *parent = nullptr );

    Network( const Network & ) = delete;
    void operator=( const Network & ) = delete;

    QNetworkAccessManager *manager;

    QString url;
    QString captchaUrl;

    NetworkImage image;

private slots:
    void replyFinished();
};

#endif   // NETWORK_H
