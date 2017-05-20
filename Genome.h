#ifndef GENOME_H
#define GENOME_H

#include <QMap>
#include <QList>
#include "Gene.h"
#include "AttributeConditioning.h"
#include "AttributeType.h"

class Genome
{
public:
    Genome();

private:
    QMap<AttributeType, AttributeConditioning> fenome_;
    QList<Gene> chromosome;
};

#endif // GENOME_H
