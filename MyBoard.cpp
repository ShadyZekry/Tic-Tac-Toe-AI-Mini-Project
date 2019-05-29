#include "MyBoard.h"
#include <iostream>

using namespace std;

MyBoard::MyBoard()
{
    //ctor
}

/*
Board MyBoard:: pointToCoordinates (Board board[3][3],int num){
    int row     = 2- (num-1)/3;     // 2- is for matching num-pad sequence
    int column  = (num-1)%3;

    return board[row][column];
}
*/

int MyBoard:: convertToNumber (int row, int column){
    int num;
    num  = (2-row)*3 + (column+1);
    return num;
}

void MyBoard:: assignValues (Board board[3][3]){
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            board[i][j].number= convertToNumber(i,j);
}

void MyBoard:: showShape(int value, int row){
    switch(value){
        case 0: cout<< "     ";break;

        case 1:
            if      (row==1 || row==0) cout<< "#   #";  // it is 0 not 5 because we pass a row argument of (%5) which will never lead to 5
            else if (row==2 || row==4) cout<< " # # ";
            else                       cout<< "  #  ";
            break;

        case 2:
            if      (row==1 || row==0) cout<< "#####";  // it is 0 not 5 because we pass a row argument of (%5) which will never lead to 5
            else                       cout<< "#   #";
            break;

/*

#   #       ######
 # #        #    #
  #         #    #
 # #        #    #
#   #       ######

*/

    }
}

void MyBoard:: showBoard (Board board[3][3]){
    for(int row=1;row<=15;row++){                // the board should be 3X3 elements, each one contains 5 chars
        cout<< "\t\t\t\t\t\t |";                  // put the board at the cinter a little bit
        for(int column=1;column<=3;column++){
            showShape(board[ (row-1) /5][column-1].value, row%5);
            cout<< "|";
        }
        cout<< endl;
        if(row%5==0) cout<<endl;
    }
}

int MyBoard:: checkWinning (Board m[3][3]){
    /*
        789                           7      8       9           9      7
                456                   4      5       6          5        5
                        123           1      2       3         1          3
    */

    if (m[0][0].value != 0 && m[0][0].value == m[0][1].value && m[0][1].value == m[0][2].value) return m[0][0].value;    //  789
    if (m[1][0].value != 0 && m[1][0].value == m[1][1].value && m[1][1].value == m[1][2].value) return m[1][0].value;    //  456
    if (m[2][0].value != 0 && m[2][0].value == m[2][1].value && m[2][1].value == m[2][2].value) return m[2][0].value;    //  123

    if (m[0][0].value != 0 && m[0][0].value == m[1][0].value && m[1][0].value == m[2][0].value) return m[0][0].value;    //  741
    if (m[0][1].value != 0 && m[0][1].value == m[1][1].value && m[1][1].value == m[2][1].value) return m[0][1].value;    //  852
    if (m[0][2].value != 0 && m[0][2].value == m[1][2].value && m[1][2].value == m[2][2].value) return m[0][2].value;    //  963

    if (m[0][0].value != 0 && m[0][0].value == m[1][1].value && m[1][1].value == m[2][2].value) return m[0][0].value;    //  951
    if (m[0][2].value != 0 && m[0][2].value == m[1][1].value && m[1][1].value == m[2][0].value) return m[0][2].value;    //  753

    int draw =1;
    for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                draw *= m[i][j].value;
    if (draw!=0) return -1;

    else return 0;
}

int MyBoard:: weHaveWinner (Board board [3][3], void (*credits)()){
    int result = checkWinning(board);

    if (result!=0){
        system("cls");
        (*credits)();

        showBoard(board);

        if (result == -1){
            cout<< "\t\t\t\t\t\t\tDraw !!!\n\n\n";
            return 1;
        }

        cout<< "\n\t\t\t\t\t\t" << "The winner is ";
        if(result==1)   cout << "X ";
        else            cout << "O ";
        cout<< "!!!\n\n\n";

        return 1;
    }

    else return 0;
}

void MyBoard:: validateChoice(int *choice, Board board[3][3]){
    while (true){
        if (*choice<1 || *choice>9){
            cout<< "\t\t\t\t\t" << "Please choose a valid number: ";
            cin>> *choice;
        }
        else if (board[2-(*choice-1)/3] [(*choice-1)%3] .value !=0){
            cout<< "\t\t\t\t\t" << "This place is taken, choose another one: ";
            cin>> *choice;
        }
        else break;
    }
}
