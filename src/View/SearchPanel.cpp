#include "SearchPanel.h"
#include <QHBoxLayout>

namespace View {

SearchPanel::SearchPanel(Model::Building& b, QWidget *parent)
    : QWidget(parent), building(b)
{
    QHBoxLayout* layout = new QHBoxLayout(this);

    searchText = new QLineEdit;
    searchText->setPlaceholderText("Search...");
    layout->addWidget(searchText);

    connect(searchText, &QLineEdit::textChanged, this, &SearchPanel::searchTextChanged);
}

void SearchPanel::searchTextChanged() {
    std::string query = searchText->text().toStdString();
    std::transform(query.begin(), query.end(), query.begin(), ::tolower);
    emit search(query);
}

}
