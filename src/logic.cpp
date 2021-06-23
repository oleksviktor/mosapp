#include "logic.h"

Logic::Logic( QObject *parent ) : QObject( parent )
{
    w = new MainWindow( this );

    QObject::connect( w, &MainWindow::loadImage, this, &Logic::onLoadImage );
    QObject::connect( NETWORK, &Network::success, this, &Logic::onSuccess );

    w->show();
    NETWORK->setUrl( "https://alt.mos.ru/api/users/v1/frontend/json/captcha" );
}

void Logic::onLoadImage()
{
    NETWORK->loadImage();
}

void Logic::onSuccess()
{
    w->getImageLabel()->setPixmap( NETWORK->getImage().pixmap );
    qDebug() << NETWORK->getImage().code;
}
