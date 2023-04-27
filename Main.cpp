#include "Vector.h"
#include "Collection.h"

int main()
{
	std::vector<std::vector<int>> in{
		{1,2,3,4},
		{2,5,6,8},
		{5,1,2}
	};
	std::vector<std::vector<int>> i1n{
		{5,1},
		{2,5},
		{3,3,3}
	};
	Collection newCol(in);
	Collection newCol1(newCol);
	Collection newCol2(i1n);
	newCol1 = newCol2;
	return 0;
}