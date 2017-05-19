#include "Randomizer.h"

Randomizer &Randomizer::getInstance()
{
    static Randomizer instance;
    return instance;
}

std::mt19937 &Randomizer::rand_gen()
{
    return getInstance().gen_;
}

Randomizer::Randomizer()
    :gen_(rd_())
{

}
