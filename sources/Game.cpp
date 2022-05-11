#include "Game.hpp"
using namespace std;
using namespace coup;

constexpr int max_players_in_game = 6;


Game::Game()
{

    this->players_in_game = new vector<Player *>[max_players_in_game];
    this->game_is_on = false;

    this->last_forighn = NULL;
    this->last_couped = NULL;
    this->stolen_amount = NULL;

    this->current_palyer_turn = 0;
}

Game::~Game()
{
    delete[] this->players_in_game;
}


void Game::save_player(Player *player) const
{
    this->players_in_game->insert(this->players_in_game->begin() + (player->change - 1), player);
}


bool Game::player_turn(const Player &player) const
{

    if (player.online)
    {
        return (this->players_in_game->at(this->current_palyer_turn % this->players_in_game->size()) == &player);
    }
     throw std::invalid_argument("Player is offline");
}




void Game::delete_from_game(Player &player) const
{
    bool ans = false;

    for (unsigned int i = 0; i < this->players_in_game->size(); i++)
    {
        if (this->players_in_game->at(i) == &player)
        {
            this->players_in_game->erase(this->players_in_game->begin() + i);
            ans = true;
            break;
        }
    }

    if (ans)
    {
        throw invalid_argument("the player is not in the game");
    }
}

void Game::add_to_game(Player *player) const
{
    if (this->game_is_on)
    {
        throw std::runtime_error("Game is running");
    }
    if (this->players_in_game->size() >= max_players_in_game)
    {
        throw invalid_argument("can't add more players!");
    }

    this->players_in_game->push_back(player);

    player->change = this->players_in_game->size();
}


void Game::game_turn()
{
    while (true)
    {
        this->current_palyer_turn++;

        if (this->players_in_game->at(this->current_palyer_turn % this->players_in_game->size())->online)
        {
            break;
        }
    }
}

vector<string> Game::players() const
{
    vector<string> vec;

    for (unsigned int i = 0; i < this->players_in_game->size(); i++)
    {
        if (this->players_in_game->at(i)->online)
        { 
            vec.push_back(this->players_in_game->at(i)->Name);
        }

    }
    
    return vec;

}


string Game::turn() const
{

    return this->players_in_game->at(current_palyer_turn)->Name;
}


string Game::winner() const
{
    if (!this->game_is_on)
    { 
        throw std::runtime_error("Game haven't started yet");
    }

    int count = 0;

    Player * winning_player = NULL;

    for (unsigned int i = 0; i < this->players_in_game->size(); i++)
    {
        if (this->players_in_game->at(i)->online)
        { 
            count++;
            winning_player = this->players_in_game->at(i);
        }
    }
    if (count == 1)
    {
        return winning_player->Name;
    }

    throw std::runtime_error("No one won the game yet!");
    
}