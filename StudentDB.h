#ifndef _STUDENTDB_H
#define _STUDENTDB_H

#include <vector>
#include "Student.h"
#include "FileIO.h"

using namespace std;


class StudentDB {
private:
	static StudentDB* instance;
	vector<Student> DB;
	FileIO *file;
	bool checkID(string ID);
	StudentDB(FileIO* file){ this->file = file; };
	~StudentDB(){};
	

public:
	static StudentDB* Getinstance(FileIO* file){
		if (NULL == instance){
			instance = new StudentDB(file);
		}
		return instance;
	}
	
	void insertion();
	void deletion(string ID);
	void clearDB();
	void setDB(string student[5]);

	vector<int> searchID(string ID);
	vector<int> searchName(string name);
	vector<int> searchAge(string age);
	vector<int> searchDept(string dept);

	void printStudent(vector<int> index);
	
	string	getStudentLine(int index);
	int		getDBSize(){ return DB.size(); }
};

#endif
