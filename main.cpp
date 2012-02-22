#include "textedit.h"
 #include <QApplication>

 int main( int argc, char ** argv )
 {
     Q_INIT_RESOURCE(textedit);

     QApplication a( argc, argv );
     TextEdit mw1;
     mw1.resize( 700, 500 );
     mw1.show();

     return a.exec();
 }
