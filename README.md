# Labyrinth

### Team Members

- Timothee Wirasaputra Kurniawan (3035663069)
- Michael Wang (303566765)

### Game Description

“Labyrinth” is a game of pathfinding inspired by the mobile game [Amaze](https://play.google.com/store/apps/details?id=com.crazylabs.amaze.game&hl=en). The game’s objective is to cover all the available spaces by moving the character “Laby” within a certain move limitation. There will be multiple levels to beat each with different maps and move limitations. On every level, a heart will pop up in a random position on the map, which can help to complete each level.

### Game Rules

- Players can only choose from 4 moves, which are left, right, up, or down. “Laby” will move to the respective direction until it hits an obstruction or end of the map.
- Spaces traveled by Laby will be counted towards the travel count regardless if Laby has already covered the place before or not.
- If “Laby” exceeds the travel limitation, the player loses.
- A heart will be placed randomly on the map to reduce Laby’s travel count. The number of reduced travel count varies among the maps.

### Features

1. Generation of random game sets or events

   - Randomize position of a heart in each map

2. Data structures for storing game status

   - Linked list to store users
   - Struct to store users’ data (current level, current map (coverage), current travel limit)
   - Arrays to store current map

3. Dynamic memory management

   - Initializing new user before getting the data
   - Usage of linked list

4. File input/output (e.g., for loading/saving game status)

   - savefile.cereal (using cereal serialization library) → to save users data locally

5. Program codes in multiple files
   - main.cpp → the main program
   - play.cpp → function to play the game
   - laby.cpp → function to move laby
   - levels.cpp → store the empty maps of all levels
   - userStruct.cpp → declaration of User Struct
   - welcome.cpp → starting the game
   - congrats.cpp → finishing the game
