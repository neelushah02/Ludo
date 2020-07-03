#pragma once
#include <ge211.hxx>
#include <vector>

//defined in UI instead
//const double token_radius;
//const ge211::Dimensions dice_dims;
//const ge211::Dimensions square_dims;

//model structs and classes:
enum struct Color
{
    red, green, yellow, blue, neither
};
enum struct Status
{
    yard, on_board, finished
};



class Token
{
    //private data
    int square_number_;
    int token_number_;
    int squares_moved_;
    Color color_;
    Status status_;

    //public members
public:

    //Constructor
    Token(Color, int);

    //functions
    Color get_color ();
    //gets the colour of the token
    Status get_status ();
    //returns whether the token is in the yard,
    // finished or on the board
    int get_square_number();
    //gets the index of the square that the
    //token is on
    int get_token_number();
    //gets the number (between 1 and 4) that the token
    //represents
    int get_squares_moved();
    //returns the number of squares the token has
    // crossed since it left the yard

    //collision checking happens in board class

    bool set_square_number(int dice_roll);
    //changes the square number that the token is on,
    //returns whether anything changed
    void set_squares_moved(int dice_roll);
    //changes the number of squares the token has
    //crossed since it left the yard
    void set_status(Status status);
    //changes the status of the token.

};

class Square
{
    //private data
    Color color_;
    std::vector<int> square_contents_;

    //public members
public:

    //Constructors
    Square(); //creates a square with square_contents_ and color_ neither
    Square(Color); //create a square with given color and empty
    // square_contents_

    Color get_color(); //returns the color of the square
    void add_token(int t_num); //adds a token to the square by
    // pushing its
    //number onto the vector square_contents_
    void remove_token(int t_num); //removes a token to the square by
    // popping its number from vector square_contents_
    std::vector<int> get_square_contents(); //returns the vector of pointers
    //to tokens which are contained in the square
};

class Model
{
    //private data
    int no_of_players_;
    int no_of_tokens_;
    int dice_val_;
    std::vector<Square> path_; //path_ will contain not just neutral squares,
    // it'll have the home stretch squares as well. we'll figure out how to
    // move along the path_ depending on colour of token.

    std::vector<Token> tokens_;
    Color turn_;
    bool game_status_;

    //public members
public:
    void set_dice_val(int roll);
    int get_dice_val() const;
    std::vector<Square> yards_;
    // Constructor
    Model(int); //takes number of players, creates a model with required
    // number of players and token set up


    bool get_game_status() const;
    //checks whether the game is over or not. false if game over.
    int get_num_players() const; //returns number of players
    Color get_turn() const; //returns the color whose turn it is to play
    void move(int dice_roll, int t_num); //moves tokens across the board
    // depending on // the number rolled on the dice
    void collision(int square_number); //handles collisions, dispatching the
    // appropriate token back to its yard
    void set_turn(); //changes the turn_ to the next color.
    void set_game_status(); //changes the game_status_ to false when game over.
    bool all_four_not_on_path();
    std::vector<Token> get_tokens() const;
    std::vector<Square> get_path() const;

};
