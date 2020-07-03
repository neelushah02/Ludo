#include "model.hxx"
#include <vector>

//functions for token

//Constructor
Token::Token(Color color, int token_number)
        :color_(color)
        ,token_number_(token_number)
        ,squares_moved_(0)
        ,status_(Status::yard)
        ,square_number_()
//square number isn't initialized at construction, it happens
//later
{}
Color Token::get_color()
{
    return color_;
}
Status Token::get_status()
{
    return status_;
}
int Token::get_square_number()
{
    return square_number_;
}
int Token::get_token_number()
{
    return token_number_;
}
int Token::get_squares_moved()
{
    return squares_moved_;
}


bool Token::set_square_number(int dice_roll)
{
    if(status_==Status::yard && dice_roll==6)
    {
        if(color_ == Color::red)
            square_number_ = 0;
        else if (color_ == Color::green)
            square_number_ = 10;
        else if (color_ == Color::yellow)
            square_number_ = 20;
        else if (color_ == Color::blue)
            square_number_ = 30;

        status_ = Status::on_board;
        return true;
    }
    //how about switch case, where for all colours if sq. moved + dice roll > 38
    //that's the victory path case--when a color is moving onto its victory path
    //every color has a separate victory path rule--green for example jumps from
    //8 to 45, red from 38 to 40, blue from 28 to 55, yellow from 18 to 50
    //otherwise, for all colors, as long as square number + dice roll < 40,
    // it's just simple addition.
    //else, you have to make a subtract 40 leap.
    if ( squares_moved_ + dice_roll < 39) //checks whether headed to vic path
    {
        if ( square_number_ + dice_roll < 40)
        {
            square_number_ += dice_roll;
            set_squares_moved(dice_roll);
            return true;
        } else
        {
            square_number_ = square_number_ + dice_roll - 40;
            set_squares_moved(dice_roll);
            return true;
        }
    }
    else if ( squares_moved_ + dice_roll > 38 && squares_moved_ + dice_roll <
                                                 44 )
    {
        int remainder = squares_moved_ + dice_roll - 39;
        //go to remainder th position of victory path starting with zero


        if( color_ == Color::red)
            square_number_ = 40 + remainder;
        else if(color_ == Color::green)
            square_number_ = 45 + remainder;
        else if (color_ == Color::yellow)
            square_number_ = 50 + remainder;
        else if(color_ == Color::blue)
            square_number_ = 55 + remainder;

        if(remainder == 4)
        {
            status_=Status::finished;
        }
        set_squares_moved(dice_roll);
        return true;
    }
    return false;
}

void Token::set_squares_moved(int dice_roll)
{
    squares_moved_+=dice_roll;
}

void Token::set_status(Status status)
{
    status_=status;
}

//functions for square
Square::Square()
        :color_(Color::neither)
        ,square_contents_()
{}
Square::Square(Color color)
        :color_(color)
        ,square_contents_()
{}
Color Square::get_color()
{
    return color_;
}
void Square::add_token(int t_num)
{
    square_contents_.push_back(t_num);
}


void Square::remove_token(int t_num)
{
    for ( int i = 0; i < square_contents_.size(); i++)
    {
        if(square_contents_[i] == t_num)
        {
            std::swap(square_contents_.back(), square_contents_[i]);
            square_contents_.pop_back();
        }
    }

}
std::vector<int> Square::get_square_contents()
{
    return square_contents_;
}

//model functions

Model::Model(int num_players)
        :no_of_players_(num_players)
        ,no_of_tokens_(4*num_players)
        ,game_status_(true)
        ,turn_(Color::red)
        ,dice_val_(0)
{

    //initializing path_
    for(int i=0; i<60; i++)
    {
        if(i<=39)
        {
            Square sq;
            path_.push_back(sq);
        }
        else if(i>=40 && i<=44)
        {
            Square sq(Color::red);
            path_.push_back(sq);
        }
        else if(i>=45 && i<=49)
        {
            Square sq(Color::green);
            path_.push_back(sq);
        }
        else if(i>=50 && i<=54)
        {
            Square sq(Color::yellow);
            path_.push_back(sq);
        }
        else if(i>=55 && i<=59)
        {
            Square sq(Color::blue);
            path_.push_back(sq);
        }
    }

    //initializing yards_
    for(int k = 0; k<no_of_players_; k++)
    {
        if (k==0)
        {
            Square sq(Color::red);
            yards_.push_back(sq);
        }
        else if(k==1)
        {
            Square sq(Color::green);
            yards_.push_back(sq);
        }
        else if(k==2)
        {
            Square sq(Color::yellow);
            yards_.push_back(sq);
        }
        else if(k==3)
        {
            Square sq(Color::blue);
            yards_.push_back(sq);
        }
    }
    //initializing tokens and adding them to yard
    for(int j = 0; j<no_of_tokens_; j++)
    {
        if(j<4)
        {
            Token tk(Color::red, j+1);

            tokens_.push_back(tk);
            yards_[0].add_token(j);
        }
        else if(j>=4 && j<8)
        {
            tokens_.push_back(Token (Color::green, j-3));
            yards_[1].add_token(j);
        }
        else if(j>=8 && j<12)
        {
            tokens_.push_back(Token (Color::yellow, j-7));
            yards_[2].add_token(j);
        }
        else if(j>=12 && j<16)
        {
            tokens_.push_back(Token (Color::blue, j-11));
            yards_[3].add_token(j);
        }
    }
}

bool Model::get_game_status() const
{
    return game_status_;
}
int Model::get_num_players() const
{
    return no_of_players_;
}
Color Model::get_turn() const
{
    return turn_;
}
void Model::set_turn()
{
    if(get_turn()==Color::red)
    {
        turn_=Color::green;
    }
    else if(get_turn()==Color::green)
    {
        if(no_of_players_==2)
            turn_=Color::red;
        else
            turn_=Color::yellow;
    }
    else if(get_turn()==Color::yellow)
    {
        if(no_of_players_==3)
            turn_=Color::red;
        else
            turn_=Color::blue;
    }
    else if(get_turn()==Color::blue)
    {
        turn_=Color::red;
    }
    //remember to adjust situation for when one player is done--
    //they shouldn't get to play again, turn should move on.
}
void Model::set_game_status()
{
    bool temp = false;
    for(int i = 0; i<no_of_players_; i++) //colors
    {
        temp = false;
        for(int j =0; j<4; j++)//tokens
        {
            if (tokens_[i*4 + j].get_status() != Status::finished)
             temp = true;
        }
        if(!temp)
            break;
    }
    game_status_ = temp;
}


void Model::collision(int square_number)
{
    if(path_[square_number].get_square_contents().empty())
    {
        return;
    } else
    {
        int newcomer = path_[square_number].get_square_contents().back();
        Color newcomer_color = tokens_[newcomer].get_color();
        for(int i : path_[square_number].get_square_contents())
        {
            if(tokens_[i].get_color()!=newcomer_color)
            {
                tokens_[i].set_status(Status::yard);
                tokens_[i].set_squares_moved(0 - (tokens_[i].get_squares_moved()) );
                Color c = tokens_[i].get_color();
                if(c == Color::red)
                    yards_[0].add_token(i);
                else if (c == Color::green)
                    yards_[1].add_token(i);
                else if (c == Color::yellow)
                    yards_[2].add_token(i);
                else if (c == Color::blue)
                    yards_[3].add_token(i);

                path_[square_number].remove_token(i);
            }
        }
        //collision rule: newcomer kicks out first token not of same color.
    }
}

std::vector<Token> Model::get_tokens() const
{
    return tokens_;
}

void Model::move(int dice_roll, int token_num)
{
    int color_num = 0;
     if(turn_ == Color::red)
        color_num = 0;
     else if(turn_ == Color::green)
         color_num = 1;
     else if(turn_ == Color::yellow)
         color_num = 2;
     else if(turn_ == Color::blue)
         color_num = 3;

    int t_moved = token_num;
    if (tokens_[t_moved].get_status() != Status::yard) {
        int  old_position = tokens_[t_moved].get_square_number();
        bool temp         = tokens_[t_moved].set_square_number(dice_roll);
        if (temp) {
            path_[tokens_[t_moved].get_square_number()].add_token(t_moved);
            path_[old_position].remove_token(t_moved);//remove_token
            collision(tokens_[t_moved].get_square_number());
        }
    }
    else{
        bool temp = tokens_[t_moved].set_square_number(dice_roll);

        if (temp) { //if not on yard and dice_roll == 6, squares_moved_ is
            // still zero
            path_[tokens_[t_moved].get_square_number()].add_token(t_moved);
            yards_[color_num].remove_token(t_moved);
            collision(tokens_[t_moved].get_square_number());
        }
    }

}

void Model::set_dice_val(int roll) {
    dice_val_= roll;
}

int Model::get_dice_val() const {
    return dice_val_;
}

std::vector<Square> Model::get_path() const
{
    return path_;
}

bool Model::all_four_not_on_path()
{
    int color_num = 0;
    if(turn_ == Color::red)
        color_num = 0;
    else if(turn_ == Color::green)
        color_num = 1;
    else if(turn_ == Color::yellow)
        color_num = 2;
    else if(turn_ == Color::blue)
        color_num = 3;

    return (tokens_[color_num*4].get_status()!=Status::on_board&&
            tokens_[color_num*4+1].get_status()!=Status::on_board&&
            tokens_[color_num*4+2].get_status()!=Status::on_board&&
            tokens_[color_num*4+3].get_status()!=Status::on_board);
}