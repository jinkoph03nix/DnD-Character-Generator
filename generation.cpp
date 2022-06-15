#include <iostream>
#include <vector>
#include "generation.h"
#include <stdlib.h>
#include "lists.h"
using namespace std;
  //extra: fortnite morbius
  /*
    string fName, lName;
    string cClass;
    string race;
    string align;
    string background;
  
    vector<string> personality;
    string flaw;
    string bond;
    string ideal;
  
    int str, dex, con, in, wis, cha;
    vector<string> skills, saves, equip, features, spells;
  
    int ac, initi, speed;
    
    string hair, height, weight, eyes, skin, aesthetic, gender;
    int age;
  
    string parentStatus, birthplace, wealthClass;
    vector<string> lifeEvents; //pdf pg. 70
    int sibNum;
  */
  
  void simpleGen(vector<character>& charList, int numChars){
    srand(time(NULL));
    int random = 0;
    //races - 9
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 9;
    charList[i].race = races[random];
    }
  
    //gender presentation options
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 5;
    charList[i].gender = gender[random];
    }
  
    //classes - 12
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 12;
    charList[i].cClass = classes[random];
    }
  
    //enables spells
    for(int i = 0; i < charList.size(); i++) {
      if (charList[i].cClass == "Bard" || charList[i].cClass == "Cleric" || charList[i].cClass == "Druid" || charList[i].cClass == "Sorcerer" || charList[i].cClass == "Warlock" || charList[i].cClass == "Wizard"){
        charList[i].isMagic = true;
      } else {
        charList[i].isMagic = false;
      }
    }
    
    //ability rolls
    // role 4d6 drop lowest number, add remaining 3d6
    for(int i = 0; i < charList.size(); i++) {
      int total = 0;
      int rando1 = rand() % 6 + 1;
      int rando2 = rand() % 6 + 1;
      
      for(int o = 0; o < 6; o++) {
      total = 0;
      if(rando1 == o) {
        total += 1;
      }
      if(rando2 == o) {
         total += 1;
      }
      int position, position2;
      int dice1, dice2, dice3, dice4;
      int die[4] = {dice1, dice2, dice3, dice4};
      for(int j = 0; j < 4; j++) {
        die[j] = rand() % 6 + 1;
      }
      
      if(die[0] < die[1]) {
        position = 1;
      }
      else {
        position = 2;
      }
      if(die[2] < die[3]) {
        position2 = 3;
      }
      else {
        position2 = 4;
      }
  
      if(die[position-1] < die[position2 - 1]) {
        die[position - 1] = 0; 
      }
      else {
        die[position2 - 1] = 0;
      }
  
      for(int k = 0; k < 4; k++) {
        total = total + die[k];
      }
  
        //ability bonuses based on races
      if(charList[i].race == "Human") {
        total++;
      }
        
      switch(o) {
        case 0:
          if(charList[i].race == "Dragonborn") {
            total += 2;
          }
          if(total > 20) {
            total = 20;
          }
          charList[i].str = total;
          break;
  
        case 1:
          if(charList[i].race == "Elf" || charList[i].race == "Halfling" || charList[i].race == "Half-Orc") {
            total += 2;
          }
          if(total > 20) {
            total = 20;
          }
          charList[i].dex = total;
          break;
        
        case 2:
          if(charList[i].race == "Dwarf") {
            total += 2;
          }
          if(charList[i].race == "Half-Orc" || charList[i].race == "Tiefling") {
            total += 1;
          }
          if(total > 20) {
            total = 20;
          }
          charList[i].in = total;
          break;
        
        case 3:
          if(charList[i].race == "Dwarf") {
            total += 2;
          }
          if(charList[i].race == "Half-Orc") {
           total += 1; 
          }
          if(total > 20) {
            total = 20;
          }
          charList[i].con = total;
          break;
        
        case 4:
          charList[i].wis = total;
          if(total > 20) {
            total = 20;
          }
          break;
        
        case 5:
          if(charList[i].race == "Dragonborn") {
            total += 1;
          }
          if(charList[i].race == "Tiefling" || charList[i].race == "Half-Elf") {
            total += 2;
          }
          if(total > 20) {
            total = 20;
          }
          charList[i].cha = total;
          break;
        }
      }
    }
  
    //health
    for(int i = 0; i < charList.size(); i++) {
  
    int conMod = 0;
    if (charList[i].con == 1){
      conMod -= 5;
    } else if (charList[i].con == 2 || charList[i].con == 3){
      conMod -= 4;
    } else if (charList[i].con == 4 || charList[i].con == 5){
      conMod -= 3;
    } else if (charList[i].con == 6 || charList[i].con == 7){
      conMod -= 2;
    } else if (charList[i].con == 8 || charList[i].con == 9){
      conMod -= 1;
    } else if (charList[i].con == 12 || charList[i].con == 13){
      conMod += 1;
    } else if (charList[i].con == 14 || charList[i].con == 15){
      conMod += 2;
    } else if (charList[i].con == 16 || charList[i].con == 17){
      conMod += 3;
    } else if (charList[i].con == 18 || charList[i].con == 19){
      conMod += 4;
    } else if (charList[i].con == 20){
      conMod += 5;
    } else {
      conMod = 0;
    }
  
    
    if(charList[i].cClass == "Barbarian") {
      charList[i].hp = 12 + conMod; 
    }
  
    if(charList[i].cClass == "Fighter" || charList[i].cClass == "Paladin" || charList[i].cClass == "Ranger") {
      charList[i].hp = 10 + conMod; 
    }
  
    if(charList[i].cClass == "Bard" || charList[i].cClass == "Cleric" || charList[i].cClass == "Druid" || charList[i].cClass == "Monk" || charList[i].cClass == "Rogue" || charList[i].cClass == "Warlock") {
      charList[i].hp = 8 + conMod; 
    }
  
    if(charList[i].cClass == "Wizard" || charList[i].cClass == "Sorcerer") {
      charList[i].hp = 6 + conMod; 
    }
    }
    
    //Saving Throws
    for(int i = 0; i < charList.size(); i++) {
    if(charList[i].cClass == "Barbarian" || charList[i].cClass == "Fighter") {
      charList[i].saves.push_back("Constitution, Strength");
      }
    if(charList[i].cClass == "Bard") {
          charList[i].saves.push_back("Dexterity, Charisma");
      }
    if(charList[i].cClass == "Cleric" || charList[i].cClass == "Paladin" || charList[i].cClass == "Warlock") {
          charList[i].saves.push_back("Wisdom, Charisma");
      }
      if(charList[i].cClass == "Druid" || charList[i].cClass == "Wizard") {
          charList[i].saves.push_back("Intelligence, Wisdom");
      }
      if(charList[i].cClass == "Monk" || charList[i].cClass == "Ranger") {
          charList[i].saves.push_back("Strength, Dexterity");
      }
      if(charList[i].cClass == "Rogue") {
          charList[i].saves.push_back("Dexterity, Intelligence");
      }
        if(charList[i].cClass == "Sorcerer") {
          charList[i].saves.push_back("Constiution, Charisma");
      }
    }
    
    //Speed
    for(int i = 0; i < charList.size(); i++) {
    if(charList[i].race == "Dwarf" || charList[i].race == "Halfling" || charList[i].race == "Gnome") {
      charList[i].speed = 25;
      }
    else {
      charList[i].speed = 30;
    }
    }
    
    //Initiative
    for(int i = 0; i < charList.size(); i++) {
      charList[i].initi = (charList[i].dex - 10)/2;
    }
  
    int acBonus = 0;
    //Class Features and Proficiencies and Equipment
    for (int i = 0; i < charList.size(); i++){
      acBonus = 0;
      if (charList[i].cClass == "Barbarian"){
        for (int j = 0; j < sizeof(barbarian_features)/sizeof(barbarian_features[0]); j++){
          charList[i].features.push_back(barbarian_features[j]);
        }
        for (int j = 0; j < sizeof(barabarian_profs)/sizeof(barabarian_profs[0]); j++){
          charList[i].prof.push_back(barabarian_profs[j]);
        }
        /*Greataxe vs Martial Melee Weapon*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Greataxe");
        } else if (random == 2){
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
        /*Two Handaxes vs Simple Weapon*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x2 Handaxes");
        } else if (random == 2){
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
  
        charList[i].equip.push_back("x1 Explorer's Pack");
        charList[i].equip.push_back("x4 Javelins");
        
      } else if (charList[i].cClass == "Bard"){
        for (int j = 0; j < sizeof(bard_features)/sizeof(bard_features[0]); j++){
          charList[i].features.push_back(bard_features[j]);
        }
        for (int j = 0; j < sizeof(bard_profs)/sizeof(bard_profs[0]); j++){
          charList[i].prof.push_back(bard_profs[j]);
        }
  
        /*Rapier vs. Longsword vs. Simple Weapon*/
        random = rand() % 3 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Rapier");
        } else if (random == 2){
          charList[i].equip.push_back("x1 Longsword");
        } else if (random == 3){
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
        /*Diplomat's Pack vs Entertainer's Pack*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Diplomat's Pack");
        } else if (random == 2){
          charList[i].equip.push_back("x1 Entertainer's Pack");
        }
        /*Lute vs. Instrument*/
        random = rand() % 10;
        charList[i].equip.push_back("x1 " + instruments[random]);
        charList[i].equip.push_back("x1 Leather Armor");
        charList[i].equip.push_back("x1 Dagger");
        acBonus += 1;
        
      } else if (charList[i].cClass == "Cleric"){
        for (int j = 0; j < sizeof(cleric_features)/sizeof(cleric_features[0]); j++){
          charList[i].features.push_back(cleric_features[j]);
        }
        for (int j = 0; j < sizeof(cleric_profs)/sizeof(cleric_profs[0]); j++){
          charList[i].prof.push_back(cleric_profs[j]);
        }
  
        //mace v. warhammer
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Mace");
        } else {
          charList[i].equip.push_back("x1 Warhammer");
        }
  
        /*Scale mail (+4) vs Leather armor (+1) vs Chain Mail (+6)*/
        random = rand() % 3 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Scale Mail");
          acBonus += 4;
        } else if(random == 2) {
          charList[i].equip.push_back("x1 Leather Armor");
          acBonus += 1;
        } else {
          charList[i].equip.push_back("x1 Chain Mail");
          acBonus += 6;
        }
        /*Light Crossbow + 20 bolts vs Simple Weapon*/
        if (random == 1){
          charList[i].equip.push_back("x1 Light Crossbow + 20 Bolts");
        } else {
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
        /*Priest's Pack vs Explorer's Pack*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Priest's Pack");
        } else {
          charList[i].equip.push_back("x1 Explorer's Pack");
        }
        
        charList[i].equip.push_back("x1 Shield");
        charList[i].equip.push_back("x1 Holy Symbol");
        acBonus += 2;
        
      } else if (charList[i].cClass == "Druid"){
        for (int j = 0; j < sizeof(druid_features)/sizeof(druid_features[0]); j++){
          charList[i].features.push_back(druid_features[j]);
        }
        for (int j = 0; j < sizeof(druid_profs)/sizeof(druid_profs[0]); j++){
          charList[i].prof.push_back(druid_profs[j]);
        }
  
        /*Shield vs Simple Weapon*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Shield");
          acBonus += 2;
        } else if (random == 2){
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
        /*Scimitar vs Simple Melee Weapon*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Scimitar");
        } else if (random == 2){
          random = rand() % 9;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
        charList[i].equip.push_back("x1 Leather Armor");
        charList[i].equip.push_back("x1 Explorer's Pack");
        charList[i].equip.push_back("x1 Druidic Focus");
        acBonus += 1;
      }
      
      else if (charList[i].cClass == "Fighter") {
        for (int j = 0; j < sizeof(fighter_features)/sizeof(fighter_features[0]); j++){
          charList[i].features.push_back(fighter_features[j]);
        }
        for (int j = 0; j < sizeof(fighter_profs)/sizeof(fighter_profs[0]); j++){
          charList[i].prof.push_back(fighter_profs[j]);
        }
  
        /*Chain Mail vs Leather, Longbow, & 20 Arrows*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Leather Armor");
          acBonus += 1;
          charList[i].equip.push_back("x1 Longbow + 20 Arrows");
        } else {
          charList[i].equip.push_back("x1 Chain Mail");
          acBonus += 6;
        }
  
        /*Martial weapon + shield vs 2 Martial weapons*/
        random = rand() % 2 + 1;
        if (random == 1){
          random = rand() % 23;
          charList[i].equip.push_back("x1 " + martial_weapons[random]);
          charList[i].equip.push_back("x1 Shield");
          acBonus += 2;
        } else {
          random = rand() % 23;
          charList[i].equip.push_back("x1 " + martial_weapons[random]);
          random = rand() % 23;
          charList[i].equip.push_back("x1 " + martial_weapons[random]);
        }
        
        /*Light crossbow + 20 bolts vs 2 Handaxes*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("Light Crossbow + 20 bolts");
          }
        else {
          charList[i].equip.push_back("2 Handaxes");
        }

        //dungeoneer pack vs explorer's pack
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Dungeoneer's Pack");
        } else {
          charList[i].equip.push_back("x1 Explorer's Pack");
        }
        
      } else if (charList[i].cClass == "Monk") {
        for (int j = 0; j < sizeof(monk_features)/sizeof(monk_features[0]); j++){
          charList[i].features.push_back(monk_features[j]);
        }
        for (int j = 0; j < sizeof(monk_profs)/sizeof(monk_profs[0]); j++){
          charList[i].prof.push_back(monk_profs[j]);
        }
  
        /*Shortsword vs Simple Weapon*/
        random = rand() % 2 + 1;
        if (random == 1){
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        } else {
          charList[i].equip.push_back("x1 Shortsword");
        }
        /*Dungeoneer's Pack vs Explorer's Pack*/
        charList[i].equip.push_back("x10 Darts");
        
      } else if (charList[i].cClass == "Paladin"){
        for (int j = 0; j < sizeof(paladin_features)/sizeof(paladin_features[0]); j++){
          charList[i].features.push_back(paladin_features[j]);
        }
        for (int j = 0; j < sizeof(paladin_profs)/sizeof(paladin_profs[0]); j++){
          charList[i].prof.push_back(paladin_profs[j]);
        }
        
        /* Martial Weapon + shield vs 2 Martial Weapon */
        random = rand() % 2 + 1;
        if (random == 1){
          random = rand() % 23;
          charList[i].equip.push_back("x1 " + martial_weapons[random]);
          charList[i].equip.push_back("x1 Shield");
          acBonus += 2;
        } else {
          random = rand() % 23;
          charList[i].equip.push_back("x1 " + martial_weapons[random]);
          random = rand() % 23;
          charList[i].equip.push_back("x1 " + martial_weapons[random]);
        }
        /*five javelins vs simple melee weapon*/
        random = rand() % 2 + 1;
        if (random == 1){
          random = rand() % 14;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        } else {
          charList[i].equip.push_back("x5 Javelins");
        }
        /*preist's pack vs explorer's pack */
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Priest's Pack");
        } else {
          charList[i].equip.push_back("x1 Explorer's Pack");
        }
        charList[i].equip.push_back("x1 Chain Mail");
        charList[i].equip.push_back("x1 Holy Symbol");
        acBonus += 6;
      } 
  
      else if (charList[i].cClass == "Ranger"){
        for (int j = 0; j < sizeof(ranger_features)/sizeof(ranger_features[0]); j++){
          charList[i].features.push_back(ranger_features[j]);
        }
        for (int j = 0; j < sizeof(ranger_profs)/sizeof(ranger_profs[0]); j++){
          charList[i].prof.push_back(ranger_profs[j]);
        }
  
        /*Scale Mail vs Leather Armor*/
          random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Leather Armor");
          acBonus += 1;
        } else {
          charList[i].equip.push_back("x1 Scale Mail");
          acBonus += 4;
        }
        /*2 Shortswords vs 2 Melee Weapons*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x2 Shortswords");
        } else {
          random = rand() % 9;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
          random = rand() % 9;
          charList[i].equip.push_back("x1 " + simple_weapons[random]);
        }
        /*Dungeoneer's Pack vs Explorer's Pack*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Dungeoneer's Pack");
        } else {
          charList[i].equip.push_back("x1 Explorer's Pack");
        }

        //Longbow + 20 Arrows
        charList[i].equip.push_back("x1 Longbow + 20 arrows");
        
      } else if (charList[i].cClass == "Rogue"){
        for (int j = 0; j < sizeof(rogue_features)/sizeof(rogue_features[0]); j++){
          charList[i].features.push_back(rogue_features[j]);
        }
        for (int j = 0; j < (sizeof(rogue_profs)/sizeof(rogue_profs[0]))-1; j++){
          charList[i].prof.push_back(rogue_profs[j]);
        }
        charList[i].tools.push_back(rogue_profs[6]);
  
        /*Rapier vs Shortsword*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Rapier");
        } else {
          charList[i].equip.push_back("x1 Shortsword");
        }
        /*Shortbow + 20 arrows vs Shortsword*/
        random = rand() % 2 + 1;
        if (random == 1){
          charList[i].equip.push_back("x1 Shortbow + 20 arrows");
        } else {
          charList[i].equip.push_back("x1 Shortsword");
        }
        /*Burglar's Pack vs Dungeoneer's Pack vs Explorer's Pack*/
        if (random == 1){
          charList[i].equip.push_back("x1 Burglar's Pack");
        } else if(random == 2) {
          charList[i].equip.push_back("x1 Dungeoneer's Pack");
        } else {
          charList[i].equip.push_back("x1 Explorer's Pack");
        }
        
        charList[i].equip.push_back("x1 Leather Armor");
        charList[i].equip.push_back("x2 Daggers");
        charList[i].equip.push_back("x1 Thieve's Tools");
        acBonus += 1;
        
      } else if (charList[i].cClass == "Sorcerer"){
        for (int j = 0; j < sizeof(sorcerer_features)/sizeof(sorcerer_features[0]); j++){
          charList[i].features.push_back(sorcerer_features[j]);
        }
        for (int j = 0; j < sizeof(sorcerer_profs)/sizeof(sorcerer_profs[0]); j++){
          charList[i].prof.push_back(sorcerer_profs[j]);
          }
          //Light cross + 20 bolts vs simple weapon
          random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Shortbow + 20 arrows");
          } else {
            random = rand() % 14;
            charList[i].equip.push_back("x1 " + simple_weapons[random]);
          }
          //component pouch or arcane focus
          random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Component Pouch");
          } else {
            charList[i].equip.push_back("x1 Arcane Focus");
          }
          //dungeener pack vs explorer's pack
          random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Dungeoneer's Pack");
          } else {
            charList[i].equip.push_back("x1 Explorer's Pack");
          }
          //2 Daggers
          charList[i].equip.push_back("x2 Daggers");
        
      } else if (charList[i].cClass == "Warlock"){
        for (int j = 0; j < sizeof(warlock_features)/sizeof(warlock_features[0]); j++){
          charList[i].features.push_back(warlock_features[j]);
        }
        for (int j = 0; j < sizeof(warlock_profs)/sizeof(warlock_profs[0]); j++){
          charList[i].prof.push_back(warlock_profs[j]);
        }
  
        /*Light Crossbow + 20 bolts vs Simple Weapon*/
        random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Light Crossbow + 20 bolts");
          } else {
            random = rand() % 14;
            charList[i].equip.push_back("x1 " + simple_weapons[random]);
          }
        /*Component Pouch vs Arcane Focus*/
        random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Component Pouch");
          } else {
            charList[i].equip.push_back("x1 Arcane Focus");
          }
        /*Scholar's Pack vs Dungeoneer's Pack*/
        random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Dungeoneer's Pack");
          } else {
            charList[i].equip.push_back("x1 Scholar's Pack");
          }
        charList[i].equip.push_back("x1 Leather Armor");
        charList[i].equip.push_back("x2 Daggers");
        acBonus += 1;
        
      } else if (charList[i].cClass == "Wizard"){
        for (int j = 0; j < sizeof(wizard_features)/sizeof(wizard_features[0]); j++){
          charList[i].features.push_back(wizard_features[j]);
        }
        for (int j = 0; j < sizeof(wizard_profs)/sizeof(wizard_profs[0]); j++){
          charList[i].prof.push_back(wizard_profs[j]);
        }
        
        //quarterstaff or dagger
        random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Quarterstaff");
          } else {
            charList[i].equip.push_back("x1 Dagger");
          }
        /*Component Pouch vs Arcane Focus*/
        random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Component Pouch");
          } else {
            charList[i].equip.push_back("x1 Arcane Focus");
          }
        //scholar's pack or explorer's pack
        random = rand() % 2 + 1;
          if (random == 1){
            charList[i].equip.push_back("x1 Explorer's Pack");
          } else {
            charList[i].equip.push_back("x1 Scholar's Pack");
          }
        charList[i].equip.push_back("x1 Spellbook");
      } 
  
    //AC: 10+Dex+Class Bonus+Shield Bonus+(Armor bonus-10)
      int dexMod = 0;
      dexMod = 0;
      if (charList[i].dex == 1){
        dexMod -= 5;
      } else if (charList[i].dex == 2 || charList[i].dex == 3){
        dexMod -= 4;
      } else if (charList[i].dex == 4 || charList[i].dex == 5){
        dexMod -= 3;
      } else if (charList[i].dex == 6 || charList[i].dex == 7){
        dexMod -= 2;
      } else if (charList[i].dex == 8 || charList[i].dex == 9){
        dexMod -= 1;
      } else if (charList[i].dex == 12 || charList[i].dex == 13){
        dexMod += 1;
      } else if (charList[i].dex == 14 || charList[i].dex == 15){
        dexMod += 2;
      } else if (charList[i].dex == 16 || charList[i].dex == 17){
        dexMod += 3;
      } else if (charList[i].dex == 18 || charList[i].dex == 19){
        dexMod += 4;
      } else if (charList[i].dex == 20){
        dexMod += 5;
      } else {
        dexMod = 0;
      }
      
      charList[i].ac = 10 + dexMod + acBonus;
    }
  
    
    //Names and Race Traits/Languages
    for (int i = 0; i < charList.size(); i++){
      if (charList[i].race == "Dragonborn"){ //dragonborn names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Dragonborn_female_first_names[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Dragonborn_male_first_name[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Dragonborn_female_first_names[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Dragonborn_male_first_name[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Dragonborn_clan[random];
        
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Draconic");
        for (int j = 0; j < sizeof(dragonborn_features)/sizeof(dragonborn_features[0]); j++){
          charList[i].features.push_back(dragonborn_features[j]);
        }
      } else if (charList[i].race == "Dwarf"){ //dwarf names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Dwarf_female_first_name[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Dwarf_male_first_name[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Dwarf_female_first_name[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Dwarf_male_first_name[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Dwarf_clan_names[random];
        
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Dwarvish");
        for (int j = 0; j < sizeof(dwarf_features)/sizeof(dwarf_features[0]); j++){
          charList[i].features.push_back(dwarf_features[j]);
        }
      } else if (charList[i].race == "Elf"){ //elf names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Elf_female_first_names[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Elf_male_first_names[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Elf_female_first_names[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Elf_male_first_names[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Elf_family_names[random];
  
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Elvish");
        for (int j = 0; j < sizeof(elf_features)/sizeof(elf_features[0]); j++){
          charList[i].features.push_back(elf_features[j]);
        }
      } else if (charList[i].race == "Gnome"){ //gnome names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Gnome_female_first_names[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Gnome_male_first_names[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Gnome_female_first_names[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Gnome_male_first_names[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Gnome_clan[random];
  
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Gnomish");
        for (int j = 0; j < sizeof(gnome_featuers)/sizeof(gnome_featuers[0]); j++){
          charList[i].features.push_back(gnome_featuers[j]);
        }
      } else if (charList[i].race == "Halfling"){ //halfling names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Halfing_female_first_names[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Halfing_male_first_names[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Halfing_female_first_names[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Halfing_male_first_names[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Halfing_clan_last_names[random];
  
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Halfling");
        for (int j = 0; j < sizeof(halfling_features)/sizeof(halfling_features[0]); j++){
          charList[i].features.push_back(halfling_features[j]);
        }
      } else if (charList[i].race == "Half-Orc"){ //half-orc names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Orc_female_first_name[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Orc_male_first_name[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Orc_female_first_name[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Orc_male_first_name[random];
          }
        } // orcs do not have last names
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Orc");
        for (int j = 0; j < sizeof(half_orc_features)/sizeof(half_orc_features[0]); j++){
          charList[i].features.push_back(half_orc_features[j]);
        }
      } else if (charList[i].race == "Tiefling"){ //tiefling names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Tiefling_female_first_name[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Tiefling_male_first_name[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Tiefling_female_first_name[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Tiefling_male_first_name[random];
          }
        } // tieflings do not have last names
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Infernal");
        for (int j = 0; j < sizeof(tiefling_features)/sizeof(tiefling_features[0]); j++){
          charList[i].features.push_back(tiefling_features[j]);
        }
      } else if (charList[i].race == "Human"){ //human names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Human_female_first_name[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Human_male_first_name[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Human_female_first_name[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Human_male_first_name[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Human_last_name[random];
  
        charList[i].languages.push_back("Common");
        for (int j = 0; j < sizeof(human_features)/sizeof(human_features[0]); j++){
          charList[i].features.push_back(human_features[j]);
        }
      } else if (charList[i].race == "Half-Elf"){ //elf names
        if (charList[i].gender == "Female"){
          random = rand() % 10;
          charList[i].fName = Elf_female_first_names[random];
        } else if (charList[i].gender == "Male"){
          random = rand() % 10;
          charList[i].fName = Elf_male_first_names[random];
        } else { //nonbinary options
          random = rand() % 2 + 1;
          if (random == 1){
            random = rand() % 10;
            charList[i].fName = Elf_female_first_names[random];
          } else if (random == 2){
            random = rand() % 10;
            charList[i].fName = Elf_male_first_names[random];
          }
        }
        random = rand() % 10;
        charList[i].lName = Human_last_name[random];
        charList[i].languages.push_back("Common");
        charList[i].languages.push_back("Elvish");
        for (int j = 0; j < sizeof(half_elf_features)/sizeof(half_elf_features[0]); j++){
          charList[i].features.push_back(half_elf_features[j]);
        }
      } 
    }
    
    //Background (Includes Personality, Flaws, Bonds, Ideals, Features, Proficiencies, Skills, and Equipment)
    for (int i = 0; i < charList.size(); i++){
      random = rand() % 13;
      charList[i].background = backgrounds[random];
      random = rand() % 8;
      if (charList[i].background == "Acolyte") {
        charList[i].personality.push_back(acolyte_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], acolyte_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(acolyte_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = acolyte_flaw[random];
        random = rand() % 6;
        charList[i].bond = acolyte_bonds[random];
        random = rand() % 6;
        charList[i].ideal = acolyte_ideal[random];
  
        for (int j = 0; j < sizeof(acolyte_features)/sizeof(acolyte_features[0]); j++){
          charList[i].features.push_back(acolyte_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 18;
            result = searchListLang(charList[i], languages[random]);
            if (result == -1){
              charList[i].languages.push_back(languages[random]);
            }
          } while (result != -1);
        }
  
        for (int j = 0; j < sizeof(acolyte_equip)/sizeof(acolyte_equip[0]); j++){
          charList[i].equip.push_back(acolyte_equip[j]);
        }
  
        charList[i].gp = 15;
  
        for (int j = 0; j < sizeof(acolyte_skills)/sizeof(acolyte_skills[0]); j++){
          charList[i].skills.push_back(acolyte_skills[j]);
        }
        
      } else if (charList[i].background == "Charlatan") {
        charList[i].personality.push_back(charlatan_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], charlatan_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(charlatan_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = charlatan_flaws[random];
        random = rand() % 6;
        charList[i].bond = charlatan_bonds[random];
        random = rand() % 6;
        charList[i].ideal = charlatan_ideals[random];
  
        for (int j = 0; j < sizeof(charlatan_features)/sizeof(charlatan_features[0]); j++){
          charList[i].features.push_back(charlatan_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(charlatan_profs)/sizeof(charlatan_profs[0]); j++){
          charList[i].prof.push_back(charlatan_profs[j]);
        }
  
        for (int j = 0; j < sizeof(charlatan_equip)/sizeof(charlatan_equip[0]); j++){
          charList[i].equip.push_back(charlatan_equip[j]);
        }
  
        charList[i].gp = 15;
  
        for (int j = 0; j < sizeof(charlatan_skills)/sizeof(charlatan_skills[0]); j++){
          charList[i].skills.push_back(charlatan_skills[j]);
        }
        
      } else if (charList[i].background == "Criminal") {
        charList[i].personality.push_back(criminal_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], criminal_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(criminal_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = criminal_flaws[random];
        random = rand() % 6;
        charList[i].bond = criminal_bonds[random];
        random = rand() % 6;
        charList[i].ideal = criminal_ideals[random];
  
        for (int j = 0; j < sizeof(criminal_features)/sizeof(criminal_features[0]); j++){
          charList[i].features.push_back(criminal_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(criminal_profs)/sizeof(criminal_profs[0]); j++){
          charList[i].tools.push_back(criminal_profs[j]);
        }
  
        random = rand() % 3;
        charList[i].tools.push_back(gamesets[random]);
  
        for (int j = 0; j < sizeof(criminal_equip)/sizeof(criminal_equip[0]); j++){
          charList[i].equip.push_back(criminal_equip[j]);
        }
        charList[i].gp = 15;
  
        for (int j = 0; j < sizeof(criminal_skills)/sizeof(criminal_skills[0]); j++){
          charList[i].skills.push_back(criminal_skills[j]);
        }
      
      } else if (charList[i].background == "Folk Hero") {
        charList[i].personality.push_back(folkhero_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], folkhero_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(folkhero_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = folkhero_flaws[random];
        random = rand() % 6;
        charList[i].bond = folkhero_bonds[random];
        random = rand() % 6;
        charList[i].ideal = folkhero_ideals[random];
  
        for (int j = 0; j < sizeof(folkhero_features)/sizeof(folkhero_features[0]); j++){
          charList[i].features.push_back(folkhero_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(folkhero_profs)/sizeof(folkhero_profs[0]); j++){
          charList[i].prof.push_back(folkhero_profs[j]);
        }
  
        random = rand() % 17;
        charList[i].tools.push_back(toolkits[random]);
  
        for (int j = 0; j < sizeof(folkhero_equip)/sizeof(folkhero_equip[0]); j++){
          charList[i].equip.push_back(folkhero_equip[j]);
        }
        charList[i].gp = 10;
  
        for (int j = 0; j < sizeof(folkhero_skills)/sizeof(folkhero_skills[0]); j++){
          charList[i].skills.push_back(folkhero_skills[j]);
        }
      
      } else if (charList[i].background == "Guild Artisan") {
        charList[i].personality.push_back(guild_artisan_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], guild_artisan_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(guild_artisan_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = guild_artisan_flaws[random];
        random = rand() % 6;
        charList[i].bond = guild_artisan_bonds[random];
        random = rand() % 6;
        charList[i].ideal = guild_artisan_ideals[random];
  
        for (int j = 0; j < sizeof(guildartisan_features)/sizeof(guildartisan_features[0]); j++){
          charList[i].features.push_back(guildartisan_features[j]);
        }
  
        int result;
        //proficiencies
        do{
            random = rand() % 18;
            result = searchListLang(charList[i], languages[random]);
            if (result == -1){
              charList[i].languages.push_back(languages[random]);
            }
        } while (result != -1);
        
        random = rand() % 17;
        charList[i].tools.push_back(toolkits[random]);
  
        for (int j = 0; j < sizeof(guildartisan_equip)/sizeof(guildartisan_equip[0]); j++){
          charList[i].equip.push_back(guildartisan_equip[j]);
        }
        charList[i].gp = 15;
  
        for (int j = 0; j < sizeof(guildartisan_skills)/sizeof(guildartisan_skills[0]); j++){
          charList[i].skills.push_back(guildartisan_skills[j]);
        }
      
      } else if (charList[i].background == "Sailor") {
        charList[i].personality.push_back(sailor_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], sailor_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(sailor_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = sailor_flaws[random];
        random = rand() % 6;
        charList[i].bond = sailor_bonds[random];
        random = rand() % 6;
        charList[i].ideal = sailor_ideals[random];
  
        for (int j = 0; j < sizeof(sailor_features)/sizeof(sailor_features[0]); j++){
          charList[i].features.push_back(sailor_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(sailor_profs)/sizeof(sailor_profs[0]); j++){
          charList[i].tools.push_back(sailor_profs[j]);
        }
  
        for (int j = 0; j < sizeof(sailor_equip)/sizeof(sailor_equip[0]); j++){
          charList[i].equip.push_back(sailor_equip[j]);
        }
        charList[i].gp = 10;
  
        for (int j = 0; j < sizeof(sailor_skills)/sizeof(sailor_skills[0]); j++){
          charList[i].skills.push_back(sailor_skills[j]);
        }
      
      } else if (charList[i].background == "Hermit") {
        charList[i].personality.push_back(hermit_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], hermit_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(hermit_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = hermit_flaws[random];
        random = rand() % 6;
        charList[i].bond = hermit_bonds[random];
        random = rand() % 6;
        charList[i].ideal = hermit_ideals[random];
  
        for (int j = 0; j < sizeof(hermit_features)/sizeof(hermit_features[0]); j++){
          charList[i].features.push_back(hermit_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(hermit_profs)/sizeof(hermit_profs[0]); j++){
          charList[i].tools.push_back(hermit_profs[j]);
        }
  
        do{
            random = rand() % 18;
            result = searchListLang(charList[i], languages[random]);
            if (result == -1){
              charList[i].languages.push_back(languages[random]);
            }
        } while (result != -1);
  
        for (int j = 0; j < sizeof(hermit_equip)/sizeof(hermit_equip[0]); j++){
          charList[i].equip.push_back(hermit_equip[j]);
        }
        charList[i].gp = 5;
  
        for (int j = 0; j < sizeof(hermit_skills)/sizeof(hermit_skills[0]); j++){
          charList[i].skills.push_back(hermit_skills[j]);
        }
      
      } else if (charList[i].background == "Noble") {
        charList[i].personality.push_back(noble_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], noble_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(noble_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = noble_flaws[random];
        random = rand() % 6;
        charList[i].bond = noble_bonds[random];
        random = rand() % 6;
        charList[i].ideal = noble_ideals[random];
  
        for (int j = 0; j < sizeof(noble_features)/sizeof(noble_features[0]); j++){
          charList[i].features.push_back(noble_features[j]);
        }
  
        int result;
        //proficiencies
        do{
            random = rand() % 18;
            result = searchListLang(charList[i], languages[random]);
            if (result == -1){
              charList[i].languages.push_back(languages[random]);
            }
        } while (result != -1);
  
        random = rand() % 3;
        charList[i].tools.push_back(gamesets[random]);
  
        for (int j = 0; j < sizeof(noble_equip)/sizeof(noble_equip[0]); j++){
          charList[i].equip.push_back(noble_equip[j]);
        }
        charList[i].gp = 25;
  
        for (int j = 0; j < sizeof(noble_skills)/sizeof(noble_skills[0]); j++){
          charList[i].skills.push_back(noble_skills[j]);
        }
      
      } else if (charList[i].background == "Outlander") {
        charList[i].personality.push_back(outlander_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], outlander_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(outlander_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = outlander_flaws[random];
        random = rand() % 6;
        charList[i].bond = outlander_bonds[random];
        random = rand() % 6;
        charList[i].ideal = outlander_ideals[random];
  
        for (int j = 0; j < sizeof(noble_features)/sizeof(noble_features[0]); j++){
          charList[i].features.push_back(outlander_features[j]);
        }
  
        int result;
        //proficiencies
        do{
            random = rand() % 18;
            result = searchListLang(charList[i], languages[random]);
            if (result == -1){
              charList[i].languages.push_back(languages[random]);
            }
        } while (result != -1);
  
        random = rand() % 3;
        charList[i].tools.push_back(toolkits[random]);
  
        for (int j = 0; j < sizeof(noble_equip)/sizeof(noble_equip[0]); j++){
          charList[i].equip.push_back(outlander_equip[j]);
        }
        charList[i].gp = 10;
  
        for (int j = 0; j < sizeof(noble_skills)/sizeof(noble_skills[0]); j++){
          charList[i].skills.push_back(outlander_skills[j]);
        }
      
      } else if (charList[i].background == "Sage") {
        charList[i].personality.push_back(sage_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], sage_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(sage_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = sage_flaws[random];
        random = rand() % 6;
        charList[i].bond = sage_bonds[random];
        random = rand() % 6;
        charList[i].ideal = sage_ideals[random];
  
        for (int j = 0; j < sizeof(sage_features)/sizeof(sage_features[0]); j++){
          charList[i].features.push_back(sage_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 18;
            result = searchListLang(charList[i], languages[random]);
            if (result == -1){
              charList[i].languages.push_back(languages[random]);
            }
          } while (result != -1);
        }
  
        for (int j = 0; j < sizeof(sage_equip)/sizeof(sage_equip[0]); j++){
          charList[i].equip.push_back(sage_equip[j]);
        }
  
        charList[i].gp = 10;
  
        for (int j = 0; j < sizeof(sage_skills)/sizeof(sage_skills[0]); j++){
          charList[i].skills.push_back(sage_skills[j]);
        }
        
      } else if (charList[i].background == "Soldier") {
        charList[i].personality.push_back(soldier_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], soldier_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(soldier_personality[random]);
        random = rand() % 6;
        charList[i].flaw = soldier_flaws[random];
        random = rand() % 6;
        charList[i].bond = soldier_bonds[random];
        random = rand() % 6;
        charList[i].ideal = soldier_ideals[random];
  
        for (int j = 0; j < sizeof(soldier_features)/sizeof(soldier_features[0]); j++){
          charList[i].features.push_back(soldier_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(soldier_profs)/sizeof(soldier_profs[0]); j++){
          charList[i].tools.push_back(soldier_profs[j]);
        }
  
        random = rand() % 3;
        charList[i].tools.push_back(gamesets[random]);
  
        for (int j = 0; j < sizeof(soldier_equip)/sizeof(soldier_equip[0]); j++){
          charList[i].equip.push_back(soldier_equip[j]);
        }
        charList[i].gp = 15;
  
        for (int j = 0; j < sizeof(soldier_skills)/sizeof(soldier_skills[0]); j++){
          charList[i].skills.push_back(soldier_skills[j]);
        }
      
      } else if (charList[i].background == "Urchin") {
        charList[i].personality.push_back(urchin_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], urchin_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(urchin_personality[random]);
        random = rand() % 6;
        charList[i].flaw = urchin_flaws[random];
        random = rand() % 6;
        charList[i].bond = urchin_bonds[random];
        random = rand() % 6;
        charList[i].ideal = urchin_ideals[random];
  
        for (int j = 0; j < sizeof(urchin_features)/sizeof(urchin_features[0]); j++){
          charList[i].features.push_back(urchin_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(urchin_profs)/sizeof(urchin_profs[0]); j++){
          charList[i].tools.push_back(urchin_profs[j]);
        }
  
        for (int j = 0; j < sizeof(urchin_equip)/sizeof(urchin_equip[0]); j++){
          charList[i].equip.push_back(urchin_equip[j]);
        }
        charList[i].gp = 10;
  
        for (int j = 0; j < sizeof(sailor_skills)/sizeof(sailor_skills[0]); j++){
          charList[i].skills.push_back(sailor_skills[j]);
        }
      
      } else if (charList[i].background == "Entertainer") {
        charList[i].personality.push_back(entertainer_personality[random]);
        random = rand() % 8;
        while (searchListTrait(charList[i], entertainer_personality[random]) > -1) {
          random = rand() % 8;
        }
        charList[i].personality.push_back(entertainer_personality[random]);
  
        random = rand() % 6;
        charList[i].flaw = soldier_flaws[random];
        random = rand() % 6;
        charList[i].bond = soldier_bonds[random];
        random = rand() % 6;
        charList[i].ideal = soldier_ideals[random];
  
        for (int j = 0; j < sizeof(soldier_features)/sizeof(soldier_features[0]); j++){
          charList[i].features.push_back(soldier_features[j]);
        }
  
        int result;
        //proficiencies
        for (int j = 0; j < sizeof(entertainer_profs)/sizeof(entertainer_profs[0]); j++){
          charList[i].tools.push_back(entertainer_profs[j]);
        }
  
        random = rand() % 10;
        charList[i].tools.push_back(instruments[random]);
  
        for (int j = 0; j < sizeof(entertainer_equip)/sizeof(entertainer_equip[0]); j++){
          charList[i].equip.push_back(entertainer_equip[j]);
        }
        charList[i].gp = 15;
  
        for (int j = 0; j < sizeof(entertainer_skills)/sizeof(entertainer_skills[0]); j++){
          charList[i].skills.push_back(entertainer_skills[j]);
        }
      
      } else {
        //this shouldn't be possible
      }
    }

    //Trinket
    for (int i = 0; i < charList.size(); i++) {
      random = rand() % 50;
      charList[i].equip.push_back("x1 " + trinkets[i]);
    }
    
    //Alignment
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 9;
    charList[i].align = alignments[random];
    }
  
    //Appearances
    //hair color
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 7;
    charList[i].hair = hair_color[random];
    }
  
    //eye color
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 12;
    charList[i].eyes = eye_color[random];
    }
  
    //height
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 5;
    charList[i].height = height[random];
    }
  
    //weight
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 7;
    charList[i].weight = weight[random];
    }
  
    //Ages
    for(int i = 0; i < charList.size(); i++) {
      if (charList[i].race == "Human" || charList[i].race == "Half-Elf" || charList[i].race == "Half-Orc" || charList[i].race == "Halfling" || charList[i].race == "Dragonborn" || charList[i].race == "Tiefling"){
        random = 18 + rand() % 53;
        charList[i].age = random;
      } else if (charList[i].race == "Dwarf" || charList[i].race == "Gnome"){
        random = 40 + rand() % 110;
        charList[i].age = random;
      } else if (charList[i].race == "Elf"){
        random = 110 + rand() % 140;
        charList[i].age = random;
      }
    }
  
    //BACKSTORY
    //parent status
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 8;
    charList[i].parentStatus = parent_status[random];
    }
  
    //childhood home
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 11;
    charList[i].home = home[random];
    }
    
    //wealth class
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 8;
    charList[i].wealthClass = wealth[random];
    }
  
    //sibling number
    for(int i = 0; i < charList.size(); i++) {
    random = rand() % 10;
    charList[i].sibNum = random;
    }
  
    int randAmnt = 0;
  
    //life events based on age
    for(int i = 0; i < charList.size(); i++) {
      if (charList[i].age <= 20){
        random = rand() % 46;
        charList[i].lifeEvents.push_back(life_events[random]);
      } else if (charList[i].age <= 30 && charList[i].age > 20){
        randAmnt = rand() % 4 + 1;
        for (int j = 0; j < randAmnt; j++){
          random = rand() % 46;
          charList[i].lifeEvents.push_back(life_events[random]);
        }
      } else if (charList[i].age <= 40 && charList[i].age > 30){
        randAmnt = rand() % 6 + 1;
        for (int j = 0; j < randAmnt; j++){
          random = rand() % 46;
          charList[i].lifeEvents.push_back(life_events[random]);
        }
      } else if (charList[i].age <= 50 && charList[i].age > 40){
        randAmnt = rand() % 8 + 1;
        for (int j = 0; j < randAmnt; j++){
          random = rand() % 46;
          charList[i].lifeEvents.push_back(life_events[random]);
        }
      } else if (charList[i].age <= 60 && charList[i].age > 50){
        randAmnt = rand() % 10 + 1;
        for (int j = 0; j < randAmnt; j++){
          random = rand() % 46;
          charList[i].lifeEvents.push_back(life_events[random]);
        }
      } else if (charList[i].age > 60){
        randAmnt = rand() % 12 + 1;
        for (int j = 0; j < randAmnt; j++){
          random = rand() % 46;
          charList[i].lifeEvents.push_back(life_events[random]);
        }
      }  
    }
  
    int result;
    
    //Spells
    for (int i = 0; i < charList.size(); i++){
      if (charList[i].cClass == "Bard"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_bard_0[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_bard_0[random]);
            }
          } while (result != -1);
        }
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_bard_1[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_bard_1[random]);
            }
          } while (result != -1);
        }
        
      } else if (charList[i].cClass == "Cleric"){
        for (int j = 0; j < 3; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_cleric_0[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_cleric_0[random]);
            }
          } while (result != -1);
        }
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_cleric_1[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_cleric_1[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Druid"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_druid_0[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_druid_0[random]);
            }
          } while (result != -1);
        }
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_druid_1[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_druid_1[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Sorcerer"){
        for (int j = 0; j < 4; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_sorcerer_0[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_sorcerer_0[random]);
            }
          } while (result != -1);
        }
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_sorcerer_1[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_sorcerer_1[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Warlock"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_warlock_0[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_warlock_0[random]);
            }
          } while (result != -1);
        }
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_warlock_1[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_warlock_1[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Wizard"){
        for (int j = 0; j < 3; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_wizard_0[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_wizard_0[random]);
            }
          } while (result != -1);
        }
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSpells(charList[i], spells_wizard_1[random]);
            if (result == -1){
              charList[i].spells.push_back(spells_wizard_1[random]);
            }
          } while (result != -1);
        }
      } 
    }
  
    //Skills
    for (int i = 0; i < charList.size(); i++){
      if (charList[i].cClass == "Barbarian"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 6;
            result = searchListSkills(charList[i], barbarian_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(barbarian_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Bard"){
        for (int j = 0; j < 3; j++){
          do{
            random = rand() % 18;
            result = searchListSkills(charList[i], bard_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(bard_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Cleric"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 5;
            result = searchListSkills(charList[i], cleric_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(cleric_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Druid"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 8;
            result = searchListSkills(charList[i], druid_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(druid_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Fighter"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 5;
            result = searchListSkills(charList[i], fighter_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(fighter_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Monk"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 7;
            result = searchListSkills(charList[i], monk_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(monk_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Paladin"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 6;
            result = searchListSkills(charList[i], paladin_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(paladin_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Ranger"){
        for (int j = 0; j < 3; j++){
          do{
            random = rand() % 8;
            result = searchListSkills(charList[i], ranger_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(ranger_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Rogue"){
        for (int j = 0; j < 4; j++){
          do{
            random = rand() % 12;
            result = searchListSkills(charList[i], rogue_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(rogue_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Sorcerer"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 6;
            result = searchListSkills(charList[i], sorcerer_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(sorcerer_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Warlock"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 6;
            result = searchListSkills(charList[i], warlock_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(warlock_skills[random]);
            }
          } while (result != -1);
        }
      } else if (charList[i].cClass == "Wizard"){
        for (int j = 0; j < 2; j++){
          do{
            random = rand() % 7;
            result = searchListSkills(charList[i], wizard_skills[random]);
            if (result == -1){
              charList[i].skills.push_back(wizard_skills[random]);
            }
          } while (result != -1);
        }
      } 
    }
  }
  
  int searchListSpells (character charList, string key){ //makes sure no repeats occur in spell list
      int i;
        for (int j = 0; j < charList.spells.size(); j++){
          if (charList.spells[j] == key)
              return j;
        }
      return -1;
  }
  
  int searchListSkills (character charList, string key){ //makes sure no repeats occur in skill list
        for (int j = 0; j < charList.skills.size(); j++){
          if (charList.skills[j] == key)
              return j;
        }
      return -1;
  }
  
  int searchListTrait (character charList, string key){ //makes sure no repeats occur in trait list
        for (int j = 0; j < charList.personality.size(); j++){
          if (charList.personality[j] == key)
              return j;
        }
      return -1;
  }
  
  int searchListLang (character charList, string key){ //makes sure no repeats occur in language list
        for (int j = 0; j < charList.languages.size(); j++){
          if (charList.languages[j] == key)
              return j;
        }
      return -1;
  }
