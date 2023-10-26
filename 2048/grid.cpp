#include "grid.hpp"

Grid::Grid()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (tab[i][j].getValue() == 0)
				emptyCellGrid.push_back(&tab[i][j]);

	srand(static_cast<unsigned>(time(0)));

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			tab[i][j] = Cell();
		}
	generateRandomCell();
	generateRandomCell();
} 

int Grid::randomValue()
{
	int randomValue = (rand() % 2) == 0 ? 2 : 4;
	return randomValue;
}

void Grid::generateRandomCell()
{

	if (emptyCellGrid.empty()) {
		this->lost = true;
		return;
	}

	int randomNumber = rand() % emptyCellGrid.size();

	emptyCellGrid[randomNumber]->setValue(randomValue()); 
	emptyCellGrid.erase(emptyCellGrid.begin() + randomNumber); 
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
	generateRandomCell();
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