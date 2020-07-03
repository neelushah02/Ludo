#include "model.hxx"
#include <catch.hxx>


TEST_CASE("Favorite Test")
{
    Model m(3);
    CHECK(m.get_tokens().size() == 12);
    m.move(5, 0); //token should not move unless 6 is rolled
    CHECK(m.get_tokens()[0].get_status() == Status::yard);
    m.set_turn(); //green's turn now
    m.move(6, 4);
    CHECK(m.get_tokens()[4].get_status() == Status::on_board);
    m.move(10, 4); //moving green token to
    //starting square to blue
    m.set_turn(); //blue's turn now
    m.move(6, 8); //collision should send green to yard
    CHECK(m.get_tokens()[4].get_status() == Status::yard);
    m.move(6, 9);
    m.move(6, 10);
    m.move(6, 11);
    //all blue tokens out of yard
    //to check game ending, let blue win by getting all tokens home.
    m.move(43, 8);
    m.move(43, 9);
    m.move(43, 10);
    m.move(43, 11);
    m.set_game_status();
    CHECK_FALSE(m.get_game_status());
}

TEST_CASE("Model constructor")
{
    Model m(4);
    CHECK(m.get_game_status() == true);
    CHECK(m.get_num_players() == 4);
    CHECK( m.get_turn() == Color::red);
}

TEST_CASE("Check Movement")
{
    Model m(2);
    CHECK(m.get_turn() == Color::red);
    CHECK(m.get_tokens()[0].get_status() == Status::yard);
    m.move(6, 0); //should be out of yard
    CHECK(m.get_tokens()[0].get_status() == Status::on_board);
    CHECK(m.get_game_status());
    CHECK(m.get_tokens()[0].get_squares_moved() == 0);
    CHECK(m.get_tokens()[0].get_square_number() == 0);
    CHECK(m.get_turn() == Color::red);
    CHECK(m.yards_[0].get_square_contents().size() == 3);
    m.move(3, 0);
    CHECK(m.get_tokens()[0].get_squares_moved() == 3);
    CHECK(m.get_tokens()[4].get_squares_moved() == 0);
    m.move(7, 1);
}

TEST_CASE("Check token initialization")
{
    Model m(3);
    CHECK(m.get_tokens().size() == 12);
    CHECK(m.get_tokens()[0].get_color() == Color::red);
    CHECK(m.get_tokens()[4].get_color() == Color::green);
    CHECK(m.get_tokens()[11].get_color() == Color::yellow);

    CHECK(m.get_tokens()[0].get_token_number() == 1);
    CHECK(m.get_tokens()[11].get_token_number() == 4);
}

TEST_CASE("Square functioning")
{
    Square s;
    Token t(Color::red, 1);
    CHECK(s.get_color() == Color::neither);
    s.add_token(1);
    CHECK(s.get_square_contents().size() == 1);
    s.remove_token(1);
    CHECK(s.get_square_contents().empty());
}
