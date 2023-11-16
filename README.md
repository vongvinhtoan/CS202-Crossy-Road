# CS202 - Crossy Road Project

## How to build

1. Clone the repository
2. Download Make for Windows from [here](http://gnuwin32.sourceforge.net/packages/make.htm) (I used Copilot so I don't know if it works).
3. Run `make` in the root directory
4. Run `make run` or `.\bin\game.exe` to run the game

## How to create new Activity and View

1. Add the following path to your project:
    ```
    <derectory of project>\bin\helpers
    <derectory of project>\libs\SFML-2.5.1\bin
    ```
2. To create or delete:
   - Run `newact <ActivityIDName>` to create new Activity  
   - Run `newview <ViewIDName>` to create new View
   - Run `delact <ActivityIDName>` to delete Activity
   - Run `delview <ViewIDName>` to delete View