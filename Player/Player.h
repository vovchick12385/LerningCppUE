#pragma once
#include <ostream>

#include <string>
#include <iostream>
#include "Vector.h"
#include "Item.h"
#include "Guild.h"


class Player
{
public:
    Player()
    {
        PlayerName = "none";
    }
    Player(const std::string& PlayerName_, Vector location): Location(location), PlayerName(PlayerName_){};
    
    void ShowPlayerInfo()
    {
        std::cout<< PlayerName << " at location: "<< Location << std::endl;
        std::cout<< PlayerName << " has ";
        if(item)
        {
            item->ShotItemName();
            return;
        }
        std::cout<< "none"<< std::endl;
        
    }
    void SetNewItem(Item* newItem)
    {
        item = newItem;
    }
    void Join(Guild* newGuild)
    {
        Guilds.push_back(newGuild);
    }
    void LeaveFromGuild(Guild* guild)
    {
        
    }
private:
    Vector Location;
    Item* item;
    std::vector<Guild*> Guilds; 
    std::string PlayerName;
  
};

class PlayersParty
{
public:
    PlayersParty()
    {
        players = new Player*[4];
    }
    void AddPlayerToPerty(Player* newPlayer)
    {
        if(current >= 4)
            return;
        players[current] = newPlayer;
        current++;
    }

    void ShowAllPlayerInfo()
    {
        for(int i=0;i<current;++i)
        {
            players[i]->ShowPlayerInfo();
        }
    }
private:
    Player** players;
    int current =0;
};
