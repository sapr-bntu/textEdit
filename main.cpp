#include "textedit.h"
#include <QApplication>



int main( int argc, char ** argv )
{
    Q_INIT_RESOURCE(textedit);


    QApplication a( argc, argv );
    TextEdit mw;
    mw.resize( 600, 500 );
    mw.show();
    return a.exec();
}
