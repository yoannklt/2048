#include "grid.hpp"

Grid::Grid()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			tab[i][j] = Cell();
		}
	checkEmptyCell();
	checkEmptyCell();
}

int Grid::randomValue()
{
	srand(static_cast<unsigned>(time(0)));

	int randomValue = (rand() % 2) == 0 ? 2 : 4;
	return randomValue;
}

void Grid::checkEmptyCell()
{
	std::vector<Cell*> emptyCellGrid; 
	int emptyCellNumber = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (tab[i][j].getValue() == 0)
			{
				emptyCellNumber++;
				emptyCellGrid.push_back(&tab[i][j]);
			}

	if (emptyCellNumber == 0) {
		this->lost = true;
		return;
	}

	int randomNumber = rand() % emptyCellNumber; 

	emptyCellGrid[randomNumber]->setValue(randomValue());
}

void Grid::slide() {
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			for (int k = 0; k < j; k++) {
				if (tab[i][3 - j + k].getValue() != 0 and tab[i][3 - j + k + 1].getValue() == 0) {
					tab[i][3 - j + k + 1].setValue(tab[i][3 - j + k].getValue());
					tab[i][3 - j + k].setValue(0);
				}
				else if (tab[i][3 - j + k].getValue() != 0 and tab[i][3 - j + k].getValue() == tab[i][3 - j + k + 1].getValue() and !tab[i][3 - j + k + 1].isMerge()) {
					tab[i][3 - j + k + 1].setValue(tab[i][3 - j + k].getValue() * 2);
					tab[i][3 - j + k].setValue(0);
				}
			}
		}
	}
	checkEmptyCell();
}

void Grid::render() {

	system("cls");

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