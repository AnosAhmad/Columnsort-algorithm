#ifndef COLUMNSORT_H
#define COLUMNSORT_H

#include "utility.h"

class Columnsort
{
public:
	
	void columnSortAlgo();	
	bool SortCheck();	
	void read();
	void writeFile();	
	void triggerSort();

	void Transpose();
	void RTranspose();
	void shiftting(int stepNum);

	void quicksort(int idex, int first, int last);
	int partation(int idex,int first, int last);

private:
	std::vector<std::vector<short int>> arrayofint;	
	double runningTime;
};

#endif //COLUMNSORT_H