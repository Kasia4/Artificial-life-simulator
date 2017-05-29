#ifndef GENOME_H
#define GENOME_H

#include <QMap>
#include <QList>
#include <QSharedPointer>

#include <exception>

#include "Gene.h"
#include "Range.h"
#include "AttributeConditioning.h"
#include "AttributeType.h"

class Genome
{
public:
    typedef QList<QSharedPointer<Gene>> Chromosome;
    typedef QMap<AttributeType, Range> AttributeRange;
    static Genome crossing(const Genome& a, const Genome& b);

    Genome();

	void addAttributesPair(AttributeType typeA, AttributeType typeB);

    int genesCount() const;
    Chromosome getChromosome() const;
    bool isConditioned(AttributeType type) const;
    bool areCoupled(AttributeType typeA, AttributeType typeB) const;
    void setAttributeRange(AttributeType type, const Range& range);
    Range getAttributeRange(AttributeType type) const;
    qreal getAttributeValue(AttributeType type) const;

	qreal getAttributeEnchancement(AttributeType type) const;
private:
	void addAttributeToGene(AttributeType type, QSharedPointer<Gene> gene, GenePosition pos);


    QMap<AttributeType, AttributeConditioning> conditionings_;
    AttributeRange ranges_;
    Chromosome chromosome_;

};

#endif // GENOME_H
