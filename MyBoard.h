#ifndef MYBOARD_H
#define MYBOARD_H

struct Board {
    int number;
    int value=0;    // 0 = no value, 1 = X, 2 = O
};

class MyBoard
{
    public:
        MyBoard();
        int convertToNumber (int row, int column);                  // converts the x,y (row,column) to a number as at the num-pad
        Board pointToCoordinates (Board board[3][3],int num);       // returnsthe address of the desired element using its x,y (row,column)
        void assignValues (Board board[3][3]);                      // assign values for palces at the board for the first time
        void showShape(int value, int line);                        // prints the current line of the value, to reform a shape referes to this particular input
        void showBoard (Board board[3][3]);
        int checkWinning (Board m[3][3]);
        int weHaveWinner (Board board [3][3], void (*credits)());
        void validateChoice(int *choice, Board board[3][3]);
};

#endif // MYBOARD_H
