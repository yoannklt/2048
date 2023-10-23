#include <iostream>

void displayGrid(int tableau[4][4]);

int main(int argc, char* argv[])
{
	int tableau[4][4] = { 0 };

	displayGrid(tableau);

	return 0;
}

void displayGrid(int tableau[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << tableau[i][j] << ' ';
		}
		std::cout << "\n";
	}

}