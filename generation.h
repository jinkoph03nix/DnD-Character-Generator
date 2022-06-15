#pragma once
#include "struct.h"
//extra: morbius

void simpleGen(std::vector<character>& charList, int numChars);

int searchListSpells (character charList, string key);
int searchListSkills (character charList, string key);
int searchListTrait (character charList, string key);
int searchListLang (character charList, string key);