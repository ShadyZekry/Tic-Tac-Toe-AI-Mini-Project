#include <iostream>
#include "MyBoard.h"
#include "AI.h"

using namespace std;

MyBoard myBoard;        // First of all, I need to make this object to access this class
AI AIPlayer;
void myCredits();
void playAgain(bool *play);

void (*credits)() = &myCredits;

int main()
{
    bool play = true;

    while (play){
        myCredits();

        Board board[3][3];
        myBoard.assignValues(board);
        //myBoard.showBoard(board);

        int choice;
        int player=1;       // X should start at any scenario
        string gameMode;      // it could hold 2 values, 's'= single mode (with AI), 'm'=multiplayer mode

        cout<< "Choose your game mode, Single mode, or Multiplayer mode (s/m)   ";
        cin>> gameMode;

        while (true){
            if (gameMode == "s" || gameMode == "S" || gameMode == "m" || gameMode == "M")
                break;
            else {
                    cout << "Please enter 's' for sigleplayer or 'M' for Multiplayer   ";
                    cin >> gameMode;
            }
        }

        if (gameMode=="m" || gameMode=="M")
            while(true){
                myCredits();
                myBoard.showBoard(board);
                cout<< "\t\t\t\t\t" << "choose your place from the Num-Pad: ";
                cin>>choice;
                myBoard.validateChoice(&choice,board);

                board[2-(choice-1)/3][(choice-1)%3].value = player;

                if (myBoard.weHaveWinner(board, credits)) goto endGame;

                player= 3-player;       // "3-player" means the other player since, 3-2= 1,  3-1= 1
            }

        else if (gameMode=="s" || gameMode=="S"){
            while(true){
                myCredits();
                myBoard.showBoard(board);

                if (player==1){
                    cout<< "\t\t\t\t\t" << "choose your place from the Num-Pad: ";
                    cin>>choice;
                    myBoard.validateChoice(&choice,board);

                    board[2-(choice-1)/3][(choice-1)%3].value = player;
                }

                if (myBoard.weHaveWinner(board, credits)) goto endGame;

                if (player==2){
                    vector<int> anyGarbageShit;
                    AIPlayer.chooseTheBestMove(board, 2, anyGarbageShit, true);
                }

                if (myBoard.weHaveWinner(board, credits)) goto endGame;

                player= 3-player;       // "3-player" means the other player since, 3-2= 1,  3-1= 1
            }
        }

        endGame:
        playAgain(&play);
    }
}


void myCredits(){
    system("cls");
    cout << "\n\t\t\t\t\t\t" << "T I C   T A C   T O E" << "\n\t\t\t\t\t\t---------------------\n\n";
}

void playAgain(bool *play){
    string again;

    cout<< "\n\n\n";
    loop:
    cout << "play again ??? (y/n)";
    cin>> again;

    if (again=="y" || again=="Y"){
        *play = true;
        system("cls");
    }

    else if (again=="n" || again=="N")
        *play = false;

    else{
        cout<< "\nPlease enter a valid value !!!\n" ;
        goto loop;
    }
}
