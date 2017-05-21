#include "AttributeConditioning.h"

AttributeConditioning::AttributeConditioning()
{

}

AttributeConditioning::AttributeConditioning(const GenePosition &position, QSharedPointer<Gene> gene)
{
    position_ = position;
    gene_handle_ = gene;
}

GenePosition AttributeConditioning::position() const
{
    return position_;
}

void AttributeConditioning::setPosition(const GenePosition &position)
{
    position_ = position;
}

void AttributeConditioning::setGene_handle(QSharedPointer<Gene> gene_handle)
{
    gene_handle_ = gene_handle;
}

QSharedPointer<Gene> AttributeConditioning::gene_handle() const
{
    return gene_handle_;
}
