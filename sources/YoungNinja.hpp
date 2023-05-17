#include "Ninja.hpp"
#ifndef COWBOY_VS_NINJA_A_YOUNGNINJA_H
#define COWBOY_VS_NINJA_A_YOUNGNINJA_H
namespace ariel {
    class YoungNinja : public Ninja {
    public:
        YoungNinja(const string &name, Point location): Ninja(name, location){}
    };
}
#endif //COWBOY_VS_NINJA_A_YOUNGNINJA_H
