// Task 3. Create a dynamic array that stores the name in the first row and the phone in the second row. 
// Search by name and phone number. Implement the ability to enter and change data.
//

#include <iostream>
#include <string>
using namespace std;

struct user
{
	string name;
	string surname;
	string phone = "0";
	string comment = "0";

	void add(string inname, string insurname, string inphone)
	{
		name = inname;
		surname = insurname;
		phone = inphone;
		
	}
	void add(string inname, string insurname, string inphone, string incomment)
	{
		name = inname;
		surname = insurname;
		phone = inphone;
		comment = incomment;
		
	}
	void print()
	{
		if (phone == "0")
		{
			cout << "\n\n\tEmpty\t";

		}
		else
		{
			cout << "\n\n\tName:\t" << name;
			cout << "\n\tSurame:\t" << surname;
			cout << "\n\tPhone:\t" << phone;

			if (comment[0] != '0')
			{
				cout << "\n\tComment: " << comment;
			}
		}
	}
};

enum Menu
{
	AddUser = 1, PrintList, Search, Edit, Delete
};
enum Searchs
{
	Name = 1, Surname, Phone, Back
};

int EnterSize();
user* CreateList(int& size);
string NameCorrector(string inname);
string PhoneCorrector(string inphone);
void Fill(user* Userlist, int& size, int& usedsize);
void Print(user* list, int& size);
void SearchNameAndPrint(user* userlist, int& size, int& usedsize, string searchable);
void SearchSurnameAndPrint(user* userlist, int& size, int& usedsize, string searchable);
void SearchPhoneAndPrint(user* userlist, int& size, int& usedsize, string searchable);
int SearchPhone(user* userlist, int& size, int& usedsize, string searchable);
void EditUser(user* userlist, int& size, int& usedsize, int toedit);
void DeleteUser(user* userlist, int& size, int& usedsize, int toedit);

int main()
{
	int size = EnterSize();
	int UsedSize = -1;
	user* UserList = CreateList(size);
	string searchable;

	int menu = 0;

	do
	{
		printf("\n\n\t1 -- Add User\n\t2 -- Print List\n\t3 -- Search\n\t4 -- Edit\n\t5 -- Delete\n\t"); cin >> menu;

		switch (Menu(menu))
		{
		case AddUser:
			Fill(UserList, size, UsedSize);
			break;
		case PrintList:
			Print(UserList, size);
			break;
		case Search:

			printf("\n\n\tSearch\n\n\t1 -- By Name\n\t2 -- By Surname\n\t3 -- By Phone\n\t4 -- Back\n\t"); cin >> menu;

			switch (Searchs(menu))
			{
			case Name:
				printf("\n\n\t0 -- Back\n\tEnter Name: "); cin >> searchable;

				if (searchable == "0")
				{
					break;
				}
				searchable = NameCorrector(searchable);

				SearchNameAndPrint(UserList, size, UsedSize, searchable);
				break;
			case Surname:
				printf("\n\n\t0 -- Back\n\tEnter Surname: "); cin >> searchable;

				if (searchable == "0")
				{
					break;
				}
				searchable = NameCorrector(searchable);

				SearchSurnameAndPrint(UserList, size, UsedSize, searchable);
				break;
			case Phone:
				printf("\n\n\t0 -- Back\n\tEnter Phone: "); cin >> searchable;

				if (searchable == "0")
				{
					break;
				}
				searchable = PhoneCorrector(searchable);

				if (searchable != "Incorrect phone")
					SearchPhoneAndPrint(UserList, size, UsedSize, searchable);
				break;
			case Back:
				break;
			default:
				break;
			}
			break;
		case Edit:
			printf("\n\n\t0 -- Back\n\tEnter Phone to edit user: "); cin >> searchable;

			if (searchable == "0")
			{
				break;
			}
			searchable = PhoneCorrector(searchable);

			if (searchable != "Incorrect phone")
				EditUser(UserList, size, UsedSize, SearchPhone(UserList, size, UsedSize, searchable));
			break;
		case Delete:
			printf("\n\n\t0 -- Back\n\tEnter Phone to delete user: "); cin >> searchable;

			if (searchable == "0")
			{
				break;
			}
			searchable = PhoneCorrector(searchable);

			if (searchable != "Incorrect phone")
				DeleteUser(UserList, size, UsedSize, SearchPhone(UserList, size, UsedSize, searchable));
			break;
		default:
			break;
		}
	} while (true);
}

int EnterSize()//List size, entered by user
{
	int insize;
	cout << "\n\n\tEnter list size: "; cin >> insize;
	return insize;
}

user* CreateList(int& size)//Create structured array with entered size
{
	user* UserList = new user[size];
	return UserList;
}

string NameCorrector(string inname)//Increases the first letters 
{
	if (inname[0] >= 97 && inname[0] <= 122)
	{
		inname[0] = inname[0] - 32;
	}
	return inname;
}

string PhoneCorrector(string inphone)//Chek phone lenght and format	//if number start fron '0' - add Ukrainian number code => "+38"
{
	string phone = "+38";

	if (inphone[0] == '+' && inphone.length() == 13)
	{
		phone = inphone;
	}
	else if (inphone[0] == '0' && inphone.length() == 10)
	{
		phone += inphone;
	}
	else
	{
		printf("\n\n\tIncorrect phone");
		phone = "Incorrect phone";
	}
	return phone;
}

void Fill(user* Userlist, int& size, int& usedsize)//Data filling function
{
	if (usedsize != size)//Chek size
	{
		usedsize++;//Current size
		string name;
		string surname;
		string phone;
		string comment;

		cout << "\n\tEnter Name: ";	cin >> name;
		name = NameCorrector(name);

		cout << "\n\tEnter Surame: ";	cin >> surname;
		surname = NameCorrector(surname);

		cout << "\n\tEnter Phone: ";	cin >> phone;
		phone = PhoneCorrector(phone);

		if (SearchPhone(Userlist, size, usedsize, phone) == -5)
		{
			if (phone != "Incorrect phone")//Correctly entered phone number need, to save entering data
			{
				int choice = 0;
				cout << "\n\tEnter Comment?\n\t0 -- no\n\t1 -- yes\n\t";	cin >> choice;//Comment, this is not a required field

				if (choice)
				{
					cout << "\n\tEnter Comment: ";	cin >> comment;

					Userlist[usedsize].add(name, surname, phone, comment);//Save data wuth comment
				}
				Userlist[usedsize].add(name, surname, phone);//Save data
			}
			else
			{
				usedsize--;
			}
		}
		else
		{
			cout << "\n\n\tUser alredy added";
			usedsize--;
		}
		
	}
	else
	{
		cout << "\n\n\tList is full";
	}

}

void Print(user* list, int& size)//Show all list of users
{
	for (int i = 0; i < size; i++)
	{
		list[i].print();
	}
}

void SearchNameAndPrint(user* userlist, int& size, int& usedsize, string searchable)//Search list by name, and print all users with the same names
{
	for (int i = 0; i <= usedsize; i++)
	{
		if (userlist[i].name == searchable)
		{
			userlist[i].print();
		}
	}
}

void SearchSurnameAndPrint(user* userlist, int& size, int& usedsize, string searchable)//Search list by surname, and print all users with the same surnames
{
	for (int i = 0; i <= usedsize; i++)
	{
		if (userlist[i].surname == searchable)
		{
			userlist[i].print();
		}
	}
}

void SearchPhoneAndPrint(user* userlist, int& size, int& usedsize, string searchable)//Search list by phone, and print all users with the same phone
{
	for (int i = 0; i <= usedsize; i++)
	{
		if (userlist[i].phone == searchable)
		{
			userlist[i].print();
		}
	}
}

int SearchPhone(user* userlist, int& size, int& usedsize, string searchable)//Search phone and return index
{
	for (int i = 0; i <= usedsize; i++)
	{
		if (userlist[i].phone == searchable)
		{
			return i;
		}
	}
	int a = -5;
	return a;
}

void EditUser(user* userlist, int& size, int& usedsize, int toedit)//You can change all parameters
{
	string name;
	string surname;
	string phone;
	string comment;

	do
	{
		userlist[toedit].print();

		int menu = 0;
		printf("\n\n\tEdit\n\t0 -- Back\n\t1 -- Name\n\t2 -- Surname\n\t3 -- Phone\n\t4 -- Comment\n\t"); cin >> menu;

		switch (menu)
		{
		case 0:
			return;
			break;
		case 1:
			cout << "\n\tEnter Name: ";	cin >> name;
			userlist[toedit].name = NameCorrector(name);
			break;
		case 2:
			cout << "\n\tEnter Surame: ";	cin >> surname;
			userlist[toedit].surname = NameCorrector(surname);
			break;
		case 3:
			cout << "\n\tEnter Phone: ";	cin >> phone;
			phone = PhoneCorrector(phone);

			if (SearchPhone(userlist, size, usedsize, phone) == -5)
			{
				if (phone != "Incorrect phone")
				{
					userlist[toedit].phone = phone;
				}
			}
			else
			{
				cout << "\n\n\tPhone alredy added";
			}
			break;
		case 4:
			cout << "\n\tUse '0' to delete\n\tEnter Comment: ";	cin >> comment;
			userlist[toedit].comment = comment;
			break;
		default:
			break;
		}
	} while (true);

}

void DeleteUser(user* userlist, int& size, int& usedsize, int toedit)//Delete choused user
{
	string name;
	string surname;
	string phone = "0";
	string comment = "0";
	userlist[toedit].name = name;
	userlist[toedit].surname = surname;
	userlist[toedit].phone = phone;
	userlist[toedit].comment = comment;
	usedsize--;
}
