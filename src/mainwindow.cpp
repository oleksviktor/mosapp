#include "mainwindow.h"

MainWindow::MainWindow( QObject *parent ) : QObject( parent )
{
    centralWidget = new QWidget();
    mainLayout = new QVBoxLayout();

    headerLabel = new QLabel( "Image loader" );
    locationId = new QLineEdit( "Введите ID локации 43" );
    date = new QLineEdit( "Введите дату 2021-06-21T20:00:00.000Z" );
    fullName = new QLineEdit( "Введите полное имя" );
    email = new QLineEdit( "Введите EMail" );
    bdate = new QLineEdit( "Введите день рождения" );
    phone = new QLineEdit( "Введите телефон" );
    band = new QLineEdit( "Введите имя группы" );
    nickName = new QLineEdit( "Введите ник" );
    captchaValue = new QLineEdit( "Введите проверочный код" );

    loadImageButton = new QPushButton( "Load" );
    imageLabel = new QLabel( "Here will be image" );
    image = new QImage( "./empty.jpg" );
    imageLabel->setPixmap( QPixmap::fromImage( image->scaled( 240, 180 ) ) );

    QObject::connect( loadImageButton, &QPushButton::clicked, this, &MainWindow::loadImage );

    makeRequestButton = new QPushButton( "Оставить заявку" );

    mainLayout->setMargin( 0 );
    centralWidget->setMinimumSize( 320, 360 );
    centralWidget->setLayout( mainLayout );

    mainLayout->addWidget( headerLabel );
    mainLayout->addWidget( locationId );
    mainLayout->addWidget( date );
    mainLayout->addWidget( fullName );
    mainLayout->addWidget( email );
    mainLayout->addWidget( bdate );
    mainLayout->addWidget( phone );
    mainLayout->addWidget( band );
    mainLayout->addWidget( nickName );
    mainLayout->addWidget( imageLabel );
    mainLayout->addWidget( loadImageButton );
    mainLayout->addWidget( captchaValue );
    mainLayout->addWidget( makeRequestButton );
}

MainWindow::~MainWindow()
{
}

void MainWindow::show()
{
    centralWidget->show();
}

QLabel *MainWindow::getImageLabel()
{
    return imageLabel;
}
