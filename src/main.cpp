#include <QApplication>

#include "logic.h"

int main( int argc, char *argv[] )
{
    QApplication a( argc, argv );
    a.setApplicationName( "Street musician" );
    QCoreApplication::setOrganizationName( "Zzz land" );
    QCoreApplication::setOrganizationDomain( "zzz-land.com" );
    QCoreApplication::setApplicationName( "StreetMusician" );
    Logic logic;
    return a.exec();
}
