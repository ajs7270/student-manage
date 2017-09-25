#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Manage.h"

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

bool menu(FileIO* file, StudentDB* db){

	int select;
	int search;
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Deletion" << endl;
	cout << "4. Exit" << endl;
	cout << ">> ";
	cin >> select;

	if (select == 1){
		//insertion
		db->insertion();
	}
	else if (select == 2){
		//search 
		cout << "1. Search by name" << endl;
		cout << "2. search by student ID" << endl;
		cout << "3. search by department name" << endl;
		cout << "4. search by Age" << endl;
		cout << "5. List All" << endl;
		cout << ">> ";
		cin >> search;

		switch (search)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:

			break;
		default:
			cout << "select mistake!" << endl;
			break;
		}
	}
	else if (select == 3){
		//deletion
	}
	else if (select == 4){
		//exit
		return false;
	}
	else{

	}
	return true;
}
