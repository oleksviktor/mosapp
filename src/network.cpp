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
    QNetworkRequest request( captchaUrl );
    auto reply = manager->get( request );
    reply->setObjectName( "image" );
    QObject::connect( reply, &QNetworkReply::readyRead, this, &Network::replyFinished );
}

void Network::takePlace( const QByteArray &binaryData )
{
    qDebug() << "try to register";
    QNetworkRequest request( url );

    auto reply = manager->put( request, binaryData );
    reply->setObjectName( "request" );
    QObject::connect( reply, &QNetworkReply::readyRead, this, &Network::replyFinished );
}

Network::Network( QObject *parent ) :
    QObject( parent ), url( "https://alt.mos.ru/altmosprx/api/1/musicians" ),
    captchaUrl( "https://alt.mos.ru/api/users/v1/frontend/json/captcha" )
{
    manager = new QNetworkAccessManager( this );
    //    QObject::connect( manager, &QNetworkAccessManager::finished, this, &Network::replyFinished );
}

const NetworkImage &Network::getImage() const
{
    return image;
}

void Network::replyFinished()
{
    QNetworkReply *reply = static_cast< QNetworkReply * >( sender() );
    if ( reply->objectName() == "image" )
    {
        image.code = reply->rawHeader( QString( "Captcha-Code" ).toUtf8() );
        image.pixmap.loadFromData( reply->readAll() );
        emit loadImageSuccess();
    }
    else
    {
        QByteArray ba = reply->readAll();
        qDebug() << "Response:" << (QString)ba;
        QJsonDocument doc = QJsonDocument::fromJson( ba );
        QJsonObject obj = doc.object();
        QString id = "";
        id = obj[ "id" ].toString();
        if ( !id.isEmpty() )
        {
            emit requestSuccess();
        }
        else
        {
            emit requestFailed();
        }
    }
    reply->deleteLater();
}
