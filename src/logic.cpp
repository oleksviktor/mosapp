#include "logic.h"

Logic::Logic( QObject *parent ) : QObject( parent )
{
    w = new MainWindow( this );

    QObject::connect( w, &MainWindow::loadImage, this, &Logic::onLoadImage );
    QObject::connect( NETWORK, &Network::loadImageSuccess, this, &Logic::onLoadImageSuccess );

    QObject::connect( w, &MainWindow::sendRequest, this, &Logic::onRequest );
    QObject::connect( NETWORK, &Network::requestSuccess, this, &Logic::onRequestSuccess );
    QObject::connect( NETWORK, &Network::requestFailed, this, &Logic::onRequestFailed );

    QObject::connect( qApp, &QApplication::aboutToQuit, this, &Logic::onPreparetoQuit );
    w->show();
    w->loadSettings();
    NETWORK->loadImage();
}

void Logic::onLoadImage()
{
    NETWORK->loadImage();
}

void Logic::onLoadImageSuccess()
{
    w->getImageLabel()->setPixmap( NETWORK->getImage().pixmap );
    qDebug() << "Image loaded";
}

void Logic::onRequest()
{
    qDebug() << w->getData();
    NETWORK->takePlace( w->getData() );
}

void Logic::onRequestSuccess()
{
    w->lockInterface();
    qDebug() << "Check Email";
    QMessageBox *msg = new QMessageBox();
    msg->setText( "Заявка успешно отправлена.\nПроверьте электронную почту." );
    msg->show();
}

void Logic::onRequestFailed()
{
    qDebug() << "Some error";
    QMessageBox *msg = new QMessageBox();
    msg->setText( "Какая-то ошибка при регистрации" );
    msg->show();
}

void Logic::onPreparetoQuit()
{
    w->saveSettings();
}
