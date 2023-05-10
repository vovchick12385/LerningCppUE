#pragma once

#include <vector>
#include <algorithm>

class Player;

class Guild
{
public:
    Guild();
    void AddNewPlayer(Player* newPlayer)
    {
        Players.push_back(newPlayer);
    }
    void RemovePlayer(Player* newPlayer)
    {
        auto player = std::find(Players.begin(),Players.end(), newPlayer);
        if( player != Players.end())
            Players.erase(player);
    }
private:
    std::vector<Player*> Players; 
};