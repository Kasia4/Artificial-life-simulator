#include "Genome.h"

Genome Genome::crossing(const Genome &a, const Genome &b)
{

}

Genome::Genome()
{

}



void Genome::addAttributesPair(AttributeType typeA, AttributeType typeB)
{
    QSharedPointer<Gene> gene_ptr(new Gene);
    AttributeConditioning condA(GenePosition::A, gene_ptr);
    AttributeConditioning condB(GenePosition::B, gene_ptr);
    chromosome_.insert(gene_ptr);
    conditionings_.insert(typeA, condA);
    conditionings_.insert(typeB, condB);
}

void Genome::addAttributeToGene(AttributeType type, QSharedPointer<Gene> gene, GenePosition pos)
{
    conditionings_.insert(type, AttributeConditioning(pos, gene));
}

qreal Genome::getAttributeValue(AttributeType type) const
{
    AttributeConditioning cond = conditionings_.find(type).value();
    return chromosome_.find(cond.gene_handle())->data()->getValue(cond.position());
}

bool Genome::isConditioned(AttributeType type) const
{
    return conditionings_.contains(type);
}
