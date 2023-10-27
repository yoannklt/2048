#include "test.hpp"

Test::Test()
{
	
}

Test::~Test()
{

}

void Test::level(int digit)
{
	if (digit == 1)
	{
		tab[0][0].setValue(2);
	}
	else if(digit == 2)
	{
		tab[0][0].setValue(2);
		tab[0][1].setValue(2);
	}
	else if (digit == 3)
	{
		tab[0][0].setValue(2);
		tab[0][1].setValue(4);
		tab[0][2].setValue(2);
	}
}