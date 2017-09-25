#include <iostream>
#include <iomanip>
#include <algorithm>

#include "StudentDB.h"
#include "FileIO.h"


StudentDB* StudentDB::instance = NULL;

StudentDB::StudentDB(FileIO* file){
	this->file = file;
}

StudentDB* StudentDB::Getinstance(FileIO* file){
	if (NULL == instance){
		instance = new StudentDB(file);
	}
	return instance;
}


void StudentDB::insertion(){ //insertion student
	string student[5];
	cout << "Name ? ";
	cin >> student[0];
	cout << "Student ID ? ";
	cin >> student[1];
	cout << "Age ? ";
	cin >> student[2];
	cout << "Department ? ";
	cin >> student[3];
	cout << "Tel ? ";
	cin >> student[4];
	if (checkID(student[1])){
		cout << "Error : Already inserted";
	}else{
		DB.push_back(student);
	}
	//DB sort
	sort(DB.begin(), DB.end());

	file->writeFIle(this);
}

void StudentDB::deletion(string ID){

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->getStudentID().compare(ID) == 0){
			iter = DB.erase(iter);
		}
	}

	file->writeFIle(this);
}

void StudentDB::clearDB(){
	DB.clear();
}

void StudentDB::setDB(string student[5]){
	DB.push_back(student);
}

vector<int> StudentDB::searchID(string ID){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->getStudentID().compare(ID) == 0){
			index.push_back(iter - DB.begin());
		}
	}
	
	return index;
}

vector<int> StudentDB::searchName(string name){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->getName().compare(name) == 0){
			index.push_back(iter - DB.begin());
		}
	}

	return index;
}

vector<int> StudentDB::searchAge(string age){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->getAge().compare(age) == 0){
			index.push_back(iter - DB.begin());
		}
	}

	return index;
}

vector<int> StudentDB::searchDept(string dept){
	vector<int> index;

	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->getDept().compare(dept) == 0){
			index.push_back(iter - DB.begin());
		}
	}

	return index;
}


void StudentDB::printStudent(vector<int> index){
	cout << setw(10) << left << "Name" 
		<< setw(15) << left << "StudentID" 
		<< setw(20) << left << "Dept" 
		<< setw(10) << left << "Age" 
		<< setw(10) << left<< "tel" 
		<< endl;
	for (int i = 0; i<index.size(); i++){
		cout << setw(10) << left << DB[index[i]].getName() 
			<< setw(15) << left << DB[index[i]].getStudentID() 
			<< setw(20) << left << DB[index[i]].getDept() 
			<< setw(10) << left << DB[index[i]].getAge() 
			<< setw(10) << left << DB[index[i]].getTel() 
			<< endl;
	}
}

void StudentDB::printAllStudent(){
	cout << setw(10) << left << "Name"
		<< setw(15) << left << "StudentID"
		<< setw(20) << left << "Dept"
		<< setw(10) << left << "Age"
		<< setw(10) << left << "tel"
		<< endl;
	for (int i = 0; i < DB.size(); i++){
		cout << setw(10) << left << DB[i].getName() 
			<< setw(15) << left << DB[i].getStudentID()
			<< setw(20) << left << DB[i].getDept() 
			<< setw(10) << left << DB[i].getAge() 
			<< setw(10) << left << DB[i].getTel() 
			<< endl;
	}
}

bool StudentDB::checkID(string ID){
	
	//if id conflict
	for (auto iter = DB.begin(); iter != DB.end(); iter++){
		if (iter->getStudentID().compare(ID) == 0){
			return true;
		}
	}

	//if id is empty
	if (ID.compare("") == 0){
		return true;
	}

	return false;
}

string StudentDB::getStudentLine(int index){
	string line = DB[index].getName() 
		+ '/' + DB[index].getStudentID() 
		+ '/' + DB[index].getAge() 
		+ '/' + DB[index].getDept() 
		+ '/' + DB[index].getTel();
	return line;
}