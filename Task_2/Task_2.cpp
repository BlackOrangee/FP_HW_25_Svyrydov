// Task 2. Transposing a matrix is an operation after which the columns of the former matrix become rows, 
// and the rows become columns. Write the matrix transpose function.
//

#include <iostream>
using namespace std;

int** GenerateMatrix(int& size);
void Print(int** arr, int& size);
int** MatrixTransposing(int** arr, int& size);

int main()
{
	int size = 3;
	int** arr = GenerateMatrix(size);
	Print(arr, size);

	int** trans_arr = MatrixTransposing(arr, size);
	Print(trans_arr, size);

}

int** GenerateMatrix(int& size)// Generate matrix
{
	int count = 0;
	int** arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			count++;
			arr[i][j] = count;
		}
	}
	return arr;
}

void Print(int** arr, int& size)// Print function
{
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\t";
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** MatrixTransposing(int** arr, int& size)// Transposing function
{
	int** transposing_arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		transposing_arr[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			transposing_arr[i][j] = arr[j][i];
		}
	}
	delete[] arr;
	return transposing_arr;
}