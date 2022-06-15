#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <vector>
using namespace std;

struct character { //structure for all stats to be stored + printed out
  //basics
  string fName, lName;
  string cClass;
  string race;
  string align;
  string background;

  //stats + proficiencies
  int str, dex, con, in, wis, cha;
  vector<string> skills, saves, equip, features, spells, prof;

  vector<string> languages, tools;

  //personality
  vector<string> personality;
  string flaw;
  string bond;
  string ideal;

  //stats
  int ac, initi, speed, hp;

  //appearance
  string hair, height, weight, eyes, gender;
  int age;

  //backstory
  string parentStatus, home, wealthClass;
  vector<string> lifeEvents;
  int sibNum;

  //spellcasting
  bool isMagic;

  //gold
  int gp;
};

#endif