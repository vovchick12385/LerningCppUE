#pragma once
#include <string>
#include <iostream>

class Item
{
public:
    Item()
    {
        ItemName = "none";
    }
    Item(const std::string& inItemName):ItemName(inItemName){}
    void ShotItemName()
    {
        std::cout << ItemName << " ";
    }

private:
    std::string ItemName;
};