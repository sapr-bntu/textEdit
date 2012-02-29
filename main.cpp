#include "textedit.h"
#include <QApplication>



int main( int argc, char ** argv )
{
    Q_INIT_RESOURCE(textedit);


    QApplication a( argc, argv );
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    TextEdit mw;
    mw.resize( 600, 500 );
    mw.show();
    return a.exec();

}
