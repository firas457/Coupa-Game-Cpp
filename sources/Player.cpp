#include "Player.hpp"

constexpr int coup_player = 10;
constexpr int coup_cost1 = 7;
constexpr int coup_cost2 = 3;

using namespace coup;
using namespace std;

Player::Player(Game &game, const string &name, const string &role)
{
    this->online = true;
    this->coup_changer = false;
    this->Name = name;
    this->last_play = "";
    this->money = 0;
    this->role_ch = role;
    this->game = &game;
    this->change = 0;
    this->game->add_to_game(this);
}

string Player::role() const
{
    return this->role_ch;
}

void Player::income()
{
    if (!this->game->player_turn(*this))
    {
        throw runtime_error("wait for your turn!");
    }

    if (this->money >= coup_player)
    {
        throw std::runtime_error("can't coup with this amount of coins!");
    }

    if (this->game->players().size() == 1)
    {
        throw std::runtime_error("you need to players at least!");
    }

    if (this->game->player_turn(*this))
    {
        this->game->game_is_on = true;
        this->money++;

        this->last_play = "income";
        this->game->game_turn();
    }
}

void Player::foreign_aid()
{
    if (!this->game->player_turn(*this))
    {
        throw runtime_error("wait for your turn!");
    }

    if (this->game->players().size() == 1)
    {
        throw std::runtime_error("you need at least two players!");
    }

    if (this->money >= coup_player)
    {
        throw std::runtime_error("can't coup with this amount of coins!");
    }

    if (this->game->player_turn(*this))
    {
        this->game->game_is_on = true;
        this->money += 2;

        this->last_play = "foreign_aid";
        this->game->game_turn();
    }
}

int Player::coins() const
{
    return this->money;
}

void Player::coup(Player &player)
{
    if (this->game->players().size() == 1)
    {
        throw std::runtime_error("you need at least two players!");
    }

    if (!this->game->player_turn(*this))
    {
        throw std::invalid_argument("wait for your turn!");
    }

    if (this->game->player_turn(*this))
    {
        if (!player.online)
        {
            throw std::invalid_argument("player is not online!");
        }

        if (player.online)
        {
            if (this->role() == "Assassin")
            {
                if (this->coins() >= coup_cost1)
                {
                    this->money -= coup_cost1;
                    player.online = false;
                    this->last_play = "coup";

                    this->game->last_couped = &player;
                    this->coup_changer = true;

                    this->game->game_turn();
                }

                else if (this->coins() >= coup_cost2)
                {
                    this->money -= coup_cost2;
                    player.online = false;
                    this->last_play = "coup";
                    this->game->last_couped = &player;
                    this->coup_changer = false;
                    this->game->game_turn();
                }
                else
                {
                    throw std::invalid_argument("at least three coins needed to perform");
                }
            }

            else
            {
                if (this->coins() < coup_cost1)
                {
                    throw std::runtime_error("more coins needed to perform");
                }

                if (this->coins() >= coup_cost1)
                {
                    this->money -= coup_cost1;
                    player.online = false;
                    this->last_play = "coup";
                    this->game->last_couped = &player;
                    this->game->game_turn();
                }
            }
        }
    }
}
