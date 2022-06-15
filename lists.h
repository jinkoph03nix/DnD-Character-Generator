#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//FILE IS USED FOR STORING ARRAYS FOR EASIER RANDOMIZATION
//extra: morbius
// string background_personality[10] = {"", "", "", "", "", "", "", "", "", ""};

//RACE AND CLASS
string races[9] = {"Dwarf", "Elf", "Halfling", "Human", "Dragonborn", "Gnome", "Half-Elf", "Half-Orc", "Tiefling"}; //races
string classes[12] = {"Barbarian", "Bard", "Cleric", "Druid", "Fighter", "Monk", "Paladin", "Ranger", "Rogue", "Sorcerer", "Warlock", "Wizard"}; //classes

//ALIGNMENT
string alignments[9] = {"Lawful Good", "Neutral Good", "Chaotic Good", "Lawful Neutral", "True Neutral", "Chaotic Neutral", "Lawful Evil", "Neutral Evil", "Chaotic Evil"};

//BACKGROUNDS
string backgrounds[13] = {"Acolyte", "Charlatan", "Criminal", "Entertainer", "Folk Hero", "Guild Artisan", "Sailor", "Hermit", "Noble", "Outlander", "Sage", "Soldier", "Urchin"};

//NAME LISTS
//Dragonborn
string Dragonborn_female_first_names[10] = {"Akra", "Biri", "Chassath", "Daar", "Eggren", "Furrele", "Gilkass", "Haran", "Jaxi", "Kadana"};
string Dragonborn_clan[10] = {"Akambherylliax", "Baharaoosh", "Clethinthiallor", "Delmirev", "Esstryrlynn", "Ghaallixirn", "Hashphronyxadyn", "Mystan", "Norixys", "Nemmonis"}; 
string Dragonborn_male_first_name[10] = {"Adrex", "Kiirith", "Nither", "Srorin", "Vrondiss", "Rhogar", "Ghesh", "Trynnicus", "Valorean", "Mozikth"};
//Dwarf
string Dwarf_male_first_name[10] = {"Adrik", "Baern", "Dain", "Erias", "Fallond", "Fargrim", "Gardain", "Kilvar", "Nordak", "Morgran"};
string Dwarf_female_first_name[10] = {"Oriff", "Thodris", "Diesa", "Eidred", "Morana", "Torgga", "Vonana", "Whurdred", "Kristryd", "Werydd"};
string Dwarf_clan_names[10] = {"Loderr", "Morigak", "Silveraxe", "Steelfist", "Torevir", "Torunn", "Ungart", "Trollbleeder", "Ruby-Eye", "Orcfoe"};
//Elf
string Elf_female_first_names[10] = {"Vadania", "Claira", "Elarria", "Arannis", "Soveliss", "Keyleth", "Sariel", "Silaqui", "Valna", "Xanaphia"};
string Elf_male_first_names[10] = {"Lamlis", "Ahvain", "Erevan", "Fivin", "Laucian", "Rolan", "Thamior", "Hadaari", "Halimath", "Aust"};
string Elf_family_names[10] = {"Dalathan", "Firahel", "Goltorah", "Iranapha", "Liadon", "Mystralath", "Othronus", "Rothenel", "Teinithra", "Wasanthi"};
//Gnome
string Gnome_female_first_names[10] = {"Ablaba", "Breena", "Carlin", "Donella", "Ella", "Lilli", "Meena", "Nissa", "Oda", "Panana"};
string Gnome_male_first_names[10] = {"Alston", "Bilbron", "Cockaby", "Dabbledob", "Eldon", "Fonkin", "Gerbo", "Jabble", "Kellen", "Oppleby"};
string Gnome_clan[10] = {"Albaratie", "Beren", "Cobblelob", "Dunben", "Folkor", "Garrick", "Horcusporcus", "Leffery", "Miggledy", "Nackle"};
//Halfling
string Halfing_female_first_names[10] = {"Alain", "Bella", "Bree", "Cora", "Eida", "Dell", "Eran", "Gynnie", "Harriet", "Jo"};
string Halfing_male_first_names[10] = {"Alton", "Bernie", "Callus", "Dannad", "Eddie", "Fildo", "Garret", "Harol", "Igor", "Lazam"};
string Halfing_clan_last_names[10] = {"Appleblossom", "Bigheart", "Cherrycheeks", "Copperkettle", "Fastfoot", "Goldfound", "Hilltopple", "Jamjar", "Littlefoot", "Nimblefingers"};
//Orc
string Orc_male_first_name[10] = {"Braak", "Gnarsh", "Druuk", "Korag", "Morbey", "Ugarth", "Scrag", "Render", "Odorr", "Thokk"};
string Orc_female_first_name[10] = {"Bilga", "Grigi", "Lagazi", "Shautha", "Lezre", "Reeza", "Sutha", "Tompth", "Ovack", "Vanchu"};
//Tiefling
string Tiefling_male_first_name[10] = {"Morbius", "Balam", "Caim", "Damakos", "Ekemon", "Fenriz", "Forcas", "Habor", "Iados", "Kairon"};
string Tiefling_female_first_name[10] = {"Akta", "Beleth", "Criella", "Damaia", "Gadreel", "Hecat", "Kali", "Lerissa", "Manea", "Nija"};
//Human
string Human_male_first_name[10] = {"Adam", "Bernard", "Charles", "Diggory", "Everard", "Fredrick", "Geoffrey", "Henry", "John", "Miles"};
string Human_female_first_name[10] = {"Agatha", "Beatrice", "Cecily", "Egelina", "Eloise", "Galiena", "Helen", "Jacoba", "Jane", "Joan"};
string Human_last_name[10] = {"Forstmane", "Ankos", "Molmel", "Buhananc", "Grizzlyblood", "Morbhallow", "Runetalon", "Bonegrain", "Sundred", "Brightwind"};

//SPELL LISTS
//bard spells
string spells_bard_0[8] = {"Vicious Mockery", "Minor Illusion", "Mage Hand", "Message", "Light", "Friends", "Dancing Lights", "Blade Ward"};
string spells_bard_1[8] = {"Cure Wounds", "Speak with Animals", "Unseen Servant", "Detect Magic", "Longstrider", "Hideous Laughter", "Thunderwave", "Dissonant Whispers"};
//wizard
string spells_wizard_0[8] = {"Fire Bolt", "Message", "Ray of Frost", "Prestidigitation", "Light", "Minor Illusion", "Shocking Grasp", "Dancing Lights"};
string spells_wizard_1[8] = {"Alarm", "Burning Hands", "Magic Missile", "Tenser's Floating Disc", "Ray of Sickness", "Mage Armor", "Find Familiar", "Detect Magic"};
//cleric
string spells_cleric_0[8] = {"Sacred Flame", "Spare the Dying", "Thaumaturgy", "Mending", "Light", "Resistance", "Guidance", "Toll the Dead"};
string spells_cleric_1[8] = {"Create/Destroy Water", "Shield of Faith", "Protection from Evil", "Cure Wounds", "Bless", "Command", "Inflict Wounds", "Guiding Bolt"};
//warlock
string spells_warlock_0[8] = {"Blade Ward", "Eldritch Blast", "Minor Illusion", "Poison Spray", "Mage Hand", "Prestidigitation", "Friends", "Chill Touch"};
string spells_warlock_1[8] = {"Armor of Agathys", "Arms of Hadar", "Hex", "Hellish Rebuke", "Illusory Script", "Protection From Evil & Good", "Unseen Servant", "Charm Person"};
//sorcerer
string spells_sorcerer_0[8] = {"Chill Touch", "Fire Bolt", "Shocking Grasp", "Mage Hand", "Blade Ward", "Dancing Lights", "Mending", "Minor Illusion"};
string spells_sorcerer_1[8] = {"Witch Bolt", "Disguise Self", "Color Spray", "Mage Armor", "Silent Image", "Feather Fall", "Sleep", "Charm Person"};
//druid
string spells_druid_0[8] = {"Druidcraft", "Guidance", "Mending", "Poison Spray", "Thorn Whip", "Shillelagh", "Produce Flame", "Resistance"};
string spells_druid_1[8] = {"Animal Friendship", "Goodberry", "Fog Cloud", "Faerie Fire", "Speak with Animals", "Jump", "Longstrider", "Detect Poison/Disease"};

//SKILL LIST
string skills[18] = {"Acrobatics", "Animal Handling", "Arcana", "Athletics", "Deception", "History", "Insight", "Intimidation", "Investigation", "Medicine", "Nature", "Perception", "Performance", "Persuasion", "Religion", "Sleight of Hand", "Stealth", "Survival"};

//PERSONALITY TRAITS, IDEALS, FLAWS, BONDS
//Acolyte traits
string acolyte_personality[8] = {"I idolize a particular hero of my faith, and constantly refer to that person's deeds and example", "I can find common ground between the fiercest enemies, empathizing with them and always working toward peace.", "I see omens in every event and action. The gods try to speak to us, we just need to listen.", "Nothing can shake my optimistic attitude.", "I quote(or misquote) sacred texts and proverbs in almost every situation.", "I am tolerant(or intolerant) of other faiths and respect(or condemn) the worship of other gods.", "I’ve enjoyed fine food, drink, and high society among my temple’s elite. Rough living grates on me.", "I’ve spent so long in the temple that I have little practical experience dealing with people in the outside world."};
string acolyte_ideal[6] = {"Tradition; The ancient traditions of worship and sacrifice must be preserved and upheld. (Lawful)", "Charity; I always try to help those in need, no matter what the personal cost. (Good)", "Change; We must help bring about the changes the gods are constantly working in the world. (Chaotic)", "Power; I hope to one day rise to the top of my faith’s religious hierarchy. (Lawful)", "Faith; I trust that my deity will guide my actions. I have faith that if I work hard, things will go well. (Lawful)", "Aspiration; I seek to prove myself worthy of my god’s favor by matching my actions against his or her teachings. (Any)"};
string acolyte_flaw[6] = {"I judge others harshly, myself even more severely.", "Those who wield power within my temple's hierarchy, I put too much trust in them.", "My piety sometimes leads me to blindly believe those which profess faith in my god.", "I am inflexible in my thinking.", "I am suspicious of strangers and I also expect the worst of them.", "Once I pick a goal, I become obsessed with it to the detriment of everything else in my life."};
string acolyte_bonds[6] = {"I would die to recover an ancient relic of my faith that was lost long ago.", "Some day i will get revenge on the corrupt temple hierarchy who branded me a heretic.", "I owe my life to he priest who ever took me in when my parents has died.", "Everything I do is only for the common people.", "I will do anything to protect the temple where ever I served", "I seek to preserve a sacred text which my enemies consider heretical and seek to destroy."};

//Charlaton
string charlatan_personality[8] = {"I fall in and out of love easily, and am always pursuing someone.", "I have a joke for every occasion, especially occasions where humor is inappropriate.", "Flattery is my preferred trick for getting what I want.", "I'm a born gambler who can't resist taking a risk for a potential payoff.", "I lie about almost everything, even when there's no good reason to.", "Sarcasm and insults are my weapons of choice.", "I keep multiple holy symbols on me and invoke whatever deity might come in useful at any given moment.", "I pocket anything I see that might have some value."};
string charlatan_ideals[6] = {"Independence. I am a free spirit – no one tells me what to do. (Chaotic)", "Fairness. I never target people who can't afford to lose a few coins. (Lawful)", "Charity. I distribute the money I acquire to the people who really need it. (Good)", "Creativity. I never run the same con twice. (Chaotic)", "Friendship. Material goods come and go. Bonds of friendship last forever. (Good)", "Aspiration. I'm determined to make something of myself. (Any)"};
string charlatan_flaws[6] = {"I can't resist a pretty face.", "I'm always in debt. I spend my ill-gotten gains on decadent luxuries faster than I bring them in.", "I'm convinced that no one could ever fool me the way I fool others.", "I'm too greedy for my own good. I can't resist taking a risk if there's money involved.", "I can't resist swindling people who are more powerful than me.", "I hate to admit it and will hate myself for it, but I'll run and preserve my own hide if the going gets tough."};
string charlatan_bonds[6] = {"I fleeced the wrong person and must work to ensure that this individual never crosses paths with me or those I care about.", "I owe everything to my mentor – a horrible person who's probably rotting in jail somewhere.", "Somewhere out there, I have a child who doesn't know me. I'm making the world better for him or her.", "I come from a noble family, and one day I'll reclaim my lands and title from those who stole them from me.", "A powerful person killed someone I love. Some day soon, I'll have my revenge.", "I swindled and ruined a person who didn't deserve it. I seek to atone for my misdeeds but might never be able to forgive myself."};

//Criminal
string criminal_personality[8] = {"I always have a plan for what to do when things go wrong.", "I am always calm, no matter what the situation. I never raise my voice or let my emotions control me.", "The first thing I do in a new place is note the locations of everything valuable-or where such things could be hidden.", "I would rather make a new friend than a new enemy.", "I am incredibly slow to trust. Those who seem the fairest often have the most to hide.", "I don't pay attention to the risks in a situation. Never tell me the odds.", "The best way to get me to do something is to tell me I can't do it.", "I blow up at the slightest insult."};
string criminal_ideals[6] = {"Honor. I don’t steal from others in the trade. (Lawful)", "Freedom. Chains are meant to be broken, as are those who would forge them. (Chaotic)", "Charity. I steal from the wealthy so that I can help people in need. (Good)", "Greed. I will do whatever it takes to become wealthy. (Evil)", "People. I’m loyal to my friends, not to any ideals, and everyone else can take a trip down the Styx for all I care. (Neutral)", "Redemption. There’s a spark of good in everyone. (Good)"};
string criminal_flaws[6] = {"When I see something valuable, I can’t think about anything but how to steal it.", "When faced with a choice between money and my friends, I usually choose the money.", "If there’s a plan, I’ll forget it. If I don’t forget it, I’ll ignore it.", "I have a “tell” that reveals when I'm lying.", "I turn tail and run when things look bad.", "An innocent person is in prison for a crime that I committed. I’m okay with that."};
string criminal_bonds[6] = {"I’m trying to pay off an old debt I owe to a generous benefactor.", "My ill-gotten gains go to support my family.", "Something important was taken from me, and I aim to steal it back.", "I will become the greatest thief that ever lived.", "I’m guilty of a terrible crime. I hope I can redeem myself for it.", "Someone I loved died because of a mistake I made. That will never happen again."};

//Entertainer
string entertainer_personality[8] = {"I know a story relevant to almost every situation.", "Whenever I come to a new place, I collect local rumors and spread gossip.", "I'm a hopeless romantic, always searching for that 'special someone.'","Nobody stays angry at me or around me for long, since I can defuse any amount of tension.", "I love a good insult, even one directed at me.", "I get bitter if I'm not the center of attention.", "I'll settle for nothing less than perfection.", "I change my mood or my mind as quickly as I change key in a song.",};
string entertainer_ideals[6] = {"Beauty. When I perform, I make the world better than it was. (Good)", "Tradition. The stories, legends, and songs of the past must never be forgotten, for they teach us who we are. (Lawful)", "Creativity. The world is in need of new ideas and bold action. (Chaotic)", "Greed. I'm only in it for the money and fame. (Evil)", "People. I like seeing the smiles on people's faces when I perform. That's all that matters. (Neutral)", "Honesty. Art should reflect the soul; it should come from within and reveal who we really are. (Any)"};
string entertainer_flaws[6] = {"I'll do anything to win fame and renown.", "I'm a sucker for a pretty face.", "A scandal prevents me from ever going home again. That kind of trouble seems to follow me around.", "I once satirized a noble who still wants my head. It was a mistake that I will likely repeat.", "I have trouble keeping my true feelings hidden. My sharp tongue lands me in trouble.", "Despite my best efforts, I am unreliable to my friends."};
string entertainer_bonds[6] = {"My instrument is my most treasured possession, and it reminds me of someone I love.", "Someone stole my precious instrument, and someday I'll get it back.", "I want to be famous, whatever it takes.", 
"I idolize a hero of the old tales and measure my deeds against that person's.", "I will do anything to prove myself superior to my hated rival.", "I would do anything for the other members of my old troupe."};

//Folk Hero
string folkhero_personality[8] = {"I do judge people by their actions, not their words.", "If someone is in trouble, I’m always ready to lend help.", "When I set my mind to something, I follow through no matter what gets in my way.", "I do have a strong sense of fair play and always try to find the most equitable solution to arguments.", "I’m confident in my own abilities and do what I can to instill confidence in others.", "Thinking is for other people. I prefer action.", "I misuse long words in an attempt to sound smarter.", "I get bored easily. When am I going to get on with my destiny?"};
string folkhero_ideals[6] = {"Respect: People deserve to be treated with dignity and respect. (Good)", "Fairness: No one should get preferential treatment before the law, and no one is above the law. (Lawful)", "Freedom: Tyrants must not be allowed to oppress the people. (Chaotic)", "Might: If I become strong, I can take what I want—what I deserve. (Evil)", "Sincerity: There’s no good in pretending to be something I’m not. (Neutral)", "Destiny: Nothing and no one can steer me away from my higher calling. (Any)"};
string folkhero_flaws[6] = {"The tyrant who rules my land will stop at nothing to see me killed.", "I’m convinced of the significance of my destiny, and blind to my shortcomings and the risk of failure.", "The people who knew me when I was young know my shameful secret, so I can never go home again.", "I have a weakness for the vices of the city, especially hard drink.", "Secretly, I believe that things would be better if I were a tyrant lording over the land.", "I have trouble trusting in my allies."};
string folkhero_bonds[6] = {"I have a family, but I have no idea where they are. One day, I hope to see them again.", "I worked the land, I love the land, and I will protect the land.", "A proud noble once gave me a horrible beating, and I will take my revenge on any bully I encounter.", "My tools are symbols of my past life, and I carry them so that I will never forget my roots.", "I protect those who cannot protect themselves.", "I wish my childhood sweetheart had come with me to pursue my destiny."};

//Guild_Artisan
string guild_artisan_personality[8] = {"I believe that anything worth doing is worth doing right. I can't help it – I'm a perfectionist.", "I'm a snob who looks down on those who can't appreciate fine art.", "I always want to know how things work and what makes people tick.", "I'm full of witty aphorisms and have a proverb for every occasion.", "I'm rude to people who lack my commitment to hard work and fair play.", "I like to talk at length about my profession.", "I don't part with my money easily and will haggle tirelessly to get the best deal possible.", "I'm well known for my work, and I want to make sure everyone appreciates it. I'm always taken aback when people haven't heard of me."};
string guild_artisan_ideals[6] = {"Community. It is the duty of all civilized people to strengthen the bonds of community and the security of civilization. (Lawful)", "Generosity. My talents were given to me so that I could use them to benefit the world. (Good)", "Freedom. Everyone should be free to pursue his or her own livelihood. (Chaotic)", "Greed. I'm only in it for the money. (Evil)", "People. I'm committed to the people I care about, not to ideals. (Neutral)", "Aspiration. I work hard to be the best there is at my craft."};
string guild_artisan_flaws[6] = {"I'll do anything to get my hands on something rare or priceless.", "I'm quick to assume that someone is trying to cheat me.", "No one must ever learn that I once stole money from guild coffers.", "I'm never satisfied with what I have – I always want more.", "I would kill to acquire a noble title.", "I'm horribly jealous of anyone who can outshine my handiwork. Everywhere I go, I'm surrounded by rivals."};
string guild_artisan_bonds[6] = {"The workshop where I learned my trade is the most important place in the world to me.", "I created a great work for someone, and then found them unworthy to receive it. I'm still looking for someone worthy.", "I owe my guild a great debt for forging me into the person I am today.", "I pursue wealth to secure someone's love.", "One day I will return to my guild and prove that I am the greatest artisan of them all.", "I will get revenge on the evil forces that destroyed my place of business and ruined my livelihood."};

//Sailor
string sailor_personality[8] = {"My friends know they can rely on me, no matter what.", "I work hard so that I can play hard when the work is done.", "I enjoy sailing into new ports and making new friends over a flagon of ale.", "I stretch the truth for the sake of a good story.", "To me, a tavern brawl is a nice way to get to know a new city.", "I never pass up a friendly wager.", "My language is as foul as an otyugh nest.", "I like a job well done, especially if I can convince someone else to do it."};
string sailor_ideals[6] = {"Respect. The thing that keeps a ship together is mutual respect between captain and crew. (Good)", "Fairness. We all do the work, so we all share in the rewards. (Lawful)", "Freedom. The sea is freedom-the freedom to go anywhere and do anything. (Chaotic)", "Mastery. I'm a predator, and the other ships on the sea are my prey. (Evil)", "People. I'm committed to my crewmates, not to ideals. (Neutral)", "Aspiration. Someday I'll own my own ship and chart my own destiny. (Any)"};
string sailor_flaws[6] = {"I follow orders, even if I think they're wrong.", "I'll say anything to avoid having to do extra work.", "Once someone questions my courage, I never back down no matter how dangerous the situation.", "Once I start drinking, it's hard for me to stop.", "I can't help but pocket loose coins and other trinkets I come across.", "My pride will probably lead to my destruction."};
string sailor_bonds[6] = {"I'm loyal to my captain first, everything else second.", "The ship is most important – crewmates and captains come and go.", "I'll always remember my first ship.", "In a harbor town, I have a paramour whose eyes nearly stole me from the sea.", "I was cheated out of my fair share of the profits, and I want to get my due.", "Ruthless pirates murdered my captain and crewmates, plundered our ship, and left me to die. Vengeance will be mine."};

//Hermit
string hermit_personality[8] = {"I have been isolated for so long that i speak rarely, preferring gestures and also the occasional grunt", "I am utterly serene, even in the face of disaster.", "The leader of my community had something wise to say on every topic, and I am eager to share that wisdom.", "I feel tremendous empathy for all who suffer.", "I’m oblivious to etiquette and social expectations.", "I connect everything that happens to me to a grand, cosmic plan.", "I often get lost in my own thoughts and contemplation, becoming oblivious to my surroundings.", "I am working on a grand philosophical theory and love sharing my ideas."};
string hermit_ideals[6] = {"Greater Good. My gifts are meant to be shared with all, not used for my own benefit. (Good)", "Logic. Emotions must not cloud our sense of what is right and true, or our logical thinking. (Lawful)", "Free Thinking. Inquiry and curiosity are the pillars of progress. (Chaotic)", "Power. Solitude and contemplation are paths toward mystical or magical power. (Evil)", "Live and Let Live. Meddling in the affairs of others only causes trouble. (Neutral)", "Self-Knowledge. If you know yourself, there’s nothing left to know. (Any)"};
string hermit_flaws[6] = {"Now that I've returned to the world, I enjoy its delights a little too much", "I harbor dark, bloodthirsty thoughts that my isolation and meditation failed to quell.", "I am dogmatic in my thoughts and philosophy.", "I let my need to win arguments overshadow friendships and harmony.", "I’d risk too much to uncover a lost bit of knowledge.", "I like keeping secrets and won’t share them with anyone."};
string hermit_bonds[6] = {"Nothing is more important than the other members of my hermitage, order, or association.", "I entered seclusion to hide from the ones who might still be hunting me. I must someday confront them.", "I’m still seeking the enlightenment I pursued in my seclusion, and it still eludes me.", "I entered seclusion because I loved someone I could not have.", "Should my discovery come to light, it could bring ruin to the world.", "My isolation gave me great insight into a great evil that only I can destroy."};

//Noble
string noble_personality[8] = {"My eloquent flattery makes everyone I talk to feel like the most wonderful and important person in the world.", "The common folk love me for my kindness and generosity.", "No one could doubt by looking at my regal bearing that I am a cut above the unwashed masses.", "I take great pains to always look my best and follow the latest fashions.", "I don’t like to get my hands dirty, and I won’t be caught dead in unsuitable accommodations.", "Despite my noble birth, I do not place myself above other folk. We all have the same blood.", "My favor, once lost, is lost forever.", "If you do me an injury, I will crush you, ruin your name, and salt your fields."};
string noble_ideals[6] = {"Respect: Respect is due to me because of my position, but all people regardless of station deserve to be treated with dignity. (Good)", "Responsibility: It is my duty to respect the authority of those above me, just as those below me must respect mine. (Lawful)", "Independence: I must prove that I can handle myself without the coddling of my family. (Chaotic)", "Power: If I can attain more power, no one will tell me what to do. (Evil)", "Family: Blood runs thicker than water. (Any)", "Noble Obligation: It is my duty to protect and care for the people beneath me. (Good)"};
string noble_flaws[6] = {"I secretly believe that everyone is beneath me.", "I hide a truly scandalous secret that could ruin my family forever.", "I too often hear veiled insults and threats in every word addressed to me, and I’m quick to anger.", "I have an insatiable desire for carnal pleasures.", "In fact, the world does revolve around me.", "By my words and actions, I often bring shame to my family."};
string noble_bonds[6] = {"I will face any challenge to win the approval of my family.", "My house’s alliance with another noble family must be sustained at all costs.", "Nothing is more important than the other members of my family.", "I am in love with the heir of a family that my family despises.", "My loyalty to my sovereign is unwavering.", "The common folk must see me as a hero of the people."};

//Outlander
string outlander_personality[8] = {"I’m driven by a wanderlust that led me away from home.", "I watch over my friends as if they were a litter of newborn pups.", "I once ran twenty-five miles without stopping to warn to my clan of an approaching orc horde. I’d do it again if I had to.", "I have a lesson for every situation, drawn from observing nature.", "I place no stock in wealthy or well-mannered folk. Money and manners won’t save you from a hungry owlbear.", "I’m always picking things up, absently fiddling with them, and sometimes accidentally breaking them.", "I feel far more comfortable around animals than people.", "I was, in fact, raised by wolves."};
string outlander_ideals[6] = {"Change. Life is like the seasons, in constant change, and we must change with it. (Chaotic)", "Greater Good. It is each person’s responsibility to make the most happiness for the whole tribe. (Good)", "Honor. If I dishonor myself, I dishonor my whole clan. (Lawful)", "Might. The strongest are meant to rule. (Evil)", "Nature. The natural world is more important than all the constructs of civilization. (Neutral)", "Glory. I must earn glory in battle, for myself and my clan. (Any)"};
string outlander_flaws[6] = {"I am too enamored of ale, wine, and other intoxicants.", "There’s no room for caution in a life lived to the fullest.", "I remember every insult I’ve received and nurse a silent resentment toward anyone who’s ever wronged me.", "I am slow to trust members of other races, tribes, and societies.", "Violence is my answer to almost any challenge.", "Don’t expect me to save those who can’t save themselves. It is nature’s way that the strong thrive and the weak perish."};
string outlander_bonds[6] = {"My family, clan, or tribe is the most important thing in my life, even when they are far from me.", "An injury to the unspoiled wilderness of my home is an injury to me.", "I will bring terrible wrath down on the evildoers who destroyed my homeland.", "I am the last of my tribe, and it is up to me to ensure their names enter legend.", "I suffer awful visions of a coming disaster and will do anything to prevent it.", "It is my duty to provide children to sustain my tribe."};

//Sage
string sage_personality[8] = {"I use polysyllabic words that convey the impression of great erudition.", "I've read every book in the world’s greatest libraries—or I like to boast that I have.", "I'm used to helping out those who aren’t as smart as I am, and I patiently explain anything and everything to others.", "There’s nothing I like more than a good mystery.", "I’m willing to listen to every side of an argument before I make my own judgment.", "I... speak... slowly... when talking... to idiots... which... almost... everyone... is... compared... to me.", "I am horribly, horribly awkward in social situations.", "I’m convinced that people are always trying to steal my secrets."};
string sage_ideals[6] = {"Knowledge. The path to power and self-improvement is through knowledge. (Neutral)", "Beauty. What is beautiful points us beyond itself toward what is true. (Good)", "Logic. Emotions must not cloud our logical thinking. (Lawful)", "No Limits. Nothing should fetter the infinite possibility inherent in all existence. (Chaotic)", "Power. Knowledge is the path to power and domination. (Evil)", "Self-Improvement. The goal of a life of study is the betterment of oneself. (Any)"};
string sage_flaws[6] = {"I am easily distracted by the promise of information.", "Most people scream and run when they see a demon. I stop and take notes on its anatomy.", "Unlocking an ancient mystery is worth the price of a civilization.", "I overlook obvious solutions in favor of complicated ones.", "I speak without really thinking through my words, invariably insulting others.", "I can’t keep a secret to save my life, or anyone else’s."};
string sage_bonds[6] = {"It is my duty to protect my students.", "I have an ancient text that holds terrible secrets that must not fall into the wrong hands.", "I work to preserve a library, university, scriptorium, or monastery.", "My life’s work is a series of tomes related to a specific field of lore.", "I've been searching my whole life for the answer to a certain question.", "I sold my soul for knowledge. I hope to do great deeds and win it back."};

//Soldier
string soldier_personality[8] = {"I am always polite and respectful.", "I am haunted by memories of war. I can't get the images of violence out of my mind.", "I have lost too many friends and i am slow to make a new one.", "I am full of inspiring and cautionary tales from my military experience which is relevant to almost every combat situation.", "I can stare down a hell hound without flinching.", "I enjoy being strong and i like breaking things.", "I have a crude sense of humor.", "I face problems head-on. A simple, direct solution is the best path to success."};
string soldier_ideals[6] = {"Greater Good. Our lot is to lay down our lives in defense of others. (Good)", "Responsibility. I do what I must and obey just authority. (Lawful)", "Independence. When people follow orders blindly, they embrace a kind of tyranny. (Chaotic)", "Might. In life as in war, the stronger force wins. (Evil)", "Live and Let Live. Ideals aren’t worth killing over or going to war for. (Neutral)", "Nation. My city, nation, or people are all that matter. (Any)"};
string soldier_flaws[6] = {"The monstrous enemy which we faced in battle still leaves me quivering with fear.", "I have little respect for anyone who is not a proven warrior.", "I made a terrible mistake in battle that cost many lives—and I would do anything to keep that mistake secret.", "My hatred of my enemies is blind and unreasoning.", "I obey the law, even if the law causes misery.", "I’d rather eat my armor than admit when I’m wrong."};
string soldier_bonds[6] = {"I would still lay down my life for the people I served with.", "Someone saved my life on the battlefield. To this day, I will never leave a friend behind.", "My honor is my life.", "I’ll never forget the crushing defeat my company suffered or the enemies who dealt it.", "Those who fight beside me are those worth dying for.", "I fight for those who cannot fight for themselves."};

//Urchin
string urchin_personality[8] = {"I hide scraps of food and trinkets away in my pockets.", "I ask a lot of questions.", "I like to squeeze into small places where no one else can get to me.", "I sleep with my back to a wall or tree, with everything I own wrapped in a bundle in my arms.", "I eat like a pig and have bad manners.", "I think anyone who's nice to me is hiding evil intent.", "I don't like to bathe.", "I bluntly say what other people are hinting at or hiding."};
string urchin_ideals[6] = {"Respect: All people, rich or poor, deserve respect. (Good)", "Community: We have to take care of each other, because no one else is going to do it. (Lawful)", "Change: The low are lifted up, and the high and mighty are brought down. Change is the nature of things. (Chaotic)", "Retribution: The rich need to be shown what life and death are like in the gutters. (Evil)", "People: I help the people who help me-that's what keeps us alive. (Neutral)", "Aspiration: I'm going to prove that I'm worthy of a better life. (Any)"};
string urchin_flaws[6] = {"If I'm outnumbered, I will run away from a fight.", "Gold seems like a lot of money to me, and I'll do just about anything for more of it.", "I will never fully trust anyone other than myself.", "I'd rather kill someone in their sleep then fight fair.", "It's not stealing if I need it more than someone else.", "People who can't take care of themselves get what they deserve."};
string urchin_bonds[6] = {"My town or city is my home, and I'll fight to defend it.", "I sponsor an orphanage to keep others from enduring what I was forced to endure.", "I owe my survival to another urchin who taught me to live on the streets.", "I owe a debt I can never repay to the person who took pity on me.", "I escaped my life of poverty by robbing an important person, and I'm wanted for it.", "No one else should have to endure the hardships I've been through."};

//CLASS FEATURES
string barbarian_features[2] = {"Rage", "Unarmored Defense"};
string bard_features[2] = {"Spellcasting", "Bardic Inspiration (d6)"};
string cleric_features[2] = {"Spellcasting", "Divine Domain"};
string druid_features[2] = {"Druidic", "Spellcasting"};
string fighter_features[2] = {"Fighting Style", "Second Wind"};
string monk_features[2] = {"Unarmored Defense", "Martial Arts"};
string paladin_features[2] = {"Divine Sense", "Lay on Hands (5 hp)"};
string ranger_features[2] = {"Favored Enemy", "Natural Explorer"};
string rogue_features[3] = {"Expertise (2)", "Thieve's Cant", "Sneak Attack (d6)"};
string sorcerer_features[2] = {"Spellcasting", "Sorcerous Origin"};
string warlock_features[2] = {"Pact Magic", "Otherworldly Patron"};
string wizard_features[2] = {"Spellcasting", "Arcane Recovery"};

//RACE FEATURES
string dwarf_features[6] = {"Size: Medium", "Darkvision", "Dwarven Resilience", "Dwarven Combat Training", "Stonecunning", "Subrace"}; //+2 Con. Proficiency in battle axe, handaxe, throwing hammer, warhammer. Tool proficiency in smith's tools, brewer's supplies, or mason's tools, language: Dwarvish
string elf_features[7] = {"Size: Medium", "Long Life", "Darkvision", "Keen Senses", "Fey Ancenstry", "Trance", "Subrace"}; //+2 Dex. Proficiency in perception. language: Elvish
string halfling_features[5] = {"Size: Small", "Lucky", "Brave", "Halfling Nimbleness", "Subrace"}; //+2 Dex. language: Halfling
string human_features[1] = {"Size: Medium"}; //+1 in all abilities. language: choose one
string dragonborn_features[5] = {"Size: Medium", "Draconic Ancestry", "Breath Weapon", "Damage Resistance"}; //+2 Str. +1 Cha. language: Draconic
string gnome_featuers[4] = {"Size: Small", "Darkvision", "Gnome Cunning", "Subrace"}; //+2 Int. language: gnomish
string half_elf_features[3] = {"Size: Medium", "Darkvision", "Fey Ancestry"}; //+2 Cha, +1 in 2 other abilites, 2 random skills, lancauge: Elvish, one other language
string half_orc_features[4] = {"Size: Medium", "Darvision", "Relentless Endurance", "Savage Attacks"}; //+2 Str. +1 Con. Intimidation skill. language: orc
string tiefling_features[4] = {"Size: Medium", "Darkvision", "Hellish Resistance", "Infernal Legacy"}; //+1 Int. +2 Cha. Thaumaturgy cantrip. language: infernal


//BACKGROUND FEATURES
string acolyte_features[1] = {"Shelter the Faithful"};
string charlatan_features[2] = {"Favorite Scheme", "False Identity"};
string criminal_features[2] = {"Criminal Specialty", "Criminal Contact"};
string entertainer_features[2] = {"Entertainer Routine", "By Popular Demand"};
string folkhero_features[2] = {"Defining Event", "Rustic Hospitality"};
string guildartisan_features[2] = {"Guild Business", "Guild Membership"};
string hermit_features[2] = {"Life of Seclusion", "Discovery"};
string noble_features[1] = {"Position of Privilege"};
string outlander_features[2] = {"Origin", "Wanderer"};
string sailor_features[1] = {"Ship's Passage"};
string sage_features[2] = {"Specialty", "Researcher"};
string soldier_features[2] = {"Specialty", "Military Rank"};
string urchin_features[1] = {"City Secrets"};

//CLASS PROFICIENCIES
string barabarian_profs[5] = {"Light armor", "Medium armor", "Shields", "Simple weapons", "Martial weapons"};
string bard_profs[6] = {"Light armor", "Simple weapons", "Hand crossbows", "Longswords", "Rapiers", "Shortswords"}; //+3 instruments
string cleric_profs[4] = {"Light armor", "Medium armor", "Shields", "Simple weapons"};
string druid_profs[14] = {"Light armor", "Medium armor", "Shields", "Clubs", "Daggers", "Darts", "Javelins", "Maces", "Quarterstaffs", "Scimitars", "Sickles", "Slings", "Spears", "Herbalism kit"};
string fighter_profs[6] = {"Light armor", "Medium armor", "Heavy armor", "Shields", "Simple weapons", "Martial weapons"};
string monk_profs[2] = {"Simple weapons", "Shortswords"}; //+2 tools or +1 instrument
string paladin_profs[6] = {"Light armor", "Medium armor", "Heavy armor", "Shields", "Simple weapons", "Martial weapons"};
string ranger_profs[6] = {"Light armor", "Medium armor", "Shields", "Simple weapons", "Martial weapons"};
string rogue_profs[7] = {"Light armor", "Simple weapons", "Hand crossbows", "Longswords", "Rapiers", "Shortswords", "Thieve's tools"};
string sorcerer_profs[5] = {"Daggers", "Darts", "Quarterstaffs", "Slings", "Light crossbows"};
string warlock_profs[2] = {"Light armor", "Simple weapons"};
string wizard_profs[5] = {"Daggers", "Darts", "Quarterstaffs", "Slings", "Light crossbows"};

//BACKGROUND PROFICIENCIES
//acolyte: +2 language
string charlatan_profs[2] = {"Disguise kit", "Forgery kit"};
string criminal_profs[1] = {"Thieve's tools"}; //+1 gaming set
string entertainer_profs[1] = {"Disguise kit"}; //+1 instrument
string folkhero_profs[1] = {"Land vehicles"}; //+1 toolkit
//guild artisan: +1 toolkit, +1 language
string hermit_profs[1] = {"Herbalism kit"}; //+1 language
//noble: +1 language, +1 gaming set
//outlander: +1 language, +1 toolkit
//sage: +2 languages
string sailor_profs[2] = {"Water vehicles", "Navigator's tools"};
string soldier_profs[1] = {"Land vehicles"}; //+1 gaming set
string urchin_profs[2] = {"Disguise kit", "Thieve's tools"};

//CLASS SKILLS
string barbarian_skills[6] = {"Animal Handling", "Athletics", "Intimidation", "Nature", "Perception", "Survival"}; //2 skills
string bard_skills[18] = {"Acrobatics", "Animal Handling", "Arcana", "Athletics", "Deception", "History", "Insight", "Intimidation", "Investigation", "Medicine", "Nature", "Perception", "Performance", "Persuasion", "Religion", "Sleight of Hand", "Stealth", "Survival"};
string cleric_skills[5] = {"History", "Insight", "Medicine", "Persuasion", "Religion"};
string druid_skills[8] = {"Animal Handling", "Arcana", "Insight", "Medicine", "Nature", "Perception", "Religion", "Survival"};
string fighter_skills[8] = {"Acrobatics", "Animal Handling", "Athletics", "History", "Insight", "Intimidation", "Perception", "Survival"};
string monk_skills[7] = {"Acrobatics", "Athletics", "Deception", "History", "Insight", "Religion", "Stealth"};
string paladin_skills[6] = {"Athletics", "Insight", "Intimidation", "Medicine", "Persuasion", "Religion"};
string ranger_skills[8] = {"Animal Handling", "Athletics", "Insight", "Investigation", "Nature", "Perception", "Stealth", "Survival"};
string rogue_skills[12] = {"Acrobatics", "Athletics", "Deception", "History", "Insight", "Intimidation", "Investigation", "Perception", "Performance", "Persuasion", "Sleight of Hand", "Stealth"};
string sorcerer_skills[6] = {"Arcana", "Deception", "Insight", "Intimidation", "Persuasion", "Religion"};
string warlock_skills[6] = {"Arcana", "Deception", "History", "Intimidation", "Investigation", "Nature"};
string wizard_skills[7] = {"Arcana", "History", "Insight", "Intimidation", "Investigation", "Medicine", "Religion"};

//BACKGROUND SKILLS
string acolyte_skills[2] = {"Insight", "Religion"};
string charlatan_skills[2] = {"Deception", "Sleight of Hand"};
string criminal_skills[2] = {"Deception", "Stealth"};
string entertainer_skills[2] = {"Acrobatics", "Performance"};
string folkhero_skills[2] = {"Animal Handling", "Survival"};
string guildartisan_skills[2] = {"Insight", "Persuasion"};
string hermit_skills[2] = {"Medicine", "Religion"};
string noble_skills[2] = {"History", "Persuasion"};
string outlander_skills[2] = {"Athletics", "Survival"};
string sage_skills[2] = {"Arcana", "History"};
string sailor_skills[2] = {"Athletics", "Perception"};
string soldier_skills[2] = {"Athletics", "Intimidation"};
string urchin_skills[2] = {"Sleight of Hand", "Stealth"};

//BACKGROUND EQUIPMENT
string acolyte_equip[5] = {"x1 Holy symbol", "x1 Prayer book/wheel", "x5 Sticks incense", "x1 Vestment", "x1 Set of common clothes"}; //15GP
string charlatan_equip[3] = {"x1 Set of fine clothes", "x1 Disguise kit", "Tools for a specific con"}; //15GP
string criminal_equip[2] = {"x1 Crowbar", "x1 Set of dark common clothes"}; //15GP
string entertainer_equip[3] = {"x1 Instrument", "x1 Favor of an admirer", "x1 Costume"}; //15 GP
string folkhero_equip[4] = {"x1 Set of tools", "x1 Shovel", "x1 Iron pot", "x1 Set of common clothes"}; //10GP
string guildartisan_equip[3] = {"x1 Set of tools", "x1 Letter of introduction", "x1 Set of traveler's clothes"}; //15 GP
string hermit_equip[4] = {"x1 Scroll case of notes", "x1 Winter blanket", "x1 Set of common clothes", "x1 Herbalism kit"}; //5 GP
string noble_equip[3] = {"x1 Set of fine clothes", "x1 Signet ring", "x1 Scroll of pedigree"}; //25 GP
string outlander_equip[4] = {"x1 Staff", "x1 Hunting trap", "x1 Trophy from an animal", "x1 Set of traveler's clothes"}; //10 GP
string sage_equip[5] = {"x1 Bottle of ink", "x1 Quill", "x1 Small knife", "x1 Letter from a dead colleague", "x1 Set of common clothes"}; //10 GP
string sailor_equip[4] = {"x1 Belaying pin", "x1 50ft silk rope", "x1 Lucky charm", "x1 Set of common clothes"}; //10 GP
string soldier_equip[4] = {"x1 Insignia of rank", "x1 Trophy from an enemy", "x1 Gaming set", "x1 Set of common clothes"}; //10 GP
string urchin_equip[5] = {"x1 Small knife", "x1 Map of your home city", "x1 Pet mouse", "x1 Token to remember your parents by", "x1 Set of common clothes"}; //10 GP

//WEAPONS 
string martial_weapons[23] = {"Battleaxe", "Flail", "Glaive", "Greataxe", "Greatsword", "Halberd", "Lance", "Longsword", "Maul", "Morningstar", "Pike", "Rapier", "Scimitar", "Shortsword", "Trident", "War Pick", "Warhammer", "Whip", "Blowgun", "Crossbow(hand)", "Crossbow(heavy)", "Longbow", "Net"};//range starts at 19

string simple_weapons[14] = {"Club", "Dagger", "Greatclub", "Handaxe", "Javelin", "Light Hammer", "Mace", "Quarterstaff", "Sickle", "Spear", "Light Crossbow", "Dart", "Shortbow", "Sling"}; //Ranged weapons start at crossbow [10]

//TRINKETS AND TOOLS
string instruments[10] = {"Bagpipes", "Drum", "Dulcimer", "Flute", "Lute", "Lyre", "Horn", "Pan flute", "Shawm", "Viol"};
string toolkits[17] = {"Alchemist's supplies", "Brewer's supplies", "Calligrapher's supplies", "Carpenter's tools", "Cartographer's tools", "Cobbler's tools", "Cook's utensils", "Glassblower's tools", "Jeweler's tools", "Leatherworker's tools", "Mason's tools", "Painter's supplies", "Potter's tools", "Smith's tools", "Tinker's tools", "Weaver's tools", "Woodcarver's tools"};
string gamesets[3] = {"Dice set", "Playing cards set", "Dragonchess Set"};
string languages[18] = {"Dwarvish", "Elvish", "Giant", "Halfling", "Gnomish", "Orc", "Goblin", "Abyssal", "Celestial", "Deep Speech", "Draconic", "Infernal", "Auran", "Sylvan", "Undercommon", "Aquan", "Ignan", "Terran"}; //common is assumed
string trinkets[50] = {"Mummified Goblin Hand", "Piece of Crystal that faintly glows in moonlight", "A gold coin minted in an unknown land", "A diary written in a language you don't know", "A brass ring that never tarnishes", "Chess piece made from glass", "A pair of knucklebone dice, with skulls on the 6th side", "Small idol depicting a nightmarish creature that gives you nightmares when you sleep near it", "A rope necklace from which dangles four mummified elf fingers", "The deed for a parcel of land in an unknown realm", "A 1-Ounce block of unknown material", "A small cloth doll skewered with needles", "A tooth from an unknown beast", "An enormous scale, perhaps from a dragon", "A bright green feather", "An old divination card bearing your likeness", "A glass orb filled with moving smoke", "A 1-pound egg with a bright red shell", "A pipe that blows bubbles", "A glass jar containing a chunk of flesh in pickling fluid", "A tiny gnome-crafted music box that plays a song you dimly remember", "An adamantine toothpick", "A bag containing forty-seven humanoid teeth, one of which is rotten", "A gold doublon minted with a pirate's crest", "A shard of obsidian that always feels warm to the touchA bright feather that smells vaguely of honey", "A scrap of red cloth with a slight magic aura", "A white gem that is always cold to the touch", "Several pages of a diary written in Old Omuon", "A large bird feather that seems to dance as it falls", "A tiny, spiral horn", "A fist-sized turlte shell plate with a sun carved on it", "A handful of withered petals from a pitch-black flower", "The flag from a pirate ship sunk long ago", "A small bag of crushed ryath root", "The mummified hand of a monkey", "A small knife with your name on it", "A small, weightless stone block", "A metal can with no opening, but sounds as if it is filled with sand", "A tiny silver bell", "The walking stick of an old vampire", "A scrap of cloth from an old banner", "A gemstone that looks like a lump of coal to anyone other than you", "A blank books whose pages refuse to hold ink, chalk, graphite, or any other marking", "A vest with 100 tiny pockets", "A rank insignia from a lost legionnaire", "A silver spoon with the letter M engraved on the handle", "A mechanical canary inside a gnomish lamp", "A glass orb filled with water, where a clockwork goldfish swims", "A dead sprite in a clear glass bottle", "A sketch portrait of a goblin"};

//BACKSTORY DETAILS
string parent_status[8] = {"Married", "Divorced", "Single Father", "Unknown Parents", "One Dead", "Both Dead", "Single Mother", "Divorced and Remarried"};
string home[11] = {"On the Streets", "Rundown Shack", "No Permanent Residence", "Wilderness Camp", "Rundown Apartment", "Small House", "Large House", "Mansion", "Palace/Castle", "On the Run", "Orphanage"};
string wealth[8] = {"Wretched", "Squalid", "Poor", "Modest", "Comfortable", "Wealthy", "Aristocrat", "Royalty"};
string life_events[46] = {"You fell in love or got married", "You had a child", "You went on a small adventure", "You fought in a war", "You committed a crime but weren't caught", "You committed a crime and were caught", "You were wrongly convicted of a crime", "You were possessed", "You witnessed a miracle", "You saw a ghost", "You had a vision of the future", "You travelled to the feywild", "A family member or close friend died", "You lost all of your posessions in a disaster", "You lived in a warzone", "You fell out of love", "You were exiled", "You were kidnapped", "You found a treasure map", "You nearly died", "You found or were given an important object", "You found a large sum of money", "You caught a plague", "You made an enemy", "You were permanently injured in an accident", "You You lost a sentimental item", "A family member died", "A wizard gave you a cantrip spell scroll", "You found a first level spell scroll", "You saved the life of a commoner, who now owes you", "You found a lost riding horse", "You made a very good friend", "You fought in a battle", "You met a very important person", "You were injured by the effect of a spell", "You saw a demon", "You were teleported away from your home one night", "You saw a ghost", "You had nightmares where a powerful being gave you warnings", "You did something that brought terrible shame to your family", "You were polymorphed for a short time", "You were petrified by a statue for a short time", "You met an extremely powerful being (demigod, archfey, archdevil, angel, demon lord, or titan)", "You drank a mysterious potion", "You discovered a lost island", "You entered an ancient tomb"};

//APPEARANCES
string gender[5] = {"Female", "Male", "Androgynous", "Agender", "Fluid"};
string hair_color[7] = {"Black", "Brunette", "Ginger/Red", "Blonde", "White", "Grey", "Dyed"};
string eye_color[12] = {"Dark Brown", "Light Brown", "Hazel", "Green", "Blue", "All White", "All Black", "Gold", "Silver", "Red", "Purple", "Grey"};
string height[5] = {"Very Tall", "Taller than Average", "Average", "Shorter than Average", "Very Short"};
string weight[7] = {"Overweight", "Average", "Average", "Average", "Underweight", "Heavier than Average", "Lighter than Average"};
