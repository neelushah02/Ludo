#include "controller.hxx"

//constructor
Controller::Controller(int num_players)
            :model_(num_players)
            ,view_(model_)
{}

void Controller::draw(ge211::Sprite_set &set)
{
    view_.draw(set, model_);
}


void Controller::on_mouse_down(ge211::Mouse_button,  ge211::Position pos)
{
    if(model_.get_game_status())
    {

        int sq_num = view_.screen_to_board(pos);
        Color turn = model_.get_turn();

        for(int i = 0; i<(model_.get_num_players()*4); i++)
        {

            if(model_.get_tokens()[i].get_status()==Status::on_board
            && model_.get_tokens()[i].get_square_number()==sq_num
            && model_.get_tokens()[i].get_color()==turn)
            {
                model_.move(model_.get_dice_val(), i);
               // model_.set_turn();
                break;
            }
            else if(model_.get_tokens()[i].get_color()==turn
            &&      model_.get_tokens()[i].get_status()==Status::yard
            &&      model_.get_dice_val()==6)
            {
                model_.move(model_.get_dice_val(), i);
                //model_.set_turn();
                break;
            }
            else if(model_.get_dice_val()!=6 && model_.all_four_not_on_path())
            {
                //model_.set_turn();
            }
        }
        model_.set_game_status();
    } else{
        quit();
    }

}

void Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
   {
        quit();

   }
    else if (key == ge211::Key::code(' '))
    {
        model_.set_turn();
        roll();
    }
}
std::string Controller::initial_window_title() const
{
    return "Ludo, but with features";
}
void Controller::roll()
{
    int a = get_random().between(1,6);
    model_.set_dice_val(a);
}

//TO-ADD:
//4. add input of no. of players (2-4)
