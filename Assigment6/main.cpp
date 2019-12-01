#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <cmath>        // std::abs

using namespace std;

//Assigment 6, main.cpp

/*
OPPGAVETEKST: 
Oppgave 1 - Jobb videre med sjakkbrett-løsningen deres fra Øving 5:
lag en klasse ChessBoardPrint som tar seg av utskrift (std::cout kallene) til terminalen
ChessBoardPrint må ha tilgang til ChessBoard instansen, for eksempel i main(): ChessBoard board; ChessBoardPrint print(board);
I konstruktøren til ChessBoardPrint skal dere definere funksjonsobjektene til ChessBoard instansen ved hjelp av lambda uttrykk.
Utskriften av sjakkbrettet etter et sjakktrekk skal også foregå i ChessBoardPrint.
Legg til et eget funksjonsobjekt i ChessBoard (for eksempel after_piece_move) som blir kjørt etter et trekk er utført. Definer dette funksjonsobjektet i ChessBoardPrint.

*/

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
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    function<void()>after_piece_move;

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
                if (on_piece_move)
                    on_piece_move(*piece_from, from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if (on_piece_removed)
                            on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get())) {
                            if (on_lost_game)
                                on_lost_game(king->color);
                        }
                    } else {
                        if (on_piece_move_invalid)
                            on_piece_move_invalid(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = move(piece_from);
                after_piece_move();
                return true;
            } else {
                if (on_piece_move_invalid)
                    on_piece_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            if (on_piece_move_missing)
                on_piece_move_missing(from);
            return false;
        }
    }
};

class ChessBoardPrint{
public:

    //constructor
    explicit ChessBoardPrint(ChessBoard &board)  {
        board.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        board.on_piece_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        board.on_lost_game = [](ChessBoard::Color color) {
            if (color == ChessBoard::Color::WHITE)
                cout << "Black";
            else
                cout << "White";
            cout << " won the game" << endl;
        };
        board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        board.on_piece_move_missing=[](const string &square) {
            cout << "no piece at " << square << endl;
        };
        board.after_piece_move=[&](){
            std::cout << "_________________________________"<< std::endl;
            for (int rows = 0; rows < 8; rows++ ){
                for(int col=0; col < 8; col++){
                    std::cout << "|";
                    auto &piece = board.squares[rows][col];
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
        };
    }

};


int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

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
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");

}
