Group No.: 112
Group members: Chan Yan Yin, Li Po Yan
Topic: RNG adventure
  Generation of random game sets or events: Dungeon crawler where enemy and boss names and stats are randomly generated, as well as random loot and events
  Data structures for storing game status: structs
  Dynamic memory management: dynamic array sizes
  File input/output (e.g., for loading/saving game status): Save files
  Program codes in multiple files: different features e.g. event generation have their own cpp files
Link: https://github.com/Codenoob-lpy/Codenoob-lpy

Problem statement:
    This is a text-based adventure game and the player have to go into the infinite randomly generated dungeon as deep as possible.
    We chose this topic because the rng seed nature of the text game allows great flexibility over game content. We could utilize many things learnt within and outisde the course.
    This helps us build a game flow dependent on both luck and the decision-making of players.
    Setting: Compiled and run by Linux terminal
    Assumptions:
        The player does not modify the save files outside the game
        The player does not force quit the game
        The player does not save and quit the game when fighting monsters (intended to prevent cheating)

Basic game rules: 
    This is a text-based adventure game and the player have to go into the infinite dungeon as deep as possible.  
    Player needs to fight with monsters which will appear in the dungeon and boss monsters will appear every ten battles. There are some special events as well. Some of them may give the player blesses/curses and some of them may sell the player equipment. 
    Player has to make different decisions such as battling, using items during each battle to survive in the dungeon. Also, player can get rewards like coins, health and experience after every battle. 

Implemented features:
    1.Generation of random game sets or events
    The monsters and special events are all generated randomly.

    2.Data structures for storing game status
    The player's charater status will be stored in a struct.
    
    3.Dynamic memory management 
    Used in converting the save filename to c-string to operate deletion of save when the player dies.
    
    4.File input/output (e.g., for loading/saving game status)
    The current status of character are stored into a txt file, which is created upon new character. The user inputs the player name and the program will search the directory for the specific save. When the game is quit the game overwrites the elements in the struct into the txt.

    5.Program codes in multiple files
    The functions and main program are spearated into multiple cpp before compilation.

Compilation and execution instructions:
    1. Terminal command "make game" (tested in academy11)
    2. ./game
    3. Available commands are given ingame and stated explicitly, type "help" to see all available commands

References
    Types of monsters in the game are modified and adapted from Nethack
    (Monster names are all unique and random)
