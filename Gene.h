#ifndef GENE_H
#define GENE_H

#include <QtGlobal>
#include "Randomizer.h"
#include <iostream>

enum GenePosition : unsigned {A = 0, B};

class Gene
{
public:

    static qreal constexpr DEFAULT_SIGMA = 0.4;
    static Gene crossing(const Gene& a, const Gene& b);
    Gene();
    Gene(const Gene& other);
    Gene(const Gene& a, const Gene& b);

    qreal getBase(GenePosition pos) const;
    qreal getEnhancement(GenePosition pos) const;
    qreal getValue(GenePosition pos) const;

    qreal getSigma() const;
    qreal getMutationChance() const;

    void setBase(const qreal &value, GenePosition pos);
    void setEnhancement(const qreal &value, GenePosition pos);

    void setSigma(const qreal &value);
    void setMutationChance(const qreal &mutation_chance);

    void randomize();

    void print(int length);



private:
    qreal base_[2];
    qreal enhancement_[2];

    qreal sigma_;
    qreal mutation_chance_;
};

#endif // GENE_H
