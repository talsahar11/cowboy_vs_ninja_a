#ifndef COWBOY_VS_NINJA_A_SMARTTEAM_H
#define COWBOY_VS_NINJA_A_SMARTTEAM_H
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include <map>
namespace ariel {
    class SmartTeam {
    private:
        int size;
        Character *leader;
        Character *cowboysTarget ;
        vector<Character *> characters;
        vector<Point*> locations ;
        map<Character*, bool> is_targeted ;
        map<Character*, Character*> ninjasGuards ;
        void setNextLeader(){}
        friend Character *findMinDist(Character *source, SmartTeam &team) { return NULL ;}
        Character* getCowboysTarget(SmartTeam *targetTeam) { return cowboysTarget ;}
        Character* getNinjasTarget(Character *ninja, SmartTeam *targetTeam){ return leader ;}
        void cowboysAttack(SmartTeam *targetTeam) {}
        void ninjasAttack(SmartTeam *targetTeam) {}
        Character* findWeakestMember(Character *ninja) { return leader ;}
        void guard(Character* ninja) {}
    public:
        SmartTeam(Character *leader): size(0), leader(leader), cowboysTarget(NULL){}

        ~SmartTeam(){}
        SmartTeam(const SmartTeam& other) = default ;
        SmartTeam& operator=(const SmartTeam& other) = default ;
        SmartTeam(SmartTeam&& other)noexcept = default ;
        SmartTeam& operator=(SmartTeam&& other) noexcept = default ;
        void add(Character *character){}

        void attack(SmartTeam *targetTeam){}

        int stillAlive() const{ return size ; }

        void print(){}


        vector<Character*> getCharacters() { return characters ; }
    };
}
#endif
