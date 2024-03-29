# Labyrinth

### Team Members

- Timothee Wirasaputra Kurniawan (3035663069)
- Michael Wang (303566765)

### Game Description

“Labyrinth” is a game of pathfinding inspired by the mobile game [Amaze](https://play.google.com/store/apps/details?id=com.crazylabs.amaze.game&hl=en). The game’s objective is to cover all the available spaces by moving the character “Laby” within a certain move limit. There will be 10 total levels to beat, each with different maps and move limits. On every level, a heart will pop up in a random position on the map, when the character "Laby" passes by this heart, it will add the move limit, which can help to complete each level. If "Laby" passes by a heart, another heart will pop up immediately in a random position of the map. If users fail to cover all available spaces in the certain move limit, they lose the level and have the option of retrying it. Users can quit and save their game whenever they like.

### Game Rules

- Players can only choose from 4 moves, which are left, right, up, or down. “Laby” will move to the respective direction until it hits an obstruction or end of the map. Users enter W, A, S, or D either to move up, left, down, or right respectively.
- Each space travelled by Laby decreases the move limit of the current level.
- Spaces travelled by Laby will be counted towards the travel count regardless if "Laby" has already covered the place before or not (if Laby has visited a space previously, and Laby travels to that space again).
- If “Laby” exceeds the travel limit, the player loses.
- A heart will be placed randomly on the map to increase Laby’s moves remaining / move limit by 5. The number of moves remaining / move limit varies among levels.

### Features

1. Generation of random game sets or events

   - Randomize position of a heart in each map in each try
   - Randomize the starting position of "Laby" in each map in each try, each time a heart is passed by, it will generate a heart in a randomized position again

2. Data structures for storing game status

   - Struct to store users’ data (currentLevel -> current level of user, currentMap -> which spaces are covered and which are not, currentLimit -> moves remaining, and currentTravel -> how many spaces has "Laby" successfully covered)
   - Arrays to store current map
   - Arrays to store move limits of the map
   - Arrays to store how many spaces to be travelled of each map

3. Dynamic memory management

   - Initializing new user before getting the data

4. File input/output (e.g., for loading/saving game status)

   - username.txt --> storing the progress of player named "username", e.g. username is Bob, so Bob.txt (contains currentLevel, currentMap,currentLimit, and currentTravel)
   - usernameList.txt --> consist of all usernames.

5. Program codes in multiple files
   - main.cpp → the main program
   - play.cpp → functions to play the game
   - laby.cpp → functions to move laby
   - levels.cpp → functions to store and create maps of all 10 levels of the game
   - invalidSelection.cpp → function to detect if user's input is invalid
   - userStruct.cpp → declaration of User Struct
   - welcome.cpp → starting the game
   - congrats.cpp → finishing the game
 
 6. Compilation and execution instructions
    - Compilation :
      - cd src
      - make
    - Execution :
      - ./main


References:
   - Title Name → http://patorjk.com/software/taag/#p=display&f=Ogre&t=Labyrinth
   - Star Logo → https://ascii.co.uk/art/star



https://user-images.githubusercontent.com/61657963/150635934-7e766407-ba41-4d6c-bfaf-9d43b9d67a7f.mp4


