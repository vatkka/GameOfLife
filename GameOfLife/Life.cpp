/* Dmitrii Frolov U214N1483
* COMP-211 (Section 01) Data Structures
* Assignment 1 - Game of Life
*/
#include "Life.h"
void Life::initialize(){
	int row, col;
	for (row = 0; row < maxrow; row++)
		for (col = 0; col < maxcol; col++)
			grid[row][col] = dead;
	cout << "Enter row and column of living cells " <<
		"and finish with -1 -1" << endl;
	while ((row != -1) || (col != -1)) {
		cin >> row >> col;
		if (row == -1 && col == -1)
			cout << "Done" << endl;
		else if ((row < 0) || (row >= maxrow))
			cout << "Row out of range" << endl;
		else if ((col < 0) || (col >= maxcol))
			cout << "Column out of range" << endl;
		else
			grid[row][col] = alive;
	}
}
void Life::print() const{
	for (int row = 0; row < maxrow; row++) {
		for (int col = 0; col < maxcol; col++)
			if (grid[row][col] == alive) cout << "*";
			else cout << " ";
		cout << endl;
	}
}
/*This function countng number of alive neighbors and return int*/
int Life::neighborCount(int row, int col) const{
	int count = 0;
	if (grid[row - 1][col - 1] == alive) count++;
	if (grid[row - 1][col] == alive) count++;
	if (grid[row - 1][col + 1] == alive) count++;
	if (grid[row][col + 1] == alive) count++;
	if (grid[row + 1][col + 1] == alive) count++;
	if (grid[row + 1][col] == alive) count++;
	if (grid[row + 1][col - 1] == alive) count++;
	if (grid[row][col - 1] == alive) count++;
	return(count);
}
void Life::update(){
	system("CLS");
	for (int row = 0; row < maxrow; row++) {
		for (int col = 0; col < maxcol; col++) {
			if (grid[row][col] == alive) {
				if (neighborCount(row, col) == 2 || neighborCount(row, col) == 3) {
					clone[row][col] = alive;
				}
				else {
					clone[row][col] = dead;
				}
			}
			else {
				if (neighborCount(row, col) == 3) {
					clone[row][col] = alive;
				}
				else {
					clone[row][col] = dead;
				}
			}
		}
	}
	for (int row = 0; row < maxrow; row++) {
		for (int col = 0; col < maxcol; col++) {
			if (clone[row][col] == alive) {
				grid[row][col] = alive;
				clone[row][col] = dead;
			}
			else {
				grid[row][col] = dead;
				clone[row][col] = dead;
			}
		}
	}
}
void welcome(){
	cout << "Welcome to the game of life" << endl << endl;
}