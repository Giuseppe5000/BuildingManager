#include "View/MainWindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":assets/icon.svg"));

    QFile stylesheet(":/assets/stylesheet.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    Model::Building building;
    View::MainWindow w(building);
    w.setWindowTitle("Building Manager");
    w.resize(1024,512);
    w.show();
    return app.exec();
}
