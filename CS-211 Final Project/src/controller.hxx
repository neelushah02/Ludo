#pragma once
#include <ge211.hxx>
#include "model.hxx"
#include "view.hxx"

class Controller : public ge211::Abstract_game
{
public:
    //constructor
    Controller(int num_players = 4);

protected:
    void draw(ge211::Sprite_set& set) override;
    void on_mouse_down(ge211::Mouse_button, ge211::Position) override ;
    void on_key(ge211::Key) override ;
    std::string initial_window_title() const override;
    void roll();

private:
    // private data members
    Model model_;
    View view_;



};

