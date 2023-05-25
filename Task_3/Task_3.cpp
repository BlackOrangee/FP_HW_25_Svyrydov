// Task 3. Create a dynamic array that stores the name in the first row and the phone in the second row. 
// Search by name and phone number. Implement the ability to enter and change data.
//

#include <iostream>
using namespace std;

string** CreateList(int& size)
{
	string** list = new string*[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = new string;
	}
}

void Print(string** list, int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << list[i] << " ";
	}
}

int main()
{
	int size = 10;
	string** list = CreateList(size);

	cin >> list[0][0];

	Print(list, size);
}