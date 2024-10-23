#ifndef JSONCONVERTER_H
#define JSONCONVERTER_H

#include "Model/Building.h"
#include <QJsonDocument>

namespace Model::Converter {

class JsonConverter
{
public:
    static QJsonDocument convert(const Building&);
    static void parse(Building&,const QJsonDocument&);
};

}
#endif // JSONCONVERTER_H
