#include "Gene.h"

bool Gene::compareAttributes(const Gene &a, const Gene &b)
{
    return (a.getAttribute(GenePosition::A) == b.getAttribute(GenePosition::A) && a.getAttribute(GenePosition::B) == b.getAttribute(GenePosition::B));
}

Gene Gene::crossing(const Gene &a, const Gene &b)
{
    if(!compareAttributes(a,b))throw(std::invalid_argument("incompatible genes"));

    Gene new_gene;
    qreal new_sigma = (a.sigma_ + b.sigma_)/2;
    std::normal_distribution<double> g_dis(0, new_sigma);
    GenePosition dominant = rand()%2 ? GenePosition::A : GenePosition::B;
    qreal base_value = rand()%2 ? a.getValue(dominant) : b.getValue(dominant);
    new_gene.setSigma(new_sigma);
    new_gene.setBase( base_value, dominant);
    new_gene.setEnhancement(g_dis(Randomizer::rand_gen()), GenePosition::A);
    new_gene.setEnhancement(g_dis(Randomizer::rand_gen()), GenePosition::B);
    new_gene.setAttribute(a.getAttribute(GenePosition::A), GenePosition::A);
    new_gene.setAttribute(a.getAttribute(GenePosition::B), GenePosition::B);
    return new_gene;
}

Gene::Gene()
    :sigma_(DEFAULT_SIGMA)
{
    randomize();
}

Gene::Gene(const Gene &other)
    :sigma_(other.sigma_)
{
    setBase( other.getBase(GenePosition::A) , GenePosition::A);
    setEnhancement(other.getEnhancement(GenePosition::A), GenePosition::A);
    setEnhancement(other.getEnhancement(GenePosition::B), GenePosition::B);
    setAttribute(other.getAttribute(GenePosition::A), GenePosition::A);
    setAttribute(other.getAttribute(GenePosition::B), GenePosition::B);
}

Gene::Gene(const Gene &a, const Gene &b)
    :Gene(Gene::crossing(a, b))
{

}

qreal Gene::getBase(GenePosition pos) const
{
    return base_[pos];
}

qreal Gene::getEnhancement(GenePosition pos) const
{
    return enhancement_[pos];
}

qreal Gene::getValue(GenePosition pos) const
{
    return base_[pos] + enhancement_[pos];
}

AttributeType Gene::getAttribute(GenePosition pos) const
{
    return attribute_[pos];
}

void Gene::setBase(const qreal &value, GenePosition pos = GenePosition::A)
{
    base_[pos] = value;
    base_[1-pos] = 1 - value;
}

void Gene::setEnhancement(const qreal &value, GenePosition pos)
{
    enhancement_[pos] = value;
}

void Gene::setAttribute(const AttributeType &type, GenePosition pos)
{
    attribute_[pos] = type;
}

void Gene::setSigma(const qreal &value)
{
    sigma_ = value;
}


qreal Gene::getMutationChance() const
{
    return mutation_chance_;
}

void Gene::setMutationChance(const qreal &mutation_chance)
{
    mutation_chance_ = mutation_chance;
}

void Gene::randomize()
{
    std::uniform_real_distribution<> dis(0,1);
    std::normal_distribution<double> g_dis(0, sigma_);
    setBase(dis(Randomizer::rand_gen()));
    setEnhancement(g_dis(Randomizer::rand_gen()), GenePosition::A);
    setEnhancement(g_dis(Randomizer::rand_gen()), GenePosition::B);
}

void Gene::print(int length)
{
    int ast1 = (int)(getValue(GenePosition::A)*length);
    int ast2 = (int)(getValue(GenePosition::B)*length);
    int i;
    std::cout<<"cecha1\t|";
    for(i = 0; i < ast1 && i < length-1; ++i)
        std::cout<<"-";
    std::cout<<"*";
    for(++i; i < length; ++i)
        std::cout<<"-";
    std::cout<<"|\n base: "<<getBase(GenePosition::A)<<"\t odchylenie: "<<enhancement_[GenePosition::A]<<"\t wartosc: "<<getValue(GenePosition::A)<<std::endl;
    std::cout<<"cecha2\t|";
    for(i = 0; i < ast2 && i < length-1; ++i)
        std::cout<<"-";
    std::cout<<"*";
    for(++i; i < length; ++i)
        std::cout<<"-";
    std::cout<<"|\n base: "<<getBase(GenePosition::B)<<"\t odchylenie: "<<enhancement_[GenePosition::B]<<"\t wartosc: "<<getValue(GenePosition::B)<<std::endl;

}

qreal Gene::getSigma() const
{
    return sigma_;
}


