#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cassert>
#include <unordered_set>
#include <algorithm>

using namespace std;
namespace feb23 {
    class TicTacToe {
    public:
        static const int BOARD_SIZE = 3;
        static const char BLANK = ' ', CROSS = 'x', CIRCLE = 'o';
    private:
        char board[BOARD_SIZE][BOARD_SIZE];
    public:
        TicTacToe() {
            for (int i = 0; i < BOARD_SIZE; i++)
                for (int j = 0; j < BOARD_SIZE; j++)
                    board[i][j] = BLANK;
        }
        void setO(int row, int col) { board[row][col] = CIRCLE; }
        void setX(int row, int col) { board[row][col] = CROSS; }

        bool over() {
            for (int x = 0; x < BOARD_SIZE; ++x)
                if (board[x][0] != BLANK && board[x][0] == board[x][1]
                    && board[x][0] == board[x][2])
                    return true;
            for (int y = 0; y < BOARD_SIZE; ++y)
                if (board[0][y] != BLANK && board[0][y] == board[1][y]
                    && board[0][y] == board[2][y])
                    return true;
            if (board[0][0] != BLANK && board[0][0] == board[1][1]
                && board[0][0] == board[2][2])
                return true;
            if (board[0][2] != ' ' && board[0][2] == board[1][1]
                && board[0][2] == board[2][0])
                return true;
            for (int x = 0; x < BOARD_SIZE; ++x)
                for (int y = 0; y < BOARD_SIZE; ++y)
                    if (board[x][y] == BLANK) return false;
            return true;;
        }
    };
}
using namespace feb23;
#include <gtest/gtest.h>
#include <gmock/gmock.h>
TEST(TicTacToe, GameOverWhenAllElementsOfRowAreSame) { 
    TicTacToe t;
    EXPECT_FALSE(t.over());
    t.setO(0, 0);
    EXPECT_FALSE(t.over());
    t.setO(0, 1);
    EXPECT_FALSE(t.over());
    t.setO(0, 2);
    EXPECT_TRUE(t.over());
}
TEST(TicTacToe, GameOverWhenAllElementsOfColAreSame) {
    TicTacToe t;
    EXPECT_FALSE(t.over());
    t.setX(0, 1);
    EXPECT_FALSE(t.over());
    t.setX(1, 1);
    EXPECT_FALSE(t.over());
    t.setX(2, 1);
    EXPECT_TRUE(t.over());
}
TEST(TicTacToe, GameOverWhenAllElementsOfLeftDiagonalAreSame) {
    TicTacToe t;
    EXPECT_FALSE(t.over());
    t.setX(0, 0);
    EXPECT_FALSE(t.over());
    t.setX(1, 1);
    EXPECT_FALSE(t.over());
    t.setX(2, 2);
    EXPECT_TRUE(t.over());
}
TEST(TicTacToe, GameOverWhenAllElementsOfRightDiagonalAreSame) {
    TicTacToe t;
    EXPECT_FALSE(t.over());
    t.setO(0, 2);
    EXPECT_FALSE(t.over());
    t.setO(1, 1);
    EXPECT_FALSE(t.over());
    t.setO(2, 0);
    EXPECT_TRUE(t.over());
}
TEST(TicTacToe, GameOverWhenBoardFilledWithNoWinner) {
    TicTacToe t;
    //   OXO
    //   XOX
    //   XOX
    t.setO(0, 0);   EXPECT_FALSE(t.over());
    t.setX(0, 1);   EXPECT_FALSE(t.over());
    t.setO(0, 2);   EXPECT_FALSE(t.over());
    t.setX(1, 0);   EXPECT_FALSE(t.over());
    t.setO(1, 1);   EXPECT_FALSE(t.over());
    t.setX(1, 2);   EXPECT_FALSE(t.over());
    t.setX(2, 0);   EXPECT_FALSE(t.over());
    t.setO(2, 1);   EXPECT_FALSE(t.over());
    t.setX(2, 2);  
    EXPECT_TRUE(t.over());
}

