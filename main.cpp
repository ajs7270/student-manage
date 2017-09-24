#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Manage.h"

using namespace std;

void f(int& n) {
	n = 10;
}

int main(int argc, char *argv[]){

#ifdef _DEBUG
	fstream myfile("file1.txt", ios::in | ios::out);
#else
	fstream myfile(argv[1], ios::in | ios::out);
#endif
	FileIO *file = FileIO::GetInstance(&myfile);
	StudentDB *student = StudentDB::Getinstance(file);

	while (menu());
	
	return 0;
}

bool menu(){

	int select;
	int search;
	cout << "1. Insertion" << endl;
	cout << "2. Search" << endl;
	cout << "3. Deletion" << endl;
	cout << "4. Exit" << endl;
	cin >> select;

	if (select == 1){
		//insertion
	}
	else if (select == 2){
		cout << "1. Search by name" << endl;
		cout << "2. search by student ID" << endl;
		cout << "3. search by department name" << endl;
		cout << "4. search by Age" << endl;
		cout << "5. List All" << endl;
		cin >> search;

		switch (search)
		{

		default:
			break;
		}
	}
	else if (select == 3){

	}
	else if (select == 4){
		return false;
	}
	else{

	}
	return true;
}
