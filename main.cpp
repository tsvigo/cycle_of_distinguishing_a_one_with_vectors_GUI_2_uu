#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//###########################################################################
//    protected slots:
//        void closeApp() {
//            // Выплнить нужный код здесь.
//            qDebug() << "Application closed.";
//        }

//    QObject::connect(&a, &QApplication::aboutToQuit),
//        &Dialog::closeApp, &a);
//###########################################################################
    Dialog w;
    w.show();
  //  Dialog dialog;
  //  dialog.show();
    return a.exec();
}
