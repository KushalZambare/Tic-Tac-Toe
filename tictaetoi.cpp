    #include <iostream>
    #include <vector>
    #include <limits>

    using namespace std;

    class TicTacToe {
    private:
        vector<vector<char>> board;
        char currentPlayer;
        bool gameOver;

    public:
        TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X'), gameOver(false) {}

        void printBoard() {
            cout << "\n";
            cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
            cout << "-----------\n";
            cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
            cout << "-----------\n";
            cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
            cout << "\n";
        }

        bool makeMove(int row, int col) {
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                return false;
            }
            board[row][col] = currentPlayer;
            return true;
        }

        bool checkWin() {
            // Check rows
            for (int i = 0; i < 3; i++) {
                if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                    return true;
                }
            }

            // Check columns
            for (int j = 0; j < 3; j++) {
                if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                    return true;
                }   
            }

            // Check diagonals
            if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                return true;
            }
            if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                return true;
            }

            return false;
        }

        bool checkDraw() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        return false;
                    }
                }
            }
            return true;
        }

        void switchPlayer() {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        void playGame() {
            cout << "Welcome to Tic Tac Toe!\n";
            cout << "Player 1: X\n";
            cout << "Player 2: O\n";
            cout << "Enter row (0-2) and column (0-2) to make your move.\n";

            gameOver = false;
            while (!gameOver) {
                printBoard();
                cout << "Player " << currentPlayer << "'s turn.\n";

                int row, col;
                cout << "Enter row (0-2): ";
                while (!(cin >> row) || row < 0 || row > 2) {
                    cout << "Invalid input. Please enter a number between 0 and 2: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Enter column (0-2): ";
                while (!(cin >> col) || col < 0 || col > 2) {
                    cout << "Invalid input. Please enter a number between 0 and 2: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                if (!makeMove(row, col)) {
                    cout << "Invalid move! That spot is already taken or out of bounds. Try again.\n";
                    continue;
                }

                if (checkWin()) {
                    printBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    printBoard();
                    cout << "It's a draw!\n";
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }
        }

        void resetGame() {
            board = vector<vector<char>>(3, vector<char>(3, ' '));
            currentPlayer = 'X';
            gameOver = false;
        }
    };

    int main() {
        TicTacToe game;
        char playAgain;
        do {
            game.resetGame();
            game.playGame();
            cout << "Would you like to play again? (y/n): ";
            cin >> playAgain;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        } while (playAgain == 'y' || playAgain == 'Y');
        cout << "Thanks for playing!\n";
        return 0;
    }