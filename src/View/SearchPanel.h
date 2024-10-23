#ifndef SEARCHPANEL_H
#define SEARCHPANEL_H

#include "Model/Building.h"
#include <QWidget>
#include <QLineEdit>

namespace View {

class SearchPanel : public QWidget
{
    Q_OBJECT
private:
    Model::Building& building;
    QLineEdit* searchText;
public:
    explicit SearchPanel(Model::Building&, QWidget *parent = nullptr);
public slots:
    void searchTextChanged();
signals:
    void search(const std::string&);
};

}
#endif // SEARCHPANEL_H
