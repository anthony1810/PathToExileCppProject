
#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include "Window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window window;
    //QDir::setCurrent(QCoreApplication::applicationDirPath());

    window.move(200, 200);
    window.setWindowTitle("Path Of Exile Skill Tree");
    window.show();

    return a.exec();
}

