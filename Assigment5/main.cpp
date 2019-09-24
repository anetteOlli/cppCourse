#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>        // std::abs

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        virtual std::string art() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
        // missing implementations
    public:
        //constructor:
        King(const Color &color_) : Piece(color_) {}

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if (std::abs(from_x - to_x) > 1) {
                return false;
            }else if (std::abs(from_y - to_y) > 1){
                return false;
            }
            return true;
        }
        std::string type() const override {
            return Piece::color_string() + " king";
        }
        std::string art() const override {
            if (this->color == Color::WHITE){
                return WHITE_KING;
            }else{
                return BLACK_KING;
            }
        }
    private:
        const std::string WHITE_KING = "♔️";
        const std::string BLACK_KING = "♚";

    };

    class Knight : public Piece {
        // missing implementations
    public:

        //constructor:
        Knight (const Color &color_) : Piece (color_) {}

        //functions:
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if(std::abs(from_x-to_x)==2 && std::abs(from_y-to_y)==1){
                return true;
            }else if (std::abs(from_y-to_y)== 2 && std::abs(from_x-to_x)==1){
                return true;
            }
            return false;
        }

        std::string type() const override {
            return Piece::color_string() + " knight";
        }

        std::string art() const override {
            if (this->color == Color::WHITE){
                return WHITE_KNIGHT;
            }else{
                return BLACK_KNIGHT;
            }
        }

    private:
        const std::string WHITE_KNIGHT = "♘";
        const std::string BLACK_KNIGHT = "♞";
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }

    void print_board() const {
        std::cout << "_________________________________"<< std::endl;
        for (int rows = 0; rows < 8; rows++ ){
            for(int col=0; col < 8; col++){
                std::cout << "|";
                auto &piece = squares[rows][col];
                if (piece) {
                    std::cout <<" " << piece->art() << " ";
                }else{
                    std::cout << "   ";
                }
                if (col == 7){
                    std::cout<< "|" << std::endl << "_________________________________" << std::endl;
                }
            }

        }
    }
};

int main() {
    ChessBoard board;

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.print_board();
    board.move_piece("g8", "h6");
    board.print_board();
    board.move_piece("b1", "c3");
    board.print_board();
    board.move_piece("h6", "g8");
    board.print_board();
    board.move_piece("c3", "d5");
    board.print_board();
    board.move_piece("g8", "h6");
    board.print_board();
    board.move_piece("d5", "f6");
    board.print_board();
    board.move_piece("h6", "g8");
    board.print_board();
    board.move_piece("f6", "e8");
    board.print_board();


}

//uskrift skal være:
/*
Invalid moves:
no piece at e3
can not move white king from e1 to e3
can not move white knight from b1 to b2

A simulated game:
white king is moving from e1 to e2
black knight is moving from g8 to h6
white knight is moving from b1 to c3
black knight is moving from h6 to g8
white knight is moving from c3 to d5
black knight is moving from g8 to h6
white knight is moving from d5 to f6
black knight is moving from h6 to g8
white knight is moving from f6 to e8
black king is being removed from e8
black lost the game
 */