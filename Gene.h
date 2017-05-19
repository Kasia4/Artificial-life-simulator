#ifndef GENE_H
#define GENE_H

#include <QtGlobal>
#include "Randomizer.h"
#include <iostream>
class Gene
{
public:

    static qreal constexpr DEFAULT_SIGMA = 0.4;
    Gene();
    Gene(const Gene& other);
    Gene(const Gene& a, const Gene& b);

    qreal getBaseA() const;
    qreal getBaseB() const;
    qreal getEnhancementA() const;
    qreal getEnhancementB() const;
    qreal getValueA() const;
    qreal getValueB() const;
    qreal getSigma() const;
    qreal getMutationChance() const;

    void setBaseA(const qreal &value);
    void setBaseB(const qreal &value);
    void setEnhancementA(const qreal &value);
    void setEnhancementB(const qreal &value);

    void setSigma(const qreal &value);
    void setMutationChance(const qreal &mutation_chance);

    void randomize();

    void print(int length);



private:
    qreal base_value_;
    qreal enhancement_A_;
    qreal enhancement_B_;

    qreal sigma_;
    qreal mutation_chance_;
};

#endif // GENE_H
