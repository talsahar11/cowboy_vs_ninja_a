#include "Ninja.hpp"
#ifndef COWBOY_VS_NINJA_A_OLDNINJA_H
#define COWBOY_VS_NINJA_A_OLDNINJA_H
namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(const string &name, Point location): Ninja(name, location){}
    };
}
#endif //COWBOY_VS_NINJA_A_OLDNINJA_H
