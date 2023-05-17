#ifndef COWBOY_VS_NINJA_A_TEAM2_H
#define COWBOY_VS_NINJA_A_TEAM2_H
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
namespace ariel {

    class Team2 {
    private:
        int size;
        Character *leader;
        vector<Character *> characters;

        void setNextLeader(){}

        friend Character *findMinDist(Character *source, Team2 &team){ return NULL ;}

    public:
        Team2(Character *leader): size(0), leader(leader){}
        Team2(const Team2& other) = default ;
        Team2& operator=(const Team2& other) = default ;
        Team2(Team2&& other)noexcept = default ;
        Team2& operator=(Team2&& other) noexcept = default ;
        ~Team2(){}

        void add(Character *character){}

        void attack(Team2 *targetTeam){}

        int stillAlive() const{ return size ;}

        void print(){}
    };
}
#endif