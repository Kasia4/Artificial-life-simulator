#ifndef GENOME_H
#define GENOME_H

#include <QMap>
#include <QList>
#include <QSharedPointer>

#include <exception>

#include "Gene.h"
#include "AttributeConditioning.h"
#include "AttributeType.h"

class Genome
{
public:
    static Genome crossing(const Genome& a, const Genome& b);

    Genome();

    void addAttributesPair(AttributeType typeA, AttributeType typeB);
    void addAttributeToGene(AttributeType type, QSharedPointer<Gene> gene, GenePosition pos);
    qreal getAttributeValue(AttributeType type) const;
    int genesCount() const;
    QList<QSharedPointer<Gene>> getChromosome() const;
    bool isConditioned(AttributeType type) const;
    bool areCoupled(AttributeType typeA, AttributeType typeB) const;

private:
    QMap<AttributeType, AttributeConditioning> conditionings_;
    QList<QSharedPointer<Gene>> chromosome_;

};

#endif // GENOME_H
