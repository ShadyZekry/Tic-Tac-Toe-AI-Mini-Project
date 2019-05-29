#include "AI.h"
#include "MyBoard.h"    // To make use of "checkWinning" function
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

MyBoard myBoard2;        // To make use of "checkWinning" function

AI::AI()
{
    //ctor
}

void AI:: chooseTheBestMove (Board board [3][3], int player, vector <int> &lastPossibleMovesScores, bool isTheFinal){

    vector <int> possibleMovesScores;

    /////////////// Base Case \\\\\\\\\\\\\\\\

    int result = myBoard2.checkWinning(board);
    if (result == 1)
        lastPossibleMovesScores.push_back(-10);
    else if (result == 2)
        lastPossibleMovesScores.push_back(10);
    else if (result == -1)
        lastPossibleMovesScores.push_back(0);
    //////////////////////////////////////////

    else{
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if (board[i][j].value == 0){
                    board[i][j].value = player;
                    chooseTheBestMove(board, 3-player, possibleMovesScores, false);
                    board[i][j].value = 0;                                           // remove what the AI changed while he thinks of his moves
                }

        if (isTheFinal)
            makeTheBestMove(board, possibleMovesScores);
        else
            lastPossibleMovesScores.push_back( filteringPossibleMoves(player,possibleMovesScores) );

    }
}

int AI:: filteringPossibleMoves (int player, vector <int> &possibleMovesScores){
    int size=possibleMovesScores.size();
    int best;

    if (player==1){
        best = 1000000;
        for (int i=0;i<size;i++)
            if (possibleMovesScores[i]<best)
                best = possibleMovesScores[i];
    }
    else if (player==2){
        best = -1000000;
        for (int i=0;i<size;i++)
            if (possibleMovesScores[i]>best)
                best = possibleMovesScores[i];
    }
    return best;
}


void AI:: makeTheBestMove(Board board[3][3], vector <int> &scores){
    int best;
    vector <int> bestScores;
    int chosenIndex;

    best=filteringPossibleMoves(2,scores);

    for(int i=1;i<=scores.size();i++)
        if(scores[i-1]==best)
            bestScores.push_back(i);

    srand(time(NULL));
    chosenIndex= bestScores[ rand()%bestScores.size() ];
    cout<< chosenIndex;

    int counter=0;

    int flag = false;
    for (int i=0;i<3 && flag==false ;i++)
        for (int j=0;j<3 && flag==false ;j++){
            if (board[i][j].value == 0) counter++;
            if (counter==chosenIndex){
                board [i][j] .value = 2;
                flag=true;
            }
        }
}
