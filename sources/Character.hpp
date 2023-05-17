#include "Point.hpp"
#include <string>
#include <iostream>
#ifndef CHARACTER_H
#define CHARACTER_H
namespace ariel {
    using namespace std;

    class Character {
    private:
        string name;
        Point location;
        int hit_points;
        bool isAssociated ;

    protected:
        ~Character() = default ;
        Character(const Character& other) = default ;
        Character& operator=(const Character& other) = default ;
        Character(Character&& other)noexcept = default ;
        Character& operator=(Character&& other) noexcept = default ;
        Character(string const& name, Point location):name("Fake"), location(Point(0,0)), hit_points(0), isAssociated(false) {}

        void decreaseHitPoints(int value) {}

        virtual string print() { return "" ; }

        virtual void attack(Character *target) = 0;



    public:
        Point getLocation(){ return location ; }
        string getName() { return name ; }
        int getHitPoints() const { return hit_points ; }
        double distance(const Character *other){ return location.distance(location) ; }
        bool isAlive() const { return (hit_points > 0) ; }
        bool isPartOfTeam() const { return isAssociated ; }
        void setPartOfTeam() {}

    };

}
#endif