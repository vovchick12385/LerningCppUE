#include "Vector.h"
#include "Collection.h"
#include "Player.h"
#include "Item.h"

int main()
{
	Player* newPlayerA = new Player("Vasya", Vector(1,0,0));
	Player* newPlayerB = new Player("Petya", Vector(1,0,0));
	Item* newItem = new Item("Sword");
	
	newPlayerA->SetNewItem(newItem);
	PlayersParty PlayersAB;
	PlayersAB.AddPlayerToPerty(newPlayerA);
	PlayersAB.AddPlayerToPerty(newPlayerB);
	PlayersAB.ShowAllPlayerInfo();
	return 0;
}