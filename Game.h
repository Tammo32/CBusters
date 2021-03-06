#include "Node.h"
#include "LinkedList.h"
#include <vector>
#include "Player.h"
#define NUM_PLAYERS 2
#define BOARD_SIZE 26

class game{
public:
    //constructor
    game();

    bool loadPreviousGame(std::string fileName);

    void startNewGame(std::string playerNames[]);

    //destructor
    ~game();

    //display game board
    void displayBoard();

    //save game
    void saveGame();
    
    //setup an empty gameboard
    void setupGameboard();

    //intilize tile bag
    void setupTileBag();

    //start gameplay loop.
    void gamePlayLoop();

    //sets the board size
    void setBoardSize(int size);

    //changes players turn
    void changePlayerTurn();

    //returns players turn
    int getPlayersTurn();

    //set players turn
    void setPlayersTurn(int i);

    //places a new tile on the gameboard
    void placeTile(std::string menuInput);

    void replaceTile(std::string menuInput);

    void score(int row, int col, char colour, int shape);

    //checks if row & col coordinates are valid
    bool withinBoard(int row, int col);

    //checks to see if tile exists in hand
    bool checkHand(char colour, int shape);

    //checks to see if the tile placement is valid
    bool checkPlacement(char colour, int shape, int row, int col);
    
    //checks the length of the line on the gameboard
    bool checkLineLength(int row, int col,  int dirRow, int dirCol, char colour, int shape);

    bool checkColour(char colour);

    bool checkShape(int shape);
    
    //for setting tile display colour - ENHANCEMENT
    void setDisplayColour(char colour);

    //for setting unicode symbols - ENHANCEMENT
    void setUnicodeSymbol(int shape);

    void enhancementToggles();

    bool colouredTilesEnabled();

    bool unicodeSymbolsEnabled();

    void helpOutput();

private:
    //LinkedList holding all game tiles not in hand/play.
    LinkedList* tileBag;

    //array of the the players.
    Player* playerArr[NUM_PLAYERS];

    //tracks player turns
    int turnTracker;

    //used to set board size
    int boardSize;

    //the gameboard
    std::vector<std::vector<Tile*>> map;

    //tracks toggles (use modulus for on/off)
    int colouredTilesTracker; 
    int unicodeSymbolsTracker; 
};