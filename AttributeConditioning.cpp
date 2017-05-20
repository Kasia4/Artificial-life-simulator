#include "AttributeConditioning.h"

AttributeConditioning::AttributeConditioning()
{

}

GenePosition AttributeConditioning::position() const
{
    return position_;
}

void AttributeConditioning::setPosition(const GenePosition &position)
{
    position_ = position;
}

Gene *AttributeConditioning::gene_handle() const
{
    return gene_handle_;
}

void AttributeConditioning::setGene_handle(Gene *gene_handle)
{
    gene_handle_ = gene_handle;
}
