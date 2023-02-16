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
namespace feb16 {
    class Game {
    public:
        static const int SIZE = 3, EMPTY = 0, CROSS = 1, CIRCLE = 2;
        Game() {
            board = new int[SIZE * SIZE];
            for (int r = 0; r < SIZE; ++r)
                for (int c = 0; c < SIZE; ++c)
                    board[get_position(r, c)] = EMPTY;
        }
        void put_x(int r, int c) {
            board[get_position(r, c)] = CROSS;
        }
        void put_o(int r, int c) {
            board[get_position(r, c)] = CIRCLE;
        }
        bool is_empty(int r, int c) const {
            return board[get_position(r, c)] == EMPTY;
        }
        bool is_over() const {
            return left_diagonal_filled_with_same_elements()
                || right_diagonal_filled_with_same_elements()
                || any_row_filled_with_same_elements()
                || any_column_filled_with_same_elements()
                || all_elements_of_board_are_occupied();
        }
        virtual ~Game() { delete[] board; }
    private:
        Game(const Game&);
        Game& operator=(const Game&);
        int get_position(int row, int col) const {
            return row * SIZE + col;
        }
        bool all_elements_of_board_are_occupied() const {
            for (int r = 0; r < SIZE; ++r)
                for (int c = 0; c < SIZE; ++c)
                    if (board[get_position(r, c)] == EMPTY)
                        return false;
            return true;
        }
        bool any_row_filled_with_same_elements() const {
            for (int r = 0; r < SIZE; ++r)
                if (are_values_equal_but_not_zero(board + r * SIZE))
                    return true;
            return false;
        }
        bool any_column_filled_with_same_elements() const {
            for (int c = 0; c < SIZE; ++c) {
                int val[SIZE];
                for (int r = 0; r < SIZE; ++r)
                    val[r] = board[get_position(r, c)];
                if (are_values_equal_but_not_zero(val)) return true;
            }
            return false;
        }
        bool right_diagonal_filled_with_same_elements() const {
            unordered_set<int> v;
            for (int i = 0; i < SIZE; ++i)
                v.insert(board[get_position(i, SIZE - i - 1)]);
            return ensure_one_non_zero_value_present_in_set(v);
        }
        bool left_diagonal_filled_with_same_elements() const {
            unordered_set<int> v;
            for (int i = 0; i < SIZE; ++i)
                v.insert(board[get_position(i, i)]);
            return ensure_one_non_zero_value_present_in_set(v);
        }
        static bool ensure_one_non_zero_value_present_in_set(const unordered_set<int>& values) {
            int val = Game::EMPTY;
            return find(values.cbegin(), values.cend(), val) == values.cend() && (values.size() == 1);
        }
        static bool are_values_equal_but_not_zero(const int mv[Game::SIZE]) {
            unordered_set<int> v;
            for (int i = 0; i < Game::SIZE; ++i) v.insert(mv[i]);
            return ensure_one_non_zero_value_present_in_set(v);
        }
        int* board = nullptr;
    };
}
using namespace feb16;
void feb16Main() {
}