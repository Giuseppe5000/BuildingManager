#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Model/Building.h"
#include <QMainWindow>

namespace View {

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(Model::Building&, QWidget *parent = nullptr);
};

}
#endif // MAINWINDOW_H
