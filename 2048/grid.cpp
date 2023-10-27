#include "grid.hpp"

#include <iostream>

Grid::Grid()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			tab[i][j] = new Cell();
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (tab[i][j]->getValue() == 0)
				emptyCellGrid.push_back(tab[i][j]);

	srand(static_cast<unsigned>(time(0)));

	generateRandomCell(0);
	generateRandomCell(0);
} 

int Grid::randomValue()
{
	int randomValue = 2;// (rand() % 2) == 0 ? 2 : 4;
	return randomValue;
}

void Grid::generateRandomCell(int i /*= -1*/)
{
	if (emptyCellGrid.empty()) {
		this->lost = true;
		return;
	}

	int randomNumber = i;
	if(randomNumber == -1 )
		randomNumber = rand() % emptyCellGrid.size();

	emptyCellGrid[randomNumber]->setValue(randomValue()); 
	emptyCellGrid.erase(emptyCellGrid.begin() + randomNumber); 
}

void Grid::slide() {
	int iAdd = 0;
	if (directionVect[1] == -1) {
		iAdd = 3;
	}
	int yAdd = 0;
	if (directionVect[0] == -1) {
		yAdd = 3;
	}

	for (int row = 0; row < 4; row++) {

		for (int i = 3; i >= 0; i--) {

			int indexOne = row * (directionVect[0] * directionVect[0]) + directionVect[1] * i + iAdd;
			int indexTwo = row * (directionVect[1] * directionVect[1]) + directionVect[0] * i + yAdd;
			Cell** oCell1 = &tab[indexOne][indexTwo];
			int iValue1 = (*oCell1)->getValue();
			for (int iCompare = i - 1; iCompare >= 0; iCompare--) 
			{
				Cell** oCell2 = &tab[row][iCompare];
				int iValue2 = (*oCell2)->getValue();
				if (iValue2 == 0)
					continue;

				if (iValue1 == 0) {
					swapCell(oCell1, oCell2);   
					i++;
					break;
				}

				if (iValue1 == iValue2) {
					(*oCell1)->setValue(iValue1 + iValue2);
					(*oCell2)->setValue(0);
					emptyCellGrid.push_back(*oCell2);
					break;
				}

				break;
			}
		}
	}
	directionVect[0] = 0;
	directionVect[1] = 0;
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
			switch (tab[i][j]->getValue()) 
			{
			case 0:
				std::cout << "  | ";
				break;

			default:
				std::cout << tab[i][j]->getValue() << " | "; 
				break;
			}
		}
		std::cout << std::endl;

	}
	std::cout << " " << "-----------------" << std::endl;
}

void Grid::swapCell(Cell** cell1, Cell** cell2)
{
	Cell* intermediateCell = *cell1;
	*cell1 = *cell2;
	*cell2 = intermediateCell;
}