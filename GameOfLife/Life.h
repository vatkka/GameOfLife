/* Dmitrii Frolov U214N1483
* COMP-211 (Section 01) Data Structures
* Assignment 1 - Game of Life
*/
#pragma once
#include <iostream>
using namespace std;
#include "utilities.h"
const int maxrow = 20;
const int maxcol = 60;
void welcome();
enum status { dead, alive };
class Life {
public:
	void initialize();
	void print() const;
	void update();
private:
	int neighborCount(int, int) const;
	status grid[maxrow][maxcol];
	status clone[maxrow][maxcol];
};
