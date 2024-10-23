#include "BuildingMenuBar.h"
#include "Model/Converter/JsonConverter.h"
#include "Dialogs/AddSensorDialog.h"
#include <QMenu>
#include <QFile>
#include <QJsonDocument>
#include <QFileDialog>
#include <QMessageBox>

namespace View {

BuildingMenuBar::BuildingMenuBar(Model::Building& b, QWidget *parent)
    : QMenuBar(parent), building(b)
{
    QMenu *file = new QMenu("File", this);
    addMenu(file);
    QAction* openFile = new QAction(QIcon(":/assets/icons/open.svg"), "Open", this);
    openFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    QAction* saveFile = new QAction(QIcon(":/assets/icons/save.svg"), "Save", this);
    saveFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    QAction* saveAsFile = new QAction(QIcon(":/assets/icons/saveAs.svg"), "Save As", this);
    saveAsFile->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT |Qt::Key_S));
    QAction* closeFile = new QAction(QIcon(":/assets/icons/close.svg"), "Close file", this);
    closeFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q));
    file->addAction(openFile);
    file->addAction(saveFile);
    file->addAction(saveAsFile);
    file->addAction(closeFile);

    QMenu *sensor = new QMenu("Sensor", this);
    addMenu(sensor);
    QAction* addSensor = new QAction(QIcon(":/assets/icons/addSensor.svg"), "Add a sensor", this);
    addSensor->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Plus));
    sensor->addAction(addSensor);

    connect(openFile, &QAction::triggered, this, [this]{ this->openFile(); });
    connect(saveFile, &QAction::triggered, this, &BuildingMenuBar::saveFile);
    connect(saveAsFile, &QAction::triggered, this, &BuildingMenuBar::saveAsFile);
    connect(closeFile, &QAction::triggered, this, &BuildingMenuBar::closeFile);

    connect(addSensor, &QAction::triggered, this, &BuildingMenuBar::showAddDialog);
}

void BuildingMenuBar::openFile(QString dropFileName) {
    if (!fileName.empty()) {
        QMessageBox msgBox;
        msgBox.setText("Save the document before closing?");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
            saveFile();
            building.clear();
            break;
        case QMessageBox::Discard:
            building.clear();
            break;
        case QMessageBox::Cancel:
            return;
        default:
            break;
        }
    }

    if (building.getSize() > 0) {

        QMessageBox msgBox;
        msgBox.setText("Current document isn't stored.");
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
            saveAsFile();
            building.clear();
            break;
        case QMessageBox::Discard:
            building.clear();
            break;
        case QMessageBox::Cancel:
            return;
        default:
            break;
        }

    }

    QString name;
    if (dropFileName.isEmpty())
        name = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::homePath(), tr("Json (*.json)"));
    else
        name = dropFileName;

    QFile file(name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    Model::Converter::JsonConverter::parse(building, doc);

    fileName = name.toStdString();
    emit BuildingMenuBar::fileChanged();
}

void BuildingMenuBar::saveFile() {
    if (!fileName.empty()) {
        QJsonDocument doc(Model::Converter::JsonConverter::convert(building));
        QFile jsonFile(QString::fromStdString(fileName));
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(doc.toJson());
    }
    else {
        saveAsFile();
    }
}

void BuildingMenuBar::saveAsFile() {
    QJsonDocument doc(Model::Converter::JsonConverter::convert(building));

    QFileDialog fileDialog;
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setDefaultSuffix("json");
    fileDialog.setNameFilter(tr("Json (*.json)"));
    fileDialog.setDirectory(QDir::homePath());

    QStringList fileName;
    if (fileDialog.exec())
        fileName = fileDialog.selectedFiles();

    if (!fileName.empty()) {
        QFile jsonFile(fileName[0]);
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(doc.toJson());
    }
}

void BuildingMenuBar::closeFile() {
    if (!fileName.empty()) {
        building.clear();
        fileName.clear();
        emit BuildingMenuBar::fileChanged();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("No open file!");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.exec();
    }
}

void BuildingMenuBar::showAddDialog() {
    new Dialog::AddSensorDialog(building, this);
}

}
