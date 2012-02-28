#include "textedit.h"
 #include <QApplication>

 int main( int argc, char ** argv )
 {
     Q_INIT_RESOURCE(textedit);
     QApplication a( argc, argv );
     TextEdit MyWindows;
     MyWindows.resize( 700, 500 );
     MyWindows.show();
     return a.exec();
 }
