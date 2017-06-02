#include "Genome.h"


Genome Genome::crossing(const Genome &a, const Genome &b)
{
    if(a.genesCount() != b.genesCount())throw(std::invalid_argument("incompatible genomes"));
    auto iter_a = a.chromosome_.begin();
    auto iter_b = b.chromosome_.begin();
    Genome new_genome;
    for(;iter_a != a.chromosome_.end(); ++iter_a , ++iter_b)
    {
        if( !Gene::compareAttributes(*(iter_a->data()),*(iter_b->data())) ) throw(std::invalid_argument("incompatible genomes"));
        AttributeType type_a = iter_a->data()->getAttribute(GenePosition::A);
        AttributeType type_b = iter_a->data()->getAttribute(GenePosition::B);
        QSharedPointer<Gene> gene = QSharedPointer<Gene>(new Gene(*(iter_a->data()), *(iter_b->data())));
        new_genome.addAttributeToGene(type_a, gene, GenePosition::A);
        new_genome.addAttributeToGene(type_b, gene, GenePosition::B);
    }
    new_genome.ranges_=a.ranges_;
    return new_genome;
}

Genome::Genome()
{

}

void Genome::addAttributesPair(AttributeType typeA, AttributeType typeB)
{
    QSharedPointer<Gene> gene_ptr(new Gene);
    AttributeConditioning condA(GenePosition::A, gene_ptr);
    AttributeConditioning condB(GenePosition::B, gene_ptr);
    gene_ptr->setAttribute(typeA, GenePosition::A);
    gene_ptr->setAttribute(typeB, GenePosition::B);
    chromosome_.append(gene_ptr);
    conditionings_.insert(typeA, condA);
    conditionings_.insert(typeB, condB);
}

void Genome::addAttributeToGene(AttributeType type, QSharedPointer<Gene> gene, GenePosition pos)
{
    conditionings_.insert(type, AttributeConditioning(pos, gene));
    if(!chromosome_.contains(gene))chromosome_.append(gene);
}


qreal Genome::getAttributeValue(AttributeType type) const
{
    AttributeConditioning cond = conditionings_.value(type);
    qreal att_value = cond.gene_handle()->getValue(cond.position());
	return ranges_.value(type).transform(att_value);
}

qreal Genome::getAttributeEnchancement(AttributeType type) const
{
	AttributeConditioning cond = conditionings_.value(type);
	return cond.gene_handle()->getEnhancement(cond.position());

}

int Genome::genesCount() const
{
    return chromosome_.count();
}

bool Genome::isConditioned(AttributeType type) const
{
    return conditionings_.contains(type);
}

bool Genome::areCoupled(AttributeType typeA, AttributeType typeB) const
{
    return conditionings_.find(typeA).value().gene_handle() == conditionings_.find(typeB).value().gene_handle();
}

void Genome::setAttributeRange(AttributeType type, const Range &range)
{
    ranges_.insert(type, range);
}

Range Genome::getAttributeRange(AttributeType type) const
{
    return ranges_.value(type);
}

