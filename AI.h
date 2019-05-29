#ifndef AI_H
#define AI_H

#include "MyBoard.h"
#include <vector>

using namespace std;

class AI
{
    public:
        AI();
        void chooseTheBestMove (Board board [3][3], int player, vector <int> &lastPossibleMovesScores, bool isTheFinal);
        int filteringPossibleMoves (int player, vector <int> &possibleMovesScores);
    private:
        void makeTheBestMove(Board board[3][3], vector <int> &scores);
};

#endif // AI_H
