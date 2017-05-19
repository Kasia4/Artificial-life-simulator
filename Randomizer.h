#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

class Randomizer
{

public:
    static Randomizer& getInstance();

    std::mt19937 getGenerator();

private:
    Randomizer();
    Randomizer(const Randomizer&) = delete;
    Randomizer& operator=(const Randomizer&) = delete;

    std::random_device rd;
    std::mt19937 gen;
};

#endif // RANDOMIZER_H
