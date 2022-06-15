#include <iostream>
#include <fstream>
#include <vector>
#include "GetData.h"
#include "generation.h"
#include "struct.h"
using namespace std;

/*
Contributors: @jinkoph03nix, @RedMatteo007, @Quackerman, @Tanishcompsci
GetDataR2.cpp & GetData.h are from Darryl DiGiovanna
Project Name: Github-athon Project: D&D Character Generator
Date: 6/3/2022
Extra: morbius
*/

void sortList(vector<character>& charList);
void printInfo(ofstream& sheet, vector<character> charList, int i);

int main() {
  //sets up txt file for output
  ofstream sheet;
  sheet.open("charSheet.txt");
  //write-to line: sheet << "string" << endl;

  cout << "\n-----------------------------------" << endl;
  cout << "D&D CHARACTER GENERATOR" << endl;
  cout << "-----------------------------------" << endl;
  cout << endl;
  
  //gets number of characters to generate (store in vector of structs)
  int numChars;
  do {
    cout << "How many characters do you want to generate?: " << endl;
  } while (!getValidInt(numChars) || numChars > 1000 || numChars < 1);

  vector<character> charList(numChars);
  
  //based on complexity, randomize in function
  simpleGen(charList, numChars);

  sortList(charList);

  int charChoice;
  do{
    //user chooses which character to print out to file
    do {
      cout << "\nWhich character do you want to print out?" << endl;
      for (int i = 0; i < charList.size(); i++){
        cout << i+1 << ". " << charList[i].fName << " " << charList[i].lName << " (" << charList[i].race << ", " << charList[i].cClass << ")" << endl;
      }
      cout << charList.size()+1 << ". Exit" << endl;
      cout << "Enter the corresponding number: ";
    } while(!getValidInt(charChoice) || charChoice < 1 || charChoice > charList.size()+1);
  
    cout << endl;

    //prints to file
    ofstream sheet("charSheet.txt"); //clears file
    if (charChoice != charList.size()+1){
      printInfo(sheet, charList, charChoice-1);
      cout << "Character Sheet Generated. Check the charSheet.txt file for the result!" << endl << endl;
    }

  } while (charChoice != charList.size()+1); //allows for multiple sheets to be generated

  sheet.close();
}

void sortList(vector<character>& charList){
  //sorts list for menu so characters are in alphabetical order by first name
    int i, j;
    character temp; // holding variable
    int listLength = charList.size(); 
    for (i=0; i < (listLength -1); i++) // element to be compared
      {
        for(j = (i+1); j < listLength; j++) // rest of the elements
           {
              if (charList[i].fName > charList[j].fName)
                 {
                    temp= charList[i]; // swap
                    charList[i] = charList[j];
                    charList[j] = temp;
                 }
              else if (charList[i].fName == charList[j].fName){
                if (charList[i].lName > charList[j].lName){
                    temp= charList[i]; // swap
                    charList[i] = charList[j];
                    charList[j] = temp;
                }
              }
            }
       }
}

void printInfo(ofstream& sheet, vector<character> charList, int i){
    //prints out character sheet in the .txt file
    sheet << "Name: " << charList[i].fName << " " << charList[i].lName << endl;
    sheet << "Class: " << charList[i].cClass << ", Level: 1" << endl;
    sheet << "Race: " << charList[i].race << endl;
    sheet << "Background: " << charList[i].background << endl;
    sheet << "Alignment: " << charList[i].align << endl;
    sheet << endl;
    sheet << "HP: " << charList[i].hp << endl;
    sheet << "AC: " << charList[i].ac << endl;
    sheet << "Initiative: " << charList[i].initi << endl;
    sheet << "Speed: " << charList[i].speed << endl;
    sheet << endl;
    sheet << "ABILITY SCORES: " << endl;
    sheet << "STR: " << charList[i].str << " DEX: " << charList[i].dex << " CON: " << charList[i].con << " INT: " << charList[i].in << " WIS: " << charList[i].wis << " CHA: " << charList[i].cha << endl;
    sheet << "Saving Throws: ";
    for (int j = 0; j < charList[i].saves.size(); j++){
      if (j == charList[i].saves.size()-1){
        sheet << charList[i].saves[j] << " ";
      } else {
        sheet << charList[i].saves[j] << ", ";
      }
    }
    sheet << endl << endl;
    sheet << "Skills: ";
    for (int j = 0; j < charList[i].skills.size(); j++){
      if (j == charList[i].skills.size()-1){
        sheet << charList[i].skills[j] << " ";
      } else {
        sheet << charList[i].skills[j] << ", ";
      }
    }
    sheet << endl << endl;
    sheet << "FEATURES: " << endl;
    for (int j = 0; j < charList[i].features.size(); j++){
      sheet << charList[i].features[j] << endl;
    }
    sheet << endl;
    sheet << "PROFICIENCIES: " << endl;
    sheet << "Languages: ";
    for (int j = 0; j < charList[i].languages.size(); j++){
      if (j == charList[i].languages.size()-1){
        sheet << charList[i].languages[j] << " ";
      } else {
        sheet << charList[i].languages[j] << ", ";
      }
    }
    sheet << endl << endl;
    sheet << "Tools: ";
    for (int j = 0; j < charList[i].tools.size(); j++){
      if (j == charList[i].tools.size()-1){
        sheet << charList[i].tools[j] << " ";
      } else {
        sheet << charList[i].tools[j] << ", ";
      }
    }
    sheet << endl << endl;
    sheet << "Equipment: ";
    for (int j = 0; j < charList[i].prof.size(); j++){
      if (j == charList[i].prof.size()-1){
        sheet << charList[i].prof[j] << " ";
      } else {
        sheet << charList[i].prof[j] << ", ";
      }
    }
    sheet << endl << endl;
    sheet << "APPEARANCE: " << endl;
    sheet << "Age: " << charList[i].age << endl;
    sheet << "Gender Presentation: " << charList[i].gender << endl;
    sheet << "Hair Color: " << charList[i].hair << endl;
    sheet << "Eye Color: " << charList[i].eyes << endl;
    sheet << "Height: " << charList[i].height << endl;
    sheet << "Weight: " << charList[i].weight << endl;
    sheet << endl;
    sheet << "BACKSTORY: " << endl;
    sheet << "Parental Status: " << charList[i].parentStatus << endl;
    sheet << "Number of Siblings: " << charList[i].sibNum << endl;
    sheet << "Childhood Home: " << charList[i].home << endl;
    sheet << "Wealth Class: " << charList[i].wealthClass << endl;
    sheet << "Key Life Events: ";
    for (int j = 0; j < charList[i].lifeEvents.size(); j++){
      if (j == charList[i].lifeEvents.size()-1){
        sheet << charList[i].lifeEvents[j] << " ";
      } else {
        sheet << charList[i].lifeEvents[j] << ", ";
      }
    }
    sheet << endl << endl;
    sheet << "EQUIPMENT: " << endl;
    for (int j = 0; j < charList[i].equip.size(); j++){
      sheet << charList[i].equip[j] << endl;
    }
    sheet << endl;
    sheet << "GP: " << charList[i].gp << endl;
    sheet << endl;
    sheet << "Personality Traits: ";
    for (int j = 0; j < charList[i].personality.size(); j++){
      if (j == charList[i].personality.size()-1){
        sheet << charList[i].personality[j] << " ";
      } else {
        sheet << charList[i].personality[j] << ", ";
      }
    }
    sheet << endl;
    sheet << "Ideal: " << charList[i].ideal << endl;
    sheet << "Bond: " << charList[i].bond << endl;
    sheet << "Flaw: " << charList[i].flaw << endl;
    sheet << endl;
    if (charList[i].isMagic == true){
      sheet << "SPELLS: " << endl;
      for (int j = 0; j < charList[i].spells.size(); j++){
        sheet << charList[i].spells[j] << endl;
      }
      sheet << endl;
    }
}