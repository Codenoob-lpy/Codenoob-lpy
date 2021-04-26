#include "functions.h"

monster monster_spawner(int turn, int rngoutput){
    srand(rngoutput);
    monster current;
    char vowel[] = {'a','e', 'i', 'o', 'u'};
    string types[] = { "Demogorgon", "Asmodeus", "Baalzebub", "Dispater", "Geryon", "Orcus", "Pestilence", "Famine", "Death", "Zombie Wizard ", "Yeenoghu", "lunatic priest", "Arch lunatic  Priest", "arch-lich", "Juiblex", "Archon", "mail daemon", "Medusa", " Thief", "Cyclops", "Norn", "Chromatic Dragon", "Nalzok", "Minion of Huhetotl", "kraken", "Croesus", "mastodon", "Shaman ", "Pelias", "Onion", "iron golem", "Ixoth", "ki-rin", "master lich", "balrog", "titan", "yellow dragon", "white dragon", "silver dragon", "red dragon", "orange dragon", "green dragon", "gray dragon", "blue dragon", "black dragon", "Master Assassin", "Dark One", "storm giant", "master mind flayer", "Impaler", "jabberwock", "glass golem", "demilich", "minotaur", "Scorpius", "purple worm", "Nazgul", "pit fiend", "Olog-hai", "guardian naga", "stone golem", "nalfeshnee", "baluchitherium", "sandestin", "aligned priest",  "vampire", "skeleton", "shadow", "ice devil", "hell hound", "zombie guard", "zombie captain", "prisoner", "trapper", "lich", "frost giant", "ettin", "Oracle", "bone devil", "baby yellow dragon", "baby white dragon", "baby silver dragon", "baby red dragon", "baby orange dragon", "baby green dragon", "baby gray dragon", "baby blue dragon", "baby black dragon", "titanothere", "mind flayer", "water troll", "zombie nurse", "golden naga", "vampire",  "hezrou", "clay golem", "fallen valkyrie", "zombie tourist", "zombie samurai", " zombie rogue", " zombie lieutenant", " zombie knight", "black pudding", " zombie barbarian", " zombie archeologist", "ghost", " zombie ranger", " zombie priestess", " zombie priest", " zombie healer", " zombie elf", " zombie cavewoman", " zombie caveman", "lurker above", "queen bee", "ice troll", "rock troll", "umber hulk", "salamander", "fire giant", " zombie monk", "Elvenking", "winged gargoyle", "ogre", "doppelganger", "zruty", "giant mimic", "water demon", "couatl", "vrock", "marilith", "xorn", " zombie elf-lord", "electric eel", "flesh golem", "barbed devil", "hill giant", "erinys", "fire vortex", "fire elemental", "black naga", "water elemental", "earth elemental", "air elemental", " zombie sergeant", "giant mummy", "cobra", "long worm", "horned devil", "wumpus", "steam vortex", "stalker", "large mimic", "giant zombie", "baby purple worm", "baby long worm", "shark", "glass piercer", "xan", "winter wolf", "hell hound pup", "energy vortex", "warhorse", "troll", "ogre lord", "sasquatch", "pit viper", "quantum mechanic", "mountain centaur", "green slime", "cockatrice", "stone giant", "giant",  "wraith", "wood golem", "warg", "small mimic", "ettin mummy", "shocking sphere", "freezing sphere", "flaming sphere", "ochre jelly", "dwarf king", "red naga", "python", "pyrolisk", "gargoyle",  " zombie soldier", " zombie Grey-elf", "leocrotta", "gelatinous cube", "carnivorous ape", "tiger", "rust monster", "guide", "apprentice", "acolyte", "scorpion", "abbot", "forest centaur", "gremlin", "giant eel", "chickatrice", "owlbear", "barrow wight", "tengu", "large dog", "large cat", "ice vortex", "leather golem", "human mummy", "ettin zombie", "elf mummy", "crocodile", "chameleon", "black light", "mumak", "undead warrior", "vampire bat", "thug", "roshi", "page", "orc-captain", "ninja", "winter wolf cub", "giant spider", "student", "ogre", "neanderthal", "hunter", "horse", " zombie Green-elf", "chieftain", "attendant", "yeti", "panther", "lynx", "werewolf", "water moccasin", "quasit", "iron piercer", "werewolf", "spotted jelly", "gnome king", "quivering blob", "wolf", "piranha", "orc mummy", "lizard", "gold golem", "giant beetle", "dwarf mummy", "brown pudding", "dust vortex", "white unicorn", "gray unicorn", "black unicorn", "dwarf lord", "plains centaur", "snake", "Woodland-elf", "raven", "Kop Kaptain", "rope golem", "jaguar", "ape", "soldier ant", "fire ant", "blue jelly", "crazy cat", "crazy dog", "dingo", "yellow light", "human zombie", "gnome mummy", "orc shaman", "gnomish wizard", "violet fungus", "jellyfish", "Uruk-hai", "Mordor orc",  "bugbear", "wood nymph", "water nymph", "mountain nymph", "lemure", "ghoul", "killer bee", "leprechaun", "fog cloud", "woodchuck", "rock mole", "imp", "gnome lord", "pony", "straw golem", "rock piercer", "red naga hatchling", "paper golem", "kobold mummy", "guardian naga hatchling", "gray ooze", "golden naga hatchling", "elf zombie", "black naga hatchling", "baby crocodile", "kobold shaman", "Kop Sergeant", "hill orc", "zombie dwarf", "giant ant", "centipede", "wererat", "werejackal", "rothe", "rabid rat", "monkey", "wererat", "werejackal", "kobold lord", "giant bat", "little dog", "kitten", "homunculus", "iguana", "floating eye", "dwarf zombie", "orc", "Keystone Kop", "hobgoblin", "gnome", "manes", "garter snake", "cave spider", "shrieker", "large kobold", "hobbit", "gas spore", "red mold", "green mold", "brown mold", "acid blob", "yellow mold", "gnome zombie", "giant rat", "gecko", "coyote",  "bat", "kobold", "goblin", "lichen", "fox", "sewer rat", "newt", "kobold zombie", "jackal", "grid bug" }; 
    int stringsize = rand() % 10 + 1;
    current.name = "";
    current.attack = 0;
    current.defense = 0;
    current.speed = 0; 
    current.health = 0;   
    
    for (int i = 0; i < stringsize; i++)
    {
        char x;
        if (i == 0)
        {
            x = 'A' + rand() % 26;    
        }
        
        else if (i % 3 == 0)
        {
            x = vowel[rand() % 4];    
        }
        
        else
        {
            x = 'a' + rand() % 26;    
        }       
        current.name += x;       
    }
    int index = rand() % 357;
    current.type = types[index];
     if ( turn % 10 == 0 && turn != 0 ){   // boss monster
        current.attack += 12 * (turn / 10);
        current.defense += (turn / 10) * 10;
        current.speed += 2 * (turn / 10);
        current.health += 120 * (turn / 10);
        
    } else {
        current.attack += (turn / 10) * 15 + turn % 10;
        current.defense += turn % 10;
        current.speed += turn+turn/10;
        current.health += turn / 10 * 30 + 10 + turn % 10; 
   }
    return current;
}