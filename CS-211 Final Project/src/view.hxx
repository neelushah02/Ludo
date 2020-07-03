#include "model.hxx"
#include <ge211.hxx>


class View
{
public:
    // Constructor
    explicit View(Model const&);

    // Member Function
    void draw(ge211::Sprite_set& set, Model const&);
    ge211::Position board_to_screen (int);
    int screen_to_board (ge211::Position);

private:
    //add sprites of tokens and squares
    ge211::Rectangle_sprite box, r_box, g_box, y_box, b_box;

    ge211::Image_sprite red_token{"red-token.png"};
    ge211::Image_sprite blue_token{"blue-token.png"};
    ge211::Image_sprite green_token{"green-token.png"};
    ge211::Image_sprite yellow_token{"yellow-token.png"};
    ge211::Font sans36 {"sans.ttf", 36};
    ge211::Font sans18 {"sans.ttf", 18};
    ge211::Text_sprite dice;
    ge211::Text_sprite whose_turn_is_it;
    std::string instructions1 = "INSTRUCTIONS:";
    std::string instructions2 = "Press the spacebar to roll";
    std::string instructions3 = "the dice.";
    std::string instructions4 = "Click a token to move it. ";
    std::string instructions5 = "Remember, you can't leave";
    std::string instructions6 = "your yard till you";
    std::string instructions7 = "roll a 6!";
    ge211::Text_sprite rules1 {instructions1, sans18};
    ge211::Text_sprite rules2 {instructions2, sans18};
    ge211::Text_sprite rules3 {instructions3, sans18};
    ge211::Text_sprite rules4 {instructions4, sans18};
    ge211::Text_sprite rules5 {instructions5, sans18};
    ge211::Text_sprite rules6 {instructions6, sans18};
    ge211::Text_sprite rules7{instructions7, sans18};

};

