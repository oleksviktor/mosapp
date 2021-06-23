#ifndef NETWORK_H
#define NETWORK_H

#include <QImage>
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

    void setUrl( const QString &newUrl );

    const QString &getUrl() const;

    const NetworkImage &getImage() const;

signals:
    void success();

private:
    static Network *_network;
    explicit Network( QObject *parent = nullptr );

    Network( const Network & ) = delete;
    void operator=( const Network & ) = delete;

    QNetworkAccessManager *manager;

    QString url;

    NetworkImage image;

private slots:
    void replyFinished();
};

#endif   // NETWORK_H
