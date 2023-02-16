namespace tictactoe{
class Game {
public:
    static const int SIZE = 3, EMPTY = 0, CROSS = 1, CIRCLE = 2;

    Game() {
    	board = new int[SIZE * SIZE];
        for (int r = 0; r < SIZE; ++r)
            for (int c = 0; c < SIZE; ++c)
                board[get_position(r,c)] =  EMPTY;
    }
    void put_x(int r, int c) {
        board[get_position(r,c)] =  CROSS;
    }
    void put_o(int r, int c) {
        board[get_position(r,c)] = CIRCLE;
    }
    bool is_empty(int r, int c) const {
        return board[get_position(r,c)] == EMPTY;
    }
    bool is_over() const {
		/* The game is over, if any of the following condition is true
		   - The board is filled
		   - Any row is filled with same element
		   - Any column is filled with same element
		   - The left or right diagonal is filled with same element.
		*/
    	return false;
    }
    virtual ~Game() { delete[] board; }
private:
    Game(const Game&);
    Game& operator=(const Game&);
    int get_position(int row, int col) const { return row * SIZE + col; }
    int *board = nullptr;
};
}
//Complete the function isOver using functional programming techniques.
