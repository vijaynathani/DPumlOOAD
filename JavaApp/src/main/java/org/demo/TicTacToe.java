package org.demo;

public class TicTacToe {
    char[][] board;
    public static final int boardSize = 3;
    public static final char BLANK = ' ', CROSS = 'x', CIRCLE = 'o';
    TicTacToe() {
        board = new char[boardSize][boardSize];
        for (int i = 0; i < boardSize; i++)
            for (int j = 0; j < boardSize; j++)
                board[i][j] = BLANK;
    }
    public boolean over() {
        for (int x = 0; x < board.length; x++)
            if (board[x][0] != ' ' && board[x][0] == board[x][1] && board[x][0] == board[x][2]) return true;
        for (int y = 0; y < board[0].length; y++)
            if (board[0][y] != ' ' && board[0][y] == board[1][y] && board[0][y] == board[2][y]) return true;
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) return true;
        for (int x = 0; x < board.length; x++)
            for (int y = 0; y < board[0].length; y++)
                if (board[x][y] == BLANK) return false;
        return true;
    }
    public void setX(int row, int col) {
        board[row][col] = CROSS;
    }
    public void setO(int row, int col) {
        board[row][col] = CIRCLE;
    }
}
