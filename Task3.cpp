#include <iostream>
#include <vector>

class SudokuSolver {
private:
    std::vector<std::vector<int>> board;
    
    bool isValid(int row, int col, int num) {
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == num) {
                return false;
            }
        }
        for (int x = 0; x < 9; x++) {
            if (board[x][col] == num) {
                return false;
            }
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool findEmptyCell(int &row, int &col) {
        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {
                if (board[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    SudokuSolver(const std::vector<std::vector<int>>& initialBoard) {
        board = initialBoard;
    }
    
    bool solve() {
        int row, col;
        if (!findEmptyCell(row, col)) {
            return true;
        }
        for (int num = 1; num <= 9; num++) {
            if (isValid(row, col, num)) {
                board[row][col] = num;
                if (solve()) {
                    return true;
                }
                board[row][col] = 0;
            }
        }
        return false;
    }
    
    void printBoard() {
        for (int i = 0; i < 9; i++) {
            if (i % 3 == 0 && i != 0) {
                std::cout << "---------------------" << std::endl;
            }
            for (int j = 0; j < 9; j++) {
                if (j % 3 == 0 && j != 0) {
                    std::cout << "| ";
                }
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    std::vector<std::vector<int>> getBoard() {
        return board;
    }
};

int main() {
    std::vector<std::vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    
    SudokuSolver solver(board);
    
    std::cout << "Sudoku Puzzle:" << std::endl;
    solver.printBoard();
    
    if (solver.solve()) {
        std::cout << "\nSolution:" << std::endl;
        solver.printBoard();
    } else {
        std::cout << "\nNo solution exists." << std::endl;
    }
    
    return 0;
}