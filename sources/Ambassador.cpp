#include "Captain.hpp"
#include "Ambassador.hpp"

using namespace std;
using namespace coup;

Ambassador::Ambassador(Game &game, const string &name) : Player(game, name, "Ambassador")
{
}


void Ambassador::block(Player &player)
{
    if (this->game->players().size() != 1)
    {

        if (player.last_play != "steal")
        {
            throw std::invalid_argument(" needs two players at least to work");
        }

        if (player.last_play == "steal")
        {
            this->game->stolen_amount->money += player.money_recived;

            player.money = player.money - player.money_recived;

            this->game->stolen_amount = NULL;
        }
    }
}


void Ambassador::transfer(Player &p1, Player &p2)
{
    if (this->game->players().size() != 1)
    {

        if (this->game->player_turn(*this))
        {

            this->game->game_is_on = true;

            if (p1.online && p2.online)
            {

                if (p1.money <= 0)
                {
                    throw std::invalid_argument("can't transfer");
                }

                if (p1.money > 0)
                {
                    p1.money = p1.money - 1;
                    p2.money = p2.money + 1;

                    this->game->game_turn();
                }
            }

            else
            {

                throw std::invalid_argument("player is not online");
            }
        }
    }

    else
    {

        throw std::invalid_argument("wait for your turn!");
    }
}
