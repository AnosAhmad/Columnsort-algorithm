#include "utility.h"

#define R 4000 // represent the # of rows
#define S 25// represent the # of columns
#define PInf 32767
#define NInf -32767

Timerr timerobj;
vector<short int> temp;


/**
* CulmnSort Algorithm.
*/
void Columnsort::columnSortAlgo()
{
	
	/* Read the data */
	read();

	timerobj.reset();
	
	// Step #1 
	for (int i = 0; i < arrayofint[0].size(); ++i)
	{
		
		quicksort(i, 0, (arrayofint.size()- 1));
	}
	
	/* Step #2 */
	Transpose();

	// Step #3 
	for (int i = 0; i < arrayofint[0].size(); ++i)
	{

		quicksort(i, 0, (arrayofint.size() - 1));
	}
	
	/* Step #4 */
	RTranspose();

	// Step #5 
	for (int i = 0; i < arrayofint[0].size(); ++i)
	{

		quicksort(i, 0, (arrayofint.size() - 1));
	}
	

	/* Step #6 */
	shiftting(6); 

	/* Step #7 */
	for (int i = 0; i < arrayofint[0].size(); ++i)
	{

		quicksort(i, 0, (arrayofint.size() - 1));
	}
	
	/* Step #8 */
	shiftting(8);

	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	cout << "\nRunning Time for ColumnSort Algorithm is: " << (runningTime) << " Second\n\t\t\t\t\t  " << (runningTime*1000) <<" millisecond"<< endl;

	if (SortCheck()){
		cout << "\nIt is Sorted" << endl;
	}
	

	/* Write to text File */
	writeFile();

}

/**
* Quicksort.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
*/
void Columnsort::quicksort(int idex, int first, int last)
{
	int pivotElement;
	if (first < last)
	{
		pivotElement = partation(idex, first, last);
		quicksort(idex, first, (pivotElement - 1));
		quicksort(idex, (pivotElement + 1), last);
	}
}

/**
* Find and return the index of pivot element.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
* @return - the pivot element index.
*/
int Columnsort::partation(int idex, int first, int last)
{
	short int pivot = arrayofint[last][idex];
	int i = first - 1, temp;

	for (int j = first; j <= last - 1; j++)
	{
		if (arrayofint[j][idex] <= pivot)
		{
			i = i + 1;
			temp = arrayofint[i][idex];
			arrayofint[i][idex] = arrayofint[j][idex];
			arrayofint[j][idex] = temp;
		}
	}
	temp = arrayofint[i + 1][idex];
	arrayofint[i + 1][idex] = arrayofint[last][idex];
	arrayofint[last][idex] = temp;
	return (i + 1);
}



void Columnsort::Transpose()
{
	 temp.clear();

	for (int j = 0; j < arrayofint[0].size(); ++j)
	{
		for (int i = 0; i <arrayofint.size(); ++i)
		{
			temp.push_back(arrayofint[i][j]);

		}
	}

	int idex = 0;
	for (int j = 0; j <R; ++j)
	{
		for (int i = 0; i < S; ++i)
		{
			arrayofint[j][i] = temp.at(idex);
			idex += 1;
		}
	}
}


void Columnsort::RTranspose()
{
	temp.clear();
	

	for (int j = 0; j < R; ++j)
	{
		for (int i = 0; i < S; ++i)
		{
			temp.push_back(arrayofint[j][i]);

		}
	}

	int idex = 0;
	for (int j = 0; j <S; ++j)
	{
		for (int i = 0; i < R; ++i)
		{
			arrayofint[i][j] = temp.at(idex);
			idex += 1;
		}
	}
}

void Columnsort::shiftting(int stepNum)
{
	int position = floor((R / 2.0));
	temp.clear();
	if (stepNum == 6) {

		

		for (int i = 0; i < position; i++) {
			temp.push_back(NInf);
		}

		for (int i = 0; i < arrayofint[0].size(); i++) {
			for (int j = 0; j < arrayofint.size(); j++)
			{
				temp.push_back(arrayofint[j][i]);
			}
		}

		for (int i = 0; i < position; i++) {
			temp.push_back(PInf);
		}

		/* Grow rows by R */
		arrayofint.resize(R);
		for (int i = 0; i < R; ++i)
		{
			/*Grow Columns by S*/
			arrayofint[i].resize(S + 1);
		}

		int id = 0;
		for (int i = 0; i < arrayofint[0].size(); i++) {
			for (int j = 0; j < arrayofint.size(); j++)
			{
				arrayofint[j][i] = temp[id];
				if (id < temp.size()) {
					id += 1;
				}
				else
				{
					break;
				}
			}

		}
	}
	else
	{
		
		for (int i = 0; i < arrayofint[0].size(); i++) {
			for (int j = 0; j < (arrayofint.size()); j++)
			{
				temp.push_back(arrayofint[j][i]);
			}
		}

		/* Grow rows by R */
		arrayofint.resize(R);
		for (int i = 0; i < R; ++i)
		{
			//Grow Columns by S
			arrayofint[i].resize(S);
		}

		int id = position;
		for (int i = 0; i < arrayofint[0].size(); i++) {
			for (int j = 0; j < arrayofint.size(); j++)
			{
				arrayofint[j][i] = temp[id];
				if (id < temp.size()) {
					id += 1;
				}
				else
				{
					break;
				}
			}

		}
		runningTime = timerobj.elapsed_timee();
	}
}


/**
* Check to sure that The vector of short int are sorted.
* @return - bool value.
*/
bool Columnsort::SortCheck()
{

	bool sorted = true;

	for (int j = 0; j < S; ++j)
	{
		for (int i = 0; i < R - 1; ++i)
		{
			if (arrayofint[i][j] <= arrayofint[i + 1][j])
			{
				continue;
			}
			else
			{
				sorted = false;
				break;
			}
		}
	}
	return sorted;
}

/**
* Read the series of integers from the Text file
* @param filename - The file name which contains the integer numbers.
*/
void Columnsort::read()
{
	/* Local variables */
	ifstream openfile;
	string linee;
	int num;

	/* Grow rows by R */
	arrayofint.resize(R);
	for (int i = 0; i < R; ++i)
	{
		/*Grow Columns by S*/
		arrayofint[i].resize(S);
	}

	/* Open the file and Check if it exists */
	openfile.open("Part1Data.txt");
	if (openfile.fail()) {
		std::cout << "No data file" << endl;
		exit(1);
	}
	/* If file exist in the Dir start reading */
	else {
		while (!openfile.eof()) {
			for (int i = 0; i < S; ++i)
			{
				for (int j = 0; j < R; ++j)
				{
					getline(openfile, linee);
					if (!(linee.empty())) {
						num = atoi(linee.c_str());
						arrayofint[j][i] = (num);
					}
				}
			}
		}
	}
	openfile.close();
}




/**
* Write arrayofint values into a text file.
*/
void Columnsort::writeFile()
{

	if (SortCheck())
	{
		ofstream myfile;
		myfile.open("Results.txt");

		for (int j = 0; j < S; ++j)
		{
			for (int i = 0; i < R; ++i)
			{
				myfile << std::to_string(arrayofint[i][j]) << "\n";
			}
		}
		myfile.close();
	}
}

