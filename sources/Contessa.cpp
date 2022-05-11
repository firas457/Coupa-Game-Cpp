#include "Contessa.hpp"
#include "Assassin.hpp"

using namespace coup;

Contessa::Contessa(Game &game, const string &name) : Player(game, name, "Contessa")
{
}

void Contessa::block(Player &player)
{

    if (player.last_play != "coup" || !(player.online))
    {
        throw std::invalid_argument("Can block only coup");
    }


    if (player.last_play == "coup" && player.online)
    {
        if (player.role() == "Assassin" && player.coup_changer)
        {
            throw std::invalid_argument("can't block");
        }


        game->last_couped->online = true;

        game->last_couped = NULL;
    }

}