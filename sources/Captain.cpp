#include "Captain.hpp"
#include <algorithm>

using namespace coup;
using namespace std;

Captain::Captain(Game &game, const string &name) : Player(game, name, "Captain")
{
}

void Captain::steal(Player &player)
{

      if (!this->game->player_turn(*this))
    {
        throw std::invalid_argument("wait for your turn");
    }


    if (this->game->players().size() == 1)
    {
        throw std::runtime_error("at least two player needed!");
    }


    if (this->game->player_turn(*this))
    {
        this->game->game_is_on = true;

        if (!player.online)
        {
            throw std::invalid_argument("you can only steal online players");
        }

        if (player.online)
        {
            int min = 0;

            if (2 < player.money)
            {
                min = 2;
            }
            if (2 >= player.money)
            {
                min = player.money;
            }

            this->money = this->money + min;
            player.money -= min;

            this->money_recived = min;

            this->game->stolen_amount = &player;
            this->last_play = "steal";

            this->game->game_turn();
        }
    }

}

void Captain::block(Player &player)
{
    if (player.last_play != "steal")
    {
        throw std::invalid_argument("block only works with steal!");
    }

    if (player.last_play == "steal")
    {
        if (game->stolen_amount->online && player.online)
        {
            player.money = player.money - 2;
            game->stolen_amount->money += 2;
            game->stolen_amount = NULL;
        }
    }
}
