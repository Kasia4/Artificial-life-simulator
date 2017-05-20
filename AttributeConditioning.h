#ifndef ATTRIBUTECONDITIONING_H
#define ATTRIBUTECONDITIONING_H


class AttributeConditioning
{
public:
    AttributeConditioning();
    GenePosition position() const;
    void setPosition(const GenePosition &position);

    Gene *gene_handle() const;
    void setGene_handle(Gene *gene_handle);

private:
    GenePosition position_;
    Gene* gene_handle_;
};

#endif // ATTRIBUTECONDITIONING_H
