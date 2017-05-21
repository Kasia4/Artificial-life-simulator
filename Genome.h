#ifndef GENOME_H
#define GENOME_H

#include <QMap>
#include <QSet>
#include <QSharedPointer>

#include "Gene.h"
#include "AttributeConditioning.h"
#include "AttributeType.h"

class Genome
{
public:
    static Genome crossing(const Genome& a, const Genome& b);
    Genome();
    Genome(const Genome& a, const Genome& b);

    void addAttributesPair(AttributeType typeA, AttributeType typeB);
    void addAttributeToGene(AttributeType type, QSharedPointer<Gene> gene, GenePosition pos);
    qreal getAttributeValue(AttributeType type) const;
    int genesCount() const;
    QSet<QSharedPointer<Gene>> getChromosome() const;
    bool isConditioned(AttributeType type) const;
private:
    QMap<AttributeType, AttributeConditioning> conditionings_;
    QSet<QSharedPointer<Gene>> chromosome_;


};

#endif // GENOME_H
