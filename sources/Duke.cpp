#include "Duke.hpp"

using namespace coup;

Duke::Duke(Game &game, const string &name) : Player(game, name, "Duke")
{
}

void Duke::block(Player &player)
{
    if (player.last_play != "foreign_aid")
    {
        throw runtime_error("last play should be foreign_aid");
    }

    if (player.last_play != "foreign_aid")
    {
        player.money = player.money - 2;
    }
}

void Duke::tax()
{

    if (!this->game->player_turn(*this))
    {
        throw invalid_argument("wait for your turn!");
    }

    if (this->game->players().size() == 1)
    {
        throw std::runtime_error("you need at least two players!");
    }

    if (this->game->player_turn(*this))
    {
        this->game->game_is_on = true;

        this->money += 3;
        this->game->game_turn();
    }
}
