#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

class Randomizer
{

public:
    static Randomizer& getInstance();
    static std::mt19937& rand_gen();

private:
    Randomizer();
    Randomizer(const Randomizer&) = delete;
    Randomizer& operator=(const Randomizer&) = delete;

    std::random_device rd_;
    std::mt19937 gen_;
};

#endif // RANDOMIZER_H
