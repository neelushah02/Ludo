#include "view.hxx"
#include <ge211.hxx>
//constructor
View::View(const Model &)
        : box({40, 40}, ge211::Color::white())
        , r_box({40, 40}, ge211::Color::medium_red().lighten(0.35))
        , b_box({40, 40}, ge211::Color::medium_blue().lighten(0.35))
        , g_box({40, 40}, ge211::Color::medium_green().lighten(0.35))
        , y_box({40, 40}, ge211::Color::medium_yellow().lighten(0.35))

{}

void View::draw(ge211::Sprite_set& set, Model const& model)
{
    //drawing board
    for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (j == 5)
                {
                    if (i > 0 && i < 5)
                    {
                        set.add_sprite(g_box, {40 * (i + 1) + 5 * i,
                                               40 * (j + 1) + 5 * j});
                    }
                    else if (i > 5 && i < 10)
                    {
                        set.add_sprite(b_box, {40 * (i + 1) + 5 * i,
                                               40 * (j + 1) + 5 * j});
                    }
                    else
                        {
                        set.add_sprite(box, {40 * (i + 1) + 5 * i,
                                             40 * (j + 1) + 5 * j});
                    }
                }
                else if (i == 5)
                {
                    if (j > 0 && j < 5)
                    {
                        set.add_sprite(y_box, {40 * (i + 1) + 5 * i,
                                               40 * (j + 1) + 5 * j});
                    }
                    else if (j > 5 && j < 10)
                    {
                        set.add_sprite(r_box, {40 * (i + 1) + 5 * i,
                                               40 * (j + 1) + 5 * j});
                    }
                    else
                        {
                        set.add_sprite(box, {40 * (i + 1) + 5 * i,
                                             40 * (j + 1) + 5 * j});
                    }
                }
                else if ((i > 3 && i < 7) || (j > 3 && j < 7))
                {
                    set.add_sprite(box, {40 * (i + 1) + 5 * i,
                                         40 * (j + 1) + 5 * j});
                }
            }
        }

        // red yard
        set.add_sprite(r_box, {230 - 45 * 3, 45 * 9});
        set.add_sprite(r_box, {230 - 45 * 3 + 40, 45 * 9});
        set.add_sprite(r_box, {230 - 45 * 3, 45 * 9 + 40});
        set.add_sprite(r_box, {230 - 45 * 3 + 40, 45 * 9 + 40});

        // green yard
        set.add_sprite(g_box, {230 - 45 * 3, 45 * 2});
        set.add_sprite(g_box, {230 - 45 * 3 + 40, 45 * 2});
        set.add_sprite(g_box, {230 - 45 * 3, 45 * 2 + 40});
        set.add_sprite(g_box, {230 - 45 * 3 + 40, 45 * 2 + 40});

        // yellow yard
        set.add_sprite(y_box, {230 + 45 * 4, 45 * 2});
        set.add_sprite(y_box, {230 + 45 * 4 + 40, 45 * 2});
        set.add_sprite(y_box, {230 + 45 * 4, 45 * 2 + 40});
        set.add_sprite(y_box, {230 + 45 * 4 + 40, 45 * 2 + 40});

        // blue yard
        set.add_sprite(b_box, {230 + 45 * 4, 45 * 9});
        set.add_sprite(b_box, {230 + 45 * 4 + 40, 45 * 9});
        set.add_sprite(b_box, {230 + 45 * 4, 45 * 9 + 40});
        set.add_sprite(b_box, {230 + 45 * 4 + 40, 45 * 9 + 40});

        //draws tokens at their respective positions
        for (int i = 0;
             i < model.get_num_players() * 4; i++) //iterate thru tokens
        {
            if (model.get_tokens()[i].get_status() != Status::yard) //not yard
            {
                int sq = model.get_tokens()[i].get_square_number();
                if (i < 4) {
                    set.add_sprite(red_token,
                                   board_to_screen(sq), 1,
                                   ge211::Transform::scale(0.08));
                } else if (i < 8) {
                    set.add_sprite(green_token,
                                   board_to_screen(sq), 1,
                                   ge211::Transform::scale(0.04));
                } else if (i < 12) {
                    set.add_sprite(yellow_token,
                                   board_to_screen(sq), 1,
                                   ge211::Transform::scale(0.08));
                } else if (i < 16) {
                    set.add_sprite(blue_token,
                                   board_to_screen(sq), 1,
                                   ge211::Transform::scale(0.08));
                }
            } else { //yard cases
                if (i < 4) {
                    set.add_sprite(red_token,
                                   {230 - 45 * 3 + i * 20, 45 * 9 + i * 10}, 1,
                                   ge211::Transform::scale(0.08));
                } else if (i < 8) {
                    set.add_sprite(green_token,
                                   {230 - 45 * 3 + (i - 4) * 20,
                                    45 * 2 + (i - 4) * 10}, 1,
                                   ge211::Transform::scale(0.04));
                } else if (i < 12) {
                    set.add_sprite(yellow_token,
                                   {230 + 45 * 4 + (i - 8) * 20,
                                    45 * 2 + (i - 8) * 10}, 1,
                                   ge211::Transform::scale(0.08));
                } else if (i < 16) {
                    set.add_sprite(blue_token,
                                   {230 + 45 * 4 + (i - 12) * 20,
                                    45 * 9 + (i - 12) * 10}, 1,
                                   ge211::Transform::scale(0.08));
                }
            }
        }
        ge211::Text_sprite::Builder name_builder(sans36);
        name_builder.color(ge211::Color::white()) << "Dice Roll: " +std::to_string(model.get_dice_val());
        dice.reconfigure(name_builder);
        set.add_sprite(dice, {575, 500});

    std::string temp;
    if(model.get_turn() == Color::red)
        temp = "Red";
    else if(model.get_turn() == Color::green)
        temp = "Green";
    else if(model.get_turn() == Color::yellow)
        temp = "Yellow";
    else if(model.get_turn() == Color::blue)
        temp = "Blue";

        ge211::Text_sprite::Builder name_builder1(sans36);
        name_builder1.color(ge211::Color::white()) << "Turn: " + temp;
        whose_turn_is_it.reconfigure(name_builder1);
        set.add_sprite(whose_turn_is_it, {575, 400});
        set.add_sprite(rules1, {575, 100});
        set.add_sprite(rules2, {575, 130});
        set.add_sprite(rules3, {575, 160});
        set.add_sprite(rules4, {575, 190});
        set.add_sprite(rules5, {575, 220});
        set.add_sprite(rules6, {575, 250});
        set.add_sprite(rules7, {575, 280});
}

ge211::Position View::board_to_screen(int sq_num)
{
    int x = 0, y = 0;

    // finding x coordinate, line by line in board
    if(sq_num == 39 || sq_num == 48 || sq_num >= 0 && sq_num <4 || sq_num >12
                                                                   && sq_num < 18)
        x = 230;
    else if (sq_num == 4 || sq_num == 47 || sq_num == 12)
        x = 230 - 45;
    else if (sq_num == 5 || sq_num == 46 || sq_num == 11)
        x = 230 - 45*2;
    else if (sq_num == 6 || sq_num == 45 || sq_num == 10)
        x = 230 - 45*3;
    else if (sq_num == 7 || sq_num == 8 || sq_num == 9)
        x = 230 - 45*4;
    else if(sq_num == 38 || sq_num == 18 || sq_num >= 40 && sq_num <44 ||
            sq_num > 49 && sq_num < 54)
        x = 230 + 45;
    else if(sq_num == 58 || sq_num >= 19 && sq_num <24 || sq_num >32
                                                          && sq_num < 38)
        x = 230 + 45*2;
    else if (sq_num == 24 || sq_num == 57 || sq_num == 32)
        x = 230 + 45*3;
    else if (sq_num == 25 || sq_num == 56 || sq_num == 31)
        x = 230 + 45*4;
    else if (sq_num == 26 || sq_num == 55 || sq_num == 30)
        x = 230 + 45*5;
    else if (sq_num == 27 || sq_num == 28 || sq_num == 29)
        x = 230 + 45*6;
    else //home squares
        x = 230 + 45;


    // finding y coordinate
    if ( sq_num == 17 || sq_num == 18 || sq_num == 19)
        y = 45;
    else if ( sq_num == 16 || sq_num == 50 || sq_num == 20)
        y = 45 + 45;
    else if ( sq_num == 15 || sq_num == 51 || sq_num == 21)
        y = 45 + 45*2;
    else if ( sq_num == 14 || sq_num == 52 || sq_num == 22)
        y = 45 + 45*3;
    else if ( sq_num > 8 && sq_num <14 || sq_num == 53 || sq_num > 22 &&
                                                          sq_num < 28)
        y = 45 + 45*4;
    else if ( sq_num > 44 && sq_num <49 || sq_num == 8 || sq_num == 28 ||
              sq_num > 54 && sq_num < 59)
        y = 45 + 45*5;
    else if ( sq_num > 2 && sq_num <8 || sq_num == 43 || sq_num > 28 &&
                                                         sq_num < 34)
        y = 45 + 45*6;
    else if ( sq_num == 2 || sq_num == 42 || sq_num == 34)
        y = 45 + 45*7;
    else if ( sq_num == 1 || sq_num == 41 || sq_num == 35)
        y = 45 + 45*8;
    else if ( sq_num == 0 || sq_num == 40 || sq_num == 36)
        y = 45 + 45*9;
    else if ( sq_num > 36 && sq_num < 40)
        y = 45 + 45*10;
    else
        y = 45*6;

    return ge211::geometry::Position(x, y);
}

int View::screen_to_board(ge211::Position pos)
{
    for (int i = 0; i < 60; i++)
    {
        if( (pos.x <= View::board_to_screen(i).x + 40
             && pos.x >=View::board_to_screen(i).x)
            &&
            (pos.y <= View::board_to_screen(i).y + 40
             && pos.y >=View::board_to_screen(i).y))
        {            return i;
        }
    }
    return -1;
}


