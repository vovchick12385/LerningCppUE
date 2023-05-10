#pragma once

#include <iostream>
#include <vector>
#include <string>

class Collection
{
public:

	explicit Collection(const std::vector<std::vector<int>>& in)
	{
		collection = in;
		colInfo = new std::string("New collection/n");
		LastInfo = new std::string("Last collection/n");
	}

	Collection(const Collection& other)
	{
		*this = other;
	}

	~Collection()
	{
		std::cout << "Destructor" << std::endl;
		delete colInfo;
		delete LastInfo;
	}

	Collection& operator=(const Collection& other)
	{
		collection = other.collection;
		colInfo = new std::string(*other.colInfo);
		LastInfo = new std::string(*other.LastInfo);
		return *this;
	}
private:
	std::vector<std::vector<int>> collection;
	std::string* colInfo;
	std::string* LastInfo;
};