#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "FileIO.h"
#include "StudentDB.h"
#include "Student.h"

using namespace std;

bool menu(FileIO*, StudentDB*);

int main(int argc, char *argv[]){

#ifdef _DEBUG
	string fileName("file1.txt");
#else
	string fileName(argv[1]);
#endif
	FileIO *file = FileIO::GetInstance(fileName); // create FileIO instance
	StudentDB *DB = StudentDB::Getinstance(file); // create Student DB instance
	
	file->readFile(DB);// read file to DB

	while (menu(file, DB)); //print menu
	
	return 0;
}

enum SELECT_MENU{
	INSERTION = 1,
	SEARCH,
	DELETION,
	EXIT
};

enum SEARCH_OPTION{
	SEARCH_BY_NAME = 1,
	SEARCH_BY_ID,
	SEARCH_BY_DEPARTMENT,
	SEARCH_BY_AGE,
	LIST_ALL
};

bool menu(FileIO* file, StudentDB* DB){
	
	int select;
	int searchNum;
	string searchString;
	vector<int> index;

	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Deletion" << endl;
	cout << "4. Exit" << endl;
	cout << ">> ";
	cin >> select;

	switch (select)
	{
	case INSERTION:
		//insertion
		DB->insertion();
		break;
	case SEARCH:
		//search 
		cout << SEARCH_BY_NAME << ". Search by name" << endl;
		cout << SEARCH_BY_ID << ". search by student ID" << endl;
		cout << SEARCH_BY_DEPARTMENT << ". search by department name" << endl;
		cout << SEARCH_BY_AGE << ". search by Age" << endl;
		cout << LIST_ALL << ". List All" << endl;
		cout << ">> ";
		cin >> searchNum;

		switch (searchNum)
		{
		case SEARCH_BY_NAME:
			cout << ">> ";
			cin >> searchString;
			index = DB->searchName(searchString);
			cout << endl;
			DB->printStudent(index);
			cout << endl;
			break;
		case SEARCH_BY_ID:
			cout << ">> ";
			cin >> searchString;
			index = DB->searchID(searchString);
			cout << endl;
			DB->printStudent(index);
			cout << endl;
			break;
		case SEARCH_BY_DEPARTMENT:
			cout << ">> ";
			cin >> searchString;
			index = DB->searchDept(searchString);
			cout << endl;
			DB->printStudent(index);
			cout << endl;
			break;
		case SEARCH_BY_AGE:
			cout << ">> ";
			cin >> searchString;
			index = DB->searchAge(searchString);
			cout << endl;
			DB->printStudent(index);
			cout << endl;
			break;
		case LIST_ALL:
			cout << endl;
			DB->printAllStudent();
			cout << endl;
			break;
		default:
			cout << "select mistake!" << endl;
			break;
		}
		break;
	case DELETION:
		cout << ">>";
		cin >> searchString;
		DB->deletion(searchString);
		break;
	case EXIT:
		return false;
	default:
		break;
	}
	return true;
}
