#include "mainwindow.h"

MainWindow::MainWindow( QObject *parent ) : QObject( parent )
{
    centralWidget = new QWidget();

    mainLayout = new QVBoxLayout();

    headerLabel = new QLabel( "Регистрация в системе" );

    locationId = new QLineEdit( "" );
    date = new QLineEdit( "" );
    fullName = new QLineEdit( "" );
    email = new QLineEdit( "" );
    bdate = new QLineEdit( "" );
    phone = new QLineEdit( "" );
    band = new QLineEdit( "" );
    nickName = new QLineEdit( "" );
    locationId->setPlaceholderText( "ID площадки" );
    date->setPlaceholderText( "Дата и время 2021-06-20T18:00:00.000Z" );
    fullName->setPlaceholderText( "Полное имя (русс)" );
    email->setPlaceholderText( "Email mail@mail.ru" );
    bdate->setPlaceholderText( "День рождения 13.01.2000" );
    phone->setPlaceholderText( "Телефон +79161112233" );
    band->setPlaceholderText( "Название группы Необходимо" );
    nickName->setPlaceholderText( "Ник Необходимо" );

    captchaValue = new QLineEdit( "" );

    loadImageButton = new QPushButton( "Обновить капчу" );
    imageLabel = new QLabel( "" );
    image = new QImage( ":/empty" );
    imageLabel->setPixmap( QPixmap::fromImage( image->scaled( 240, 180 ) ) );

    QObject::connect( loadImageButton, &QPushButton::clicked, this, &MainWindow::loadImage );

    makeRequestButton = new QPushButton( "Оставить заявку" );

    QObject::connect( makeRequestButton, &QPushButton::clicked, this, &MainWindow::sendRequest );

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
    captchaValue->setFocus();
    makeRequestButton->setDefault( true );
}

MainWindow::~MainWindow()
{
}

void MainWindow::show()
{
    centralWidget->show();
}

QByteArray MainWindow::getData()
{
    QVariantMap vData;
    vData.insert( "location_id", locationId->text() );
    vData.insert( "date", date->text() );
    vData.insert( "full_name", fullName->text() );
    vData.insert( "email", email->text() );
    vData.insert( "bdate", bdate->text() );
    vData.insert( "phone", phone->text() );
    vData.insert( "band", band->text() );
    vData.insert( "nick_name", nickName->text() );
    vData.insert( "captcha_value", captchaValue->text() );
    vData.insert( "captcha_code", NETWORK->getImage().code );
    return QJsonDocument::fromVariant( vData ).toJson();
}

QLabel *MainWindow::getImageLabel()
{
    return imageLabel;
}

void MainWindow::saveSettings()
{
    QSettings settings;
    settings.beginGroup( "Main" );
    settings.setValue( "location_id", locationId->text() );
    settings.setValue( "full_name", fullName->text() );
    settings.setValue( "email", email->text() );
    settings.setValue( "bdate", bdate->text() );
    settings.setValue( "phone", phone->text() );
    settings.setValue( "band", band->text() );
    settings.setValue( "nick_name", nickName->text() );
    settings.endGroup();
    qDebug() << "Settings saved";
}

void MainWindow::loadSettings()
{
    QSettings settings;
    settings.beginGroup( "Main" );
    QDate currentDate = QDate::currentDate();
    QDateTime time = QDateTime::currentDateTimeUtc();
    time.setTime( QTime( 20, 0, 0, 0 ) );
    time.setDate( currentDate.addDays( 6 ) );
    locationId->setText( settings.value( "location_id" ).toString() );
    date->setText( time.toString( Qt::ISODateWithMs ) );
    fullName->setText( settings.value( "full_name" ).toString() );
    email->setText( settings.value( "email" ).toString() );
    bdate->setText( settings.value( "bdate" ).toString() );
    phone->setText( settings.value( "phone" ).toString() );
    band->setText( settings.value( "band" ).toString() );
    nickName->setText( settings.value( "nick_name" ).toString() );
    settings.endGroup();
}

void MainWindow::lockInterface()
{
    loadImageButton->setDisabled( true );
    makeRequestButton->setDisabled( true );
}
