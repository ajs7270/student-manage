#pragma once 

#include <vector>
#include "Student.h"

using namespace std;

class FileIO;

class StudentDB {
private:
	vector<Student> DB;
	FileIO *file;

	static StudentDB* instance; // singleton pattern
	bool checkID(string ID); // id compare and 

	StudentDB(FileIO* file); // constructor use singleton pattern
	~StudentDB(){}; //destructor

public:
	static StudentDB* Getinstance(FileIO* file); // singleton pattern

	void insertion(); // insertion student
	void deletion(string ID); // delete student by ID
	void clearDB(); // reset DB
	void setDB(string student[5]); //add Student to DB

	vector<int> searchID(string ID);// return equal ID index들
	vector<int> searchName(string name);// return equal Name index들
	vector<int> searchAge(string age);// return equal Age index들
	vector<int> searchDept(string dept);// return equal department index들

	void printStudent(vector<int> index); // input index and print that
	void printAllStudent(); // print all student

	string	getStudentLine(int index); // get one student information
	int		getDBSize(); // get How many student information
};
