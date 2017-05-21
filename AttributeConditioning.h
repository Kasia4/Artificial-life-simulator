#ifndef ATTRIBUTECONDITIONING_H
#define ATTRIBUTECONDITIONING_H

#include <QSharedPointer>
#include "Gene.h"

class AttributeConditioning
{
public:
    AttributeConditioning();
    AttributeConditioning(const GenePosition &position, QSharedPointer<Gene> gene);
    GenePosition position() const;
    void setPosition(const GenePosition &position);

    QSharedPointer<Gene> gene_handle() const;
    void setGene_handle(QSharedPointer<Gene> gene_handle);

private:
    GenePosition position_;
    QSharedPointer<Gene> gene_handle_;
};

#endif // ATTRIBUTECONDITIONING_H
