//
// Created by Kevinlinpr on 2019/6/12.
//

#include <iostream>
#include "ChessBoard.h"

bool POSITION_MARK::INVALID = false;
bool POSITION_MARK::VALID = true;



ChessBoard::ChessBoard(int sqr):square(sqr) {
    this->col = new bool[square];
    this->left_diagonal = new bool[square*2 - 1];//error:new bool[square - 1]{POSITION_MARK::VALID}
    this->right_diagonal = new bool[square*2 - 1];//error:new bool[square - 1]{POSITION_MARK::VALID}
    this->position_in_row = new int[square];
    for (int i = 0; i < square*2 - 1; ++i) {
        this->left_diagonal[i] = this->right_diagonal[i] = POSITION_MARK::VALID;
    }
    for (int j = 0; j < square; ++j) {
        this->col[j] = POSITION_MARK::VALID;
        this->position_in_row[j] = -1;
    }
}

bool ChessBoard::ValidPosition(int row, int col) {
    return (this->left_diagonal)[row + col] && (this->right_diagonal)[row - col + this->square - 1] && (this->col)[col];
}

void ChessBoard::MarkPosition(int row, int col, bool position_mark) {
    (this->left_diagonal)[row + col] = position_mark;
    (this->right_diagonal)[row - col + this->square - 1] = position_mark;
    (this->col)[col] = position_mark;
}

void ChessBoard::PrintChessBoard() {
    std::cout<<"START PRINT."<<std::endl;
    for (int i = 0; i < square; ++i) {
        std::cout<<"ROW "<<i<<" : COL : "<<(this->position_in_row)[i]<<std::endl;
    }
    std::cout<<"END PRINT."<<std::endl;
}

void ChessBoard::FindSolution() {
    this->PutQueen(0);
}

void ChessBoard::PutQueen(int row) {
    for (int c = 0; c < square; ++c) {
        if(this->ValidPosition(row,c)){
            this->MarkPosition(row,c,POSITION_MARK::INVALID);
            (this->position_in_row)[row] = c;
            if(row<square-1)//error:row<square
                this->PutQueen(row+1);
            else
                this->PrintChessBoard();
            this->MarkPosition(row,c,POSITION_MARK::VALID);
        }
    }
}

/// example
//auto * chessBoard = new ChessBoard(8);
//chessBoard->FindSolution();



