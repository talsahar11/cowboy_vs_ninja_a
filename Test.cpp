#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <iostream>
using namespace ariel ;
TEST_CASE("Point class tests"){
    Point p(0.1, 2.3) ;
    Point p2(0.4, 5.15) ;
    CHECK_EQ(p.getX(), 0.1) ;
    CHECK_EQ(p.getY(), 2.3) ;
    CHECK_EQ(p.distance(p2), 2.8657459761814205734) ;
    CHECK_EQ(p2.distance(p), 2.8657459761814205734) ;
    Point src_p(3,5), end_p(10.5,11.614378277661) ;
    Point dest_p = moveTowards(src_p, end_p, 10);
    std::cout << dest_p <<std::endl ;
    CHECK_EQ(dest_p.getX(), end_p.getX()) ;
    CHECK_EQ(dest_p.getY(), end_p.getY()) ;

    dest_p = moveTowards(dest_p, end_p, 0) ;
    CHECK_EQ(dest_p.getX(), 10.5) ;
    CHECK_EQ(dest_p.getY(), 11.614378277661) ;
}

TEST_SUITE_BEGIN("Character class tests") ;
TEST_CASE("Cowboy class tests"){
    Point p1(1, 5) ;
    Point p2(7, 11) ;
    Cowboy c1("Lucky Luke", p1) ;
    Cowboy c2("Billy the kid", p2) ;

    CHECK_EQ(c1.getLocation(), p1) ;
    CHECK_EQ(c2.getLocation(), p2) ;
    CHECK_EQ(c1.getName(), "Lucky Luke") ;
    CHECK_EQ(c2.getName(), "Billy the kid") ;


    CHECK(c1.hasBullets()) ;
    CHECK(c2.hasBullets()) ;
    CHECK(c1.isAlive()) ;
    CHECK(c2.isAlive()) ;

    for(int i = 0 ; i < 6 ; i++){
        c1.shoot(&c2) ;
    }
    CHECK(!c1.hasBullets()) ;
    c1.reload() ;
    CHECK(c1.hasBullets()) ;
    for(int i = 0 ; i < 5 ; i++){
        c1.shoot(&c2) ;
    }
    CHECK(!c2.isAlive()) ;
}

TEST_CASE("Ninja class tests"){
    Point p1(1.3, 5.7) ;
    Point p2(15, 11) ;
    Point p3(-17.5, 11) ;
    YoungNinja youngN("Ching Bong", p1) ;
    TrainedNinja trainedN("Yoshimitsu", p2) ;
    OldNinja oldN("Master Oshi", p3) ;

    //-----Ctor tests-----
    CHECK_EQ(youngN.getName(), "Ching Bong") ;
    CHECK_EQ(trainedN.getName(), "Yoshimitsu") ;
    CHECK_EQ(oldN.getName(), "Master Oshi") ;

    CHECK_EQ(youngN.getLocation(), p1) ;
    CHECK_EQ(trainedN.getLocation(), p2) ;
    CHECK_EQ(oldN.getLocation(), p3) ;

    CHECK(youngN.isAlive()) ;
    CHECK(trainedN.isAlive()) ;
    CHECK(oldN.isAlive()) ;

    CHECK_EQ(youngN.distance(&trainedN), 14.689451997947369221719782217405736446380615234375) ;
    CHECK_EQ(youngN.distance(&oldN), 19.532792939055081404831071267835795879364013671875) ;
    CHECK_EQ(oldN.distance(&trainedN), 32.5) ;

    youngN.slash(&oldN) ;
    CHECK_EQ(oldN.getHitPoints(), 150) ;

    trainedN.move(&oldN) ;
    CHECK_EQ(oldN.distance(&trainedN), 20.5) ;
    oldN.move(&trainedN) ;
    CHECK_EQ(oldN.distance(&trainedN), 12.5) ;
    trainedN.move(&oldN) ;
    CHECK_EQ(oldN.distance(&trainedN), 0.5) ;

    trainedN.slash(&oldN) ;
    CHECK_EQ(oldN.getHitPoints(), 110) ;

    oldN.slash(&trainedN) ;
    CHECK_EQ(trainedN.getHitPoints(), 80) ;

    for(int i = 0 ; i < 2 ;i++){
        oldN.slash(&trainedN) ;
    }
    CHECK(!trainedN.isAlive()) ;

    trainedN.slash(&oldN) ;
    CHECK_EQ(oldN.getHitPoints(), 110) ;
    std::cout << "YN: " << youngN.getLocation() << " ON: " << oldN.getLocation() << std::endl ;
    youngN.move(&oldN) ;
    std::cout << "L1: " << youngN.getLocation() << " L2: " << oldN.getLocation() << " dist: " << youngN.distance(&oldN) << std::endl ;
    CHECK_EQ(youngN.distance(&oldN), 0) ;
    youngN.slash(&oldN) ;
    CHECK_EQ(oldN.getHitPoints(), 70) ;
}

TEST_CASE("Team tests") {
    Character *leader1 = new TrainedNinja("Yoshimitsu", Point(10, 0)),
            *leader2 = new Cowboy("Bobby", Point(0, 10));
    Character *ch1 = new Cowboy("Jonson", Point(20, 0)),
            *ch2 = new YoungNinja("Kai", Point(30, 0)),
            *ch3 = new TrainedNinja("Chong", Point(40, 0)),
            *ch4 = new OldNinja("Kong", Point(50, 0)),
            *ch5 = new Cowboy("Luke", Point(60, 0)),
            *ch6 = new Cowboy("Jameson", Point(70, 0)),
            *ch7 = new OldNinja("Kai", Point(80, 0)),
            *ch8 = new YoungNinja("Khang", Point(90, 0)),
            *ch9 = new Cowboy("Yossi", Point(100, 0)),
            *ch10 = new TrainedNinja("Chai", Point(0, 0)),
            *ch11 = new Cowboy("George", Point(0, 20)),
            *ch12 = new TrainedNinja("Leonardo", Point(0, 30)),
            *ch13 = new Cowboy("Lucy", Point(0, 40)),
            *ch14 = new OldNinja("Suzuki", Point(0, 50)),
            *ch15 = new Cowboy("Hatch", Point(0, 60)),
            *ch16 = new YoungNinja("Lucy", Point(0, 70)),
            *ch17 = new Cowboy("Harold", Point(0, 80)),
            *ch18 = new TrainedNinja("Leonardo", Point(0, 90)),
            *ch19 = new Cowboy("Hank", Point(0, 100)),
            *ch20 = new OldNinja("Master Oshi", Point(0, 0));

    Team *team1 = new Team(leader1);
    Team *team2 = new Team(leader2);
    team1->add(ch1);
    team1->add(ch2);
    team1->add(ch3);
    team1->add(ch4);
    team1->add(ch5);
    team1->add(ch6);
    team1->add(ch7);
    team1->add(ch8);
    team1->add(ch9);

    CHECK_THROWS(team1->add(ch10));

    team2->add(ch11);
    team2->add(ch12);
    team2->add(ch13);
    team2->add(ch14);
    team2->add(ch15);
    team2->add(ch16);
    team2->add(ch17);
    team2->add(ch18);
    team2->add(ch19);
    CHECK_THROWS(team2->add(ch20));
    CHECK_EQ(team1->stillAlive(), 10) ;
    CHECK_EQ(team2->stillAlive(), 10) ;

    //-- Attack 1: --
    team1->attack(team2);

    //-- Cowboys attack --
    CHECK(team2->getLeader()->getHitPoints() == 70) ;

    //-- Ninjas attack --
    CHECK(team1->getLeader()->getLocation() == Point(1.5147186257614304594198983977548778057098388671875,8.4852813742385695405801016022451221942901611328125)) ;
    CHECK(ch2->getLocation() == Point(16.71843382729280591547649237327277660369873046875,4.4271887242357310654483626422006636857986450195312)) ;
    CHECK(ch3->getLocation() == Point(28.35828999825601925977025530301034450531005859375,2.9104275004359956291466460243100300431251525878906)) ;
    CHECK(ch4->getLocation() == Point(42.155354594472640883395797573029994964599609375,1.5689290811054723562278923054691404104232788085938)) ;
    CHECK(ch7->getLocation() == Point( 72.061776986290652757816133089363574981689453125,0.99227787671366773913916858873562887310981750488281)) ;
    CHECK(ch8->getLocation() == Point(76.0856277145693411512183956801891326904296875,1.5460413650478515013020341939409263432025909423828)) ;


    //-- Attack 2: --
    team1->attack(team2) ;

    //-- Cowboys attack --
    CHECK(team2->getLeader()->getHitPoints() == 30) ;

    //-- Ninjas attack --
    CHECK(leader1->getLocation() == Point(0, 10)) ;
    CHECK(ch2->getLocation() == Point(3.4368676545856136073098241467960178852081298828125,8.8543774484714621308967252844013273715972900390625)) ;
    CHECK(ch3->getLocation() == Point(16.7165799965120385195405106060206890106201171875,5.8208550008719912582932920486200600862503051757812)) ;
    CHECK(ch4->getLocation() == Point(34.31070918894528176679159514605998992919921875,3.1378581622109447124557846109382808208465576171875)) ;
    CHECK(ch7->getLocation() == Point(64.12355397258130551563226617872714996337890625,1.9845557534273354782783371774712577462196350097656)) ;
    CHECK(ch8->getLocation() == Point(62.17125542913867519700943375937640666961669921875,3.0920827300957030026040683878818526864051818847656)) ;


    // -- Attack 3: --
    team1->attack(team2) ;

    //-- Cowboys attack --
    CHECK(leader2->getHitPoints() == 0) ;
    CHECK(leader2->isAlive() == false) ;
    CHECK(ch11->getHitPoints() == 100) ;

    //-- Ninjas attack --
    CHECK(leader1->getLocation() == Point(0, 20)) ;
    CHECK(ch2->getLocation() == Point(0, 20)) ;
    CHECK(ch3->getLocation() == Point(7.5652228199859674617755445069633424282073974609375,13.58311381049981747537458431906998157501220703125)) ;
    CHECK(ch4->getLocation() == Point(27.130917173714095724790240637958049774169921875,6.6663970408436421521969350578729063272476196289062)) ;
    CHECK(ch7->getLocation() == Point(56.42174240985097100065104314126074314117431640625,4.1483715154998188623380883655045181512832641601562)) ;
    CHECK(ch8->getLocation() == Point(48.66192441835233495339707587845623493194580078125,6.766041853576322040453305817209184169769287109375)) ;

    //-- Attack 4: --
    team1->attack(team2) ;

    //-- Ninjas attack --
    CHECK(leader1->getLocation() == Point(0, 20)) ;
    CHECK(ch2->getLocation() == Point(0, 20)) ;
    CHECK(ch11->getHitPoints() == 0) ;
    CHECK(ch11->isAlive() == false) ;

    CHECK(ch3->getLocation() == Point(2.5429843233129210133824926742818206548690795898438,24.4816054713919442065162002108991146087646484375)) ;
    CHECK(ch4->getLocation() == Point(21.065547693121803973781425156630575656890869140625,11.882841525729833875857366365380585193634033203125)) ;
    CHECK(ch7->getLocation() == Point(49.1488168452341511738268309272825717926025390625,7.4807210967327240069835170288570225238800048828125)) ;
    CHECK(ch8->getLocation() == Point(36.0280931640206603105980320833623409271240234375,12.798148271493044347835166263394057750701904296875)) ;


}

TEST_CASE("Team2 tests") {
    Character *leader1 = new TrainedNinja("Yoshimitsu", Point(10, 0)),
            *leader2 = new Cowboy("Bobby", Point(0, 10));
    Character *ch1 = new Cowboy("Jonson", Point(20, 0)),
            *ch2 = new YoungNinja("Kai", Point(30, 0)),
            *ch3 = new TrainedNinja("Chong", Point(40, 0)),
            *ch4 = new OldNinja("Kong", Point(50, 0)),
            *ch5 = new Cowboy("Luke", Point(60, 0)),
            *ch6 = new Cowboy("Jameson", Point(70, 0)),
            *ch7 = new OldNinja("Kai", Point(80, 0)),
            *ch8 = new YoungNinja("Khang", Point(90, 0)),
            *ch9 = new Cowboy("Yossi", Point(100, 0)),
            *ch10 = new TrainedNinja("Chai", Point(0, 0)),
            *ch11 = new Cowboy("George", Point(0, 20)),
            *ch12 = new TrainedNinja("Leonardo", Point(0, 30)),
            *ch13 = new Cowboy("Lucy", Point(0, 40)),
            *ch14 = new OldNinja("Suzuki", Point(0, 50)),
            *ch15 = new Cowboy("Hatch", Point(0, 60)),
            *ch16 = new YoungNinja("Lucy", Point(0, 70)),
            *ch17 = new Cowboy("Harold", Point(0, 80)),
            *ch18 = new TrainedNinja("Leonardo", Point(0, 90)),
            *ch19 = new Cowboy("Hank", Point(0, 100)),
            *ch20 = new OldNinja("Master Oshi", Point(0, 0));

    Team2 *team1 = new Team2(leader1);
    Team2 *team2 = new Team2(leader2);
    team1->add(ch1);
    team1->add(ch2);
    team1->add(ch3);
    team1->add(ch4);
    team1->add(ch5);
    team1->add(ch6);
    team1->add(ch7);
    team1->add(ch8);
    team1->add(ch9);

    CHECK_THROWS(team1->add(ch10));
    team2->add(ch11);
    team2->add(ch12);
    team2->add(ch13);
    team2->add(ch14);
    team2->add(ch15);
    team2->add(ch16);
    team2->add(ch17);
    team2->add(ch18);
    team2->add(ch19);
    CHECK_THROWS(team2->add(ch20));
    CHECK_EQ(team1->stillAlive(), 10) ;
    CHECK_EQ(team2->stillAlive(), 10) ;

    //-- Attack 1: --
    team1->attack(team2);

    //-- Ninjas attack --
    CHECK(leader1->getLocation() == Point(1.5147186257614304594198983977548778057098388671875,8.4852813742385695405801016022451221942901611328125)) ;
    CHECK(ch2->getLocation() == Point(16.71843382729280591547649237327277660369873046875,4.4271887242357310654483626422006636857986450195312)) ;
    CHECK(ch3->getLocation() == Point(28.35828999825601925977025530301034450531005859375,2.9104275004359956291466460243100300431251525878906)) ;
    CHECK(ch4->getLocation() == Point(42.155354594472640883395797573029994964599609375,1.5689290811054723562278923054691404104232788085938)) ;
    CHECK(ch7->getLocation() == Point( 72.061776986290652757816133089363574981689453125,0.99227787671366773913916858873562887310981750488281)) ;
    CHECK(ch8->getLocation() == Point(76.0856277145693411512183956801891326904296875,1.5460413650478515013020341939409263432025909423828)) ;
    CHECK(leader2->getHitPoints() == 70) ;

    //-- Attack 2: --
    team1->attack(team2) ;

    CHECK(leader1->getLocation() == Point(0, 10)) ;
    CHECK(ch2->getLocation() == Point(3.4368676545856136073098241467960178852081298828125,8.8543774484714621308967252844013273715972900390625)) ;
    CHECK(ch3->getLocation() == Point(16.7165799965120385195405106060206890106201171875,5.8208550008719912582932920486200600862503051757812)) ;
    CHECK(ch4->getLocation() == Point(34.31070918894528176679159514605998992919921875,3.1378581622109447124557846109382808208465576171875)) ;
    CHECK(ch7->getLocation() == Point(64.12355397258130551563226617872714996337890625,1.9845557534273354782783371774712577462196350097656)) ;
    CHECK(ch8->getLocation() == Point(62.17125542913867519700943375937640666961669921875,3.0920827300957030026040683878818526864051818847656)) ;
    CHECK(leader2->getHitPoints() == 30) ;


    // -- Attack 3: --
    team1->attack(team2) ;

    //-- Cowboys attack --
    CHECK(leader2->getHitPoints() == 0) ;
    CHECK(leader2->isAlive() == false) ;
    CHECK(ch11->getHitPoints() == 70) ;

    //-- Ninjas attack --
    CHECK(leader1->getLocation() == Point(0, 10)) ;
    CHECK(ch2->getLocation() == Point(0, 20)) ;
    CHECK(ch3->getLocation() == Point(7.5652228199859674617755445069633424282073974609375,13.58311381049981747537458431906998157501220703125)) ;
    CHECK(ch4->getLocation() == Point(27.130917173714095724790240637958049774169921875,6.6663970408436421521969350578729063272476196289062)) ;
    CHECK(ch7->getLocation() == Point(56.42174240985097100065104314126074314117431640625,4.1483715154998188623380883655045181512832641601562)) ;
    CHECK(ch8->getLocation() == Point(48.66192441835233495339707587845623493194580078125,6.766041853576322040453305817209184169769287109375)) ;

    //-- Attack 4: --
    team1->attack(team2) ;

    //-- Cowboys attack --
    CHECK(ch11->getHitPoints() == 0) ;
    CHECK(ch11->isAlive() == false) ;
}

TEST_CASE("SmartTeam tests"){
    //-----Attack strategy test-----
    Point n1p(0,0) ;
    Point n2p(0,-10) ;
    Point c1p(-10, 0) ;
    Point n3p(20, 0) ;
    Point c2p(20,10) ;
    Character* ninja1 = new YoungNinja("Yoshi", n1p) ;
    Character* ninja2 = new YoungNinja("Sushi", n2p) ;
    Character* cowboy1 = new Cowboy("Bill", c1p) ;
    SmartTeam* team1 = new SmartTeam(ninja1) ;
    team1->add(cowboy1) ;
    team1->add(ninja2) ;

    Character* ninja3 = new OldNinja("Osho", n3p) ;
    Character* cowboy2 = new Cowboy("Jones", c2p) ;
    SmartTeam* team2 = new SmartTeam(ninja3) ;
    team2->add(cowboy2) ;

    team1->attack(team2) ;

    //-----Check that the cowboy shot the most close character in avarage from all team mates-----
    CHECK(ninja3->getHitPoints() == 150) ;

    //-----Check that the first ninja move towards the closest enemy-----
    Point expectedLocation = moveTowards(Point(0,0), n3p, 14) ;
    CHECK(ninja1->getLocation() == expectedLocation) ;

    //-----Check that the second ninja move towards the closest non-targeted enemy-----
    expectedLocation = moveTowards(n2p, c2p, 14) ;
    CHECK(ninja2->getLocation() == expectedLocation) ;

    team2->attack(team1) ;
    team2->attack(team1) ;
    Point temp = ninja1->getLocation() ;
    team1->attack(team2) ;

    //-----Check that the wounded ninja sets into guard mode, and going to protect the other ninja, that is the weakest
    //-----member in the team after it-----
    CHECK(temp.distance(ninja2->getLocation()) > ninja1->distance(ninja2)) ;
}