#include "Gene.h"

Gene::Gene()
    :sigma_(DEFAULT_SIGMA)
{
    randomize();
}

Gene::Gene(const Gene &other)
    :base_value_(other.base_value_)
    ,enhancement_A_(other.enhancement_A_)
    ,enhancement_B_(other.enhancement_B_)
    ,sigma_(other.sigma_)
{

}

Gene::Gene(const Gene &a, const Gene &b)
    :sigma_(DEFAULT_SIGMA)
{

    std::normal_distribution<double> g_dis(0, sigma_);
    std::cout<<"Krzyzowanie \t"<<std::endl;
    if(rand()%2)
    {
        std::cout<<"Na podstawie A"<<std::endl;
        setBaseA( rand()%2 ? a.getValueA() : b.getValueA() );
    }
    else
    {
        std::cout<<"Na podstawie B"<<std::endl;
        setBaseB( rand()%2 ? a.getValueB() : b.getValueB() );
    }
    enhancement_A_ = g_dis(Randomizer::rand_gen());
    enhancement_B_ = g_dis(Randomizer::rand_gen());
}

qreal Gene::getBaseA() const
{
    return base_value_;
}

qreal Gene::getBaseB() const
{
    return 1 - base_value_;
}

qreal Gene::getEnhancementA() const
{
    return enhancement_A_;
}

qreal Gene::getEnhancementB() const
{
    return enhancement_B_;
}

qreal Gene::getValueA() const
{
    return getBaseA() + enhancement_A_;
}

qreal Gene::getValueB() const
{
    return getBaseB() + enhancement_B_;
}

void Gene::setBaseA(const qreal &value)
{
    base_value_ = value;
}

void Gene::setBaseB(const qreal &value)
{
    base_value_ = 1 - value;
}

void Gene::setEnhancementA(const qreal &value)
{
    enhancement_A_ = value;
}

void Gene::setEnhancementB(const qreal &value)
{
    enhancement_B_ = value;
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
    base_value_ = dis(Randomizer::rand_gen());
    enhancement_A_ = g_dis(Randomizer::rand_gen());
    enhancement_B_ = g_dis(Randomizer::rand_gen());
}

void Gene::print(int length)
{
    float att1 = base_value_+ enhancement_A_;
    float att2 = 1 - base_value_+ enhancement_B_;
    int ast1 = (int)(att1*length);
    int ast2 = (int)(att2*length);
    int i;
    std::cout<<"cecha1\t|";
    for(i = 0; i < ast1 && i < length-1; ++i)
        std::cout<<"-";
    std::cout<<"*";
    for(++i; i < length; ++i)
        std::cout<<"-";
    std::cout<<"|\n base: "<<base_value_<<"\t odchylenie: "<<enhancement_A_<<"\t wartosc: "<<base_value_+ enhancement_A_<<std::endl;
    std::cout<<"cecha2\t|";
    for(i = 0; i < ast2 && i < length-1; ++i)
        std::cout<<"-";
    std::cout<<"*";
    for(++i; i < length; ++i)
        std::cout<<"-";
    std::cout<<"|\n base: "<<1 - base_value_<<"\t odchylenie: "<<enhancement_B_<<"\t wartosc: "<<1 - base_value_+ enhancement_B_<<std::endl;

}

qreal Gene::getSigma() const
{
    return sigma_;
}

