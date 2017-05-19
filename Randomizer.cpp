#include "Randomizer.h"

Randomizer &Randomizer::getInstance()
{
    static Randomizer instance;
    return instance;
}

Randomizer::Randomizer()
    :gen(rd())
{

}
