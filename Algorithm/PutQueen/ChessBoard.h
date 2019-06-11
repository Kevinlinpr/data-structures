//
// Created by Kevinlinpr on 2019/6/12.
//

#ifndef STLLEARN_CHESSBOARD_H
#define STLLEARN_CHESSBOARD_H

struct POSITION_MARK{
    static bool INVALID;
    static bool VALID;
};



class ChessBoard {
public:
    explicit ChessBoard(int sqr);
    void FindSolution();

private:
    void PrintChessBoard();
    void PutQueen(int row);
    bool ValidPosition(int row, int col);
    void MarkPosition(int row, int col,bool position_mark);

    int square{};//棋盘大小，如果是8x8那么square=8;
    bool* col;//当前行列,用于左右斜线计算,指针用于动态分配
    bool* left_diagonal,*right_diagonal;//左斜线求和，右斜线求差并加值保证下标为正，指针用于动态分配
    int* position_in_row;
};


#endif //STLLEARN_CHESSBOARD_H
