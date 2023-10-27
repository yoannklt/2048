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
	for (int row = 0; row < 4; row++) {

		for (int i = 3; i >= 0; i--) {

			Cell& oCell1 = tab[row][i];
			int iValue1 = oCell1.getValue();
			for (int iCompare = i - 1; iCompare >= 0; iCompare--) 
			{
				Cell& oCell2 = tab[row][iCompare];
				int iValue2 = oCell2.getValue();
				if (iValue2 == 0)
					continue;

				if (iValue1 == 0) {
					oCell1.setValue(iValue2);
					oCell2.setValue(0);
					emptyCellGrid.push_back(&oCell2);    
					i++;
					break;
				}

				if (iValue1 == iValue2) {
					oCell1.setValue(iValue1 + iValue2);
					oCell2.setValue(0);
					emptyCellGrid.push_back(&oCell2);
					break;
				}
				break;
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

void Grid::swapCell(Cell* cell1, Cell* cell2)
{
	Cell* intermediateCell = cell1;
	*cell1 = *cell2;
	*cell2 = *intermediateCell;
}