#include "Ninja.hpp"
#ifndef COWBOY_VS_NINJA_A_TRAINEDNINJA_H
#define COWBOY_VS_NINJA_A_TRAINEDNINJA_H
namespace ariel {
    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const string &name, Point location): Ninja(name, location){}
    };
}
#endif //COWBOY_VS_NINJA_A_TRAINEDNINJA_H