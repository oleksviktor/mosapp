#include "network.h"

Network *Network::_network = nullptr;

Network *Network::getInstance()
{
    if ( _network == nullptr )
    {
        _network = new Network();
    }
    return _network;
}

void Network::loadImage()
{
    qDebug() << "want to load image";
    QNetworkRequest request( url );
    auto reply = manager->get( request );
    QObject::connect( reply, &QNetworkReply::readyRead, this, &Network::replyFinished );
}

Network::Network( QObject *parent ) : QObject( parent )
{
    manager = new QNetworkAccessManager( this );
    //    QObject::connect( manager, &QNetworkAccessManager::finished, this, &Network::replyFinished );
}

const NetworkImage &Network::getImage() const
{
    return image;
}

const QString &Network::getUrl() const
{
    return url;
}

void Network::setUrl( const QString &newUrl )
{
    url = newUrl;
}

void Network::replyFinished()
{
    QNetworkReply *reply = static_cast< QNetworkReply * >( sender() );
    image.code = reply->rawHeader( QString( "Captcha-Code" ).toUtf8() );

    image.pixmap.loadFromData( reply->readAll() );
    //    qDebug() << "Response:" << reply->readAll();
    reply->deleteLater();
    emit success();
}
