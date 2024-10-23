#ifndef ADDSENSORDIALOG_H
#define ADDSENSORDIALOG_H

#include "Model/Building.h"
#include <QStackedLayout>
#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QComboBox>

namespace View::Dialog {

class AddSensorDialog : public QDialog
{
    Q_OBJECT
private:
    Model::Building& building;
    QStackedLayout* stackedLayout;
    QLineEdit* manufactor;
    QLineEdit* model;
    QDoubleSpinBox* precision;
    std::pair<QDoubleSpinBox*, QDoubleSpinBox*> range;
    QSpinBox* visualField;
    QComboBox* microphone;
    QDoubleSpinBox* resistance;
public:
    explicit AddSensorDialog(Model::Building&, QWidget *parent = nullptr);
public slots:
    void showType(int);
    void apply();
};

}
#endif // ADDSENSORDIALOG_H
