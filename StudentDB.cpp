#include "StudentDB.h"
#include <iostream>
#include <iomanip>

StudentDB* StudentDB::instance = NULL;

void StudentDB::insertion(){
	string student[5];
	cout << "Name ?";
	cin >> student[0];
	cout << "Student ID ?";
	cin >> student[1];
	cout << "Age ?";
	cin >> student[2];
	cout << "Department ?";
	cin >> student[3];
	cout << "Tel ?";
	cin >> student[4];
	if (checkID(student[1])){
		cout << "Error : Already inserted";
	}else{
		DB.push_back(student);
	}
	file->writeFIle();
}

void StudentDB::deletion(string ID){

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (!iter->studentID.compare(ID)){
			DB.erase(iter);
			iter--;
		}
	}

	file->writeFIle();
}


vector<int> StudentDB::searchID(string ID){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->studentID.compare(ID) == 0){
			index.push_back(iter - DB.begin());
		}
	}
	
	return index;
}

vector<int> StudentDB::searchName(string name){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->name.compare(name) == 0){
			index.push_back(iter - DB.begin());
		}
	}

	return index;
}

vector<int> StudentDB::searchAge(string age){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->age.compare(age) == 0){
			index.push_back(iter - DB.begin());
		}
	}

	return index;
}

vector<int> StudentDB::searchDept(string dept){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->dept.compare(dept) == 0){
			index.push_back(iter - DB.begin());
		}
	}

	return index;
}


void StudentDB::printStudent(vector<int> index){
	cout << setw(15) << "Name" << setw(10) << "StudentID" << setw(20) << "Dept" << "Age" << "tel" << endl;
	for (int i = 0; i<index.size(); i++){
		cout << setw(15) << DB.at(i).name << setw(10) << DB.at(i).studentID << setw(20) << DB.at(i).dept << DB.at(i).age << DB.at(i).tel << endl;
	}
}

bool StudentDB::checkID(string ID){
	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->studentID.compare(ID) == 0){
			return true;
		}
	}
	return false;
}