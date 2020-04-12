# Labyrinth

### Team Members

- Timothee Wirasaputra Kurniawan (3035663069)
- Michael Wang (303566765)

### Game Description

“Labyrinth” is a game of pathfinding inspired by the mobile game [Amaze](https://play.google.com/store/apps/details?id=com.crazylabs.amaze.game&hl=en). The game’s objective is to cover all the available spaces by moving the character “Laby” within a certain move currentLimitation. There will be multiple currentLevels to beat each with different maps and move currentLimitations. On every currentLevel, a heart will pop up in a random position on the map, which can help to complete each currentLevel.

### Game Rules

- Players can only choose from 4 moves, which are left, right, up, or down. “Laby” will move to the respective direction until it hits an obstruction or end of the map.
- Spaces traveled by Laby will be counted towards the travel count regardless if Laby has already covered the place before or not.
- If “Laby” exceeds the travel currentLimitation, the player loses.
- A heart will be placed randomly on the map to reduce Laby’s travel count. The number of reduced travel count varies among the maps.

### Features

1. Generation of random game sets or events

   - Randomize position of a heart in each map in each try
   - Randomize the starting position in each map in each try

2. Data structures for storing game status

   - Arrays to store users
   - Struct to store users’ data (current currentLevel, current map (coverage), current travel currentLimit, position of apple, apple existance)
   - Arrays to store current map

3. Dynamic memory management

   - Initializing new user before getting the data

4. File input/output (e.g., for loading/saving game status)

   - users --> a folder that consist of all [username].txt that holds the users data
   - usernameList.txt --> consist of all usernames.

5. Program codes in multiple files
   - main.cpp → the main program
   - play.cpp → function to play the game
   - laby.cpp → function to move laby
   - currentLevels.cpp → store the empty maps of all currentLevels
   - userStruct.cpp → declaration of User Struct
   - welcome.cpp → starting the game
   - congrats.cpp → finishing the game
