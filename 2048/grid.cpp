#include "grid.hpp"

Grid::Grid()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			tab[i][j] = Cell();
		}
}

int Grid::randomValue()
{
	srand(static_cast<unsigned>(time(0)));

	int randomValue = (rand() % 2) == 0 ? 2 : 4;
	return randomValue;
}

void Grid::checkEmptyCell()
{
	int emptyCellNumber = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tab[i][j].getValue() == 0) 
				emptyCellNumber++;
		}
	}

	if (emptyCellNumber == 0) {
		this->lost = true;
		return;
	}

	int randomNumber = rand() % emptyCellNumber + 1;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (tab[x][y].getValue() == 0) 
			{
				randomNumber--;
				if (randomNumber == 0) {
					tab[x][y].setValue(randomValue());
					std::cout << "coubeh";
					return;
				}
			}
		}
	}
}

void Grid::slide() {
	for (int row = 0; row < 4; row++) {

		for (int i = 3; i >= 0; i--) {

			for (int iCompare = 0; iCompare < i; iCompare++) {
				
				Cell i1 = tab[row][i];
				int i1Value = tab[row][i].getValue();

				Cell i2 = tab[row][iCompare];
				int i2Value = tab[row][iCompare].getValue();

				if (i2Value == 0) {
					continue;
				}

				if (i1Value == 0) {
					i1.setValue(i2Value);
					i2.setValue(0);
					i++;
					break;
				}

				if (i1Value == i2Value) {
					i1.setValue(i1Value + i2Value);
					i2.setValue(0);
					break;
				}
			}
		}
	}
	checkEmptyCell();
}

void Grid::render() {

	//system("cls");

	if (hasLost()) {  
		return;
	}
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << " " << "-----------------" << std::endl << " | ";
		for (int j = 0; j < 4; j++)
		{
			switch (tab[i][j].getValue()) 
			{
			case 0:
				std::cout << "  | ";
				break;

			default:
				std::cout << tab[i][j].getValue() << " | "; 
				break;
			}
		}
		std::cout << std::endl;

	}
	std::cout << " " << "-----------------" << std::endl;
}