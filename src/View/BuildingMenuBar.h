#ifndef BUILDINGMENUBAR_H
#define BUILDINGMENUBAR_H

#include "Model/Building.h"
#include <QMenuBar>
#include <QString>
#include <string>

namespace View {

class BuildingMenuBar : public QMenuBar
{
    Q_OBJECT
private:
    Model::Building& building;
    std::string fileName;
public:
    explicit BuildingMenuBar(Model::Building&, QWidget *parent = nullptr);
public slots:
    void openFile(QString dropFileName = "");
    void saveFile();
    void saveAsFile();
    void closeFile();
    void showAddDialog();
signals:
    void fileChanged();
};

}
#endif // BUILDINGMENUBAR_H
