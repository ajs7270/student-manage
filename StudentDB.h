#pragma once 

#include <vector>
#include "Student.h"

using namespace std;

class FileIO;

class StudentDB {
private:
	static StudentDB* instance; // singleton pattern
	vector<Student> DB;
	FileIO *file;
	bool checkID(string ID); // id compare and 

	StudentDB(FileIO* file); // constructor use singleton pattern
	~StudentDB(){};
	

public:
	static StudentDB* Getinstance(FileIO* file); // singleton pattern

	void insertion();
	void deletion(string ID);
	void clearDB();
	void setDB(string student[5]);

	vector<int> searchID(string ID);// return equal ID index들
	vector<int> searchName(string name);// return equal Name index들
	vector<int> searchAge(string age);// return equal Age index들
	vector<int> searchDept(string dept);// return equal department index들

	void printStudent(vector<int> index); // input index and print that
	void printAllStudent(); // print all student

	string	getStudentLine(int index);
	int		getDBSize(){ return DB.size(); }
};
