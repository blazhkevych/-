#include <iostream>
#include <string>
#include <fstream>
#define _DataBase "D:\\PhoneBook.dat"
#define _MAX_LEN 1000

using namespace std;

class PhoneBook
{
private:
	char* _Name;
	char* _Sur_Name;
	char* _PatroNymic;
	char* _Cell_Phone;
	char* _Home_Phone;
	char* _E_mail;
	char* _Home_Address;
public:
	PhoneBook();
	~PhoneBook();
	void _Delete_Data();
	void _Menu_of_PhoneBook();
	void _Write_to_file();
	void _Read_from_file();

	friend ostream& operator << (ostream& stream, const PhoneBook& obj);
	friend istream& operator >> (istream& stream, PhoneBook& obj);
};

int main()
{
	PhoneBook obj;
	obj._Menu_of_PhoneBook();
}

PhoneBook::PhoneBook()
{
	_Name = new char[_MAX_LEN];
	_Sur_Name = new char[_MAX_LEN];
	_PatroNymic = new char[_MAX_LEN];
	_Cell_Phone = new char[_MAX_LEN];
	_Home_Phone = new char[_MAX_LEN];
	_E_mail = new char[_MAX_LEN];
	_Home_Address = new char[_MAX_LEN];
}

PhoneBook::~PhoneBook()
{
	delete[] _E_mail;
	delete[] _Home_Phone;
	delete[] _Cell_Phone;
	delete[] _PatroNymic;
	delete[] _Sur_Name;
	delete[] _Name;
	delete[] _Home_Address;
}

void PhoneBook::_Delete_Data()
{

}

ostream& operator << (ostream& stream, const PhoneBook& obj)
{
	stream << obj._Name << endl;
	stream << obj._Sur_Name << endl;
	stream << obj._PatroNymic << endl;
	stream << obj._Cell_Phone << endl;
	stream << obj._Home_Phone << endl;
	stream << obj._E_mail << endl;
	stream << obj._Home_Address << endl;
	return stream;
}

istream& operator >> (istream& stream, PhoneBook& obj)
{
	cout << "Enter a name:" << endl;
	stream >> obj._Name;
	cout << "Enter a surname:" << endl;
	stream >> obj._Sur_Name;
	cout << "Enter a first name:" << endl;
	stream >> obj._PatroNymic;
	cout << "Enter Enter your mobile phone:" << endl;
	stream >> obj._Cell_Phone;
	cout << "Enter Enter your home phone:" << endl;
	stream >> obj._Home_Phone;
	cout << "Enter Enter your E-mail adress:" << endl;
	stream >> obj._E_mail;
	cout << "Enter Enter your home address:" << endl;
	stream >> obj._Home_Address;
	return stream;
}

void PhoneBook::_Write_to_file()
{
	fstream io(_DataBase, ios::in | ios::app);
	if (!io)
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		cout << "Enter the number of the order:" << endl;
		int kol;
		cin >> kol;
		for (int i = 0; i < kol; i++)
		{
			cin >> *this;
			io << *this;
		}
		io.close();
	}
}

void PhoneBook::_Read_from_file()
{
	fstream io(_DataBase, ios::in | ios::app);
	if (!io)
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		char _TempCH;
		while (!io.eof())
		{
			io.get(_TempCH);
			if (!io.eof())
				cout << _TempCH;
		}
		io.clear();
		cout << endl;
		io.close();
	}
}

void PhoneBook::_Menu_of_PhoneBook()
{
	int choise = 0;
	cout << "\tMENU:" << endl;
	cout << "1. Add data to the database:" << endl;
	cout << "2. Delete data from the database:" << endl;
	cout << "3. Display the data in the database:" << endl;
	cout << "4. Exit:" << endl << endl;
	cout << "Please make your choice:" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		_Write_to_file();
		break;
	case 2:
		break;
	case 3:
		_Read_from_file();
		break;
	case 4:
		break;
	default:
		cout << "Selected the wrong menu item." << endl;
	}
}