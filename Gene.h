/* Gene.h
 * author: Karol Checinski
 *
 * The Gene class defines values for two binded attributes.
 * Provides methods to randomize these values.
 * The value of attribute is the sum of its base (b_X) and enhancement (e_X)
 * Bases of binded attributes: b_A = 1 - b_B
 */

#ifndef GENE_H
#define GENE_H

#include <QtGlobal>
#include <iostream>

#include "Randomizer.h"
#include "AttributeType.h"

enum GenePosition : unsigned
{
    A = 0,
    B
};

class Gene
{
public:

    static qreal constexpr DEFAULT_SIGMA = 0.1;

	/** Checks whether two genes defines the same attributes **/
	static bool compareAttributes(const Gene& a, const Gene& b);

    static Gene crossing(const Gene& a, const Gene& b);

    Gene();
    Gene(const Gene& other);
    Gene(const Gene& a, const Gene& b);

    qreal getBase(GenePosition pos) const;
    qreal getEnhancement(GenePosition pos) const;
    qreal getValue(GenePosition pos) const;
    AttributeType getAttribute(GenePosition pos) const;
    qreal getSigma() const;
    qreal getMutationChance() const;

    void setBase(const qreal &value, GenePosition pos);
    void setEnhancement(const qreal &value, GenePosition pos);
    void setAttribute(const AttributeType &type, GenePosition pos);
    void setSigma(const qreal &value);
    void setMutationChance(const qreal &mutation_chance);

    void randomize();

	/** Prints gene parameters on standard output. Displays attributes' values on bars with given lenght. **/
    void print(int length);

private:
    qreal base_[2];
    qreal enhancement_[2];
    AttributeType attribute_[2];

    qreal sigma_;
    qreal mutation_chance_;
};

#endif // GENE_H
