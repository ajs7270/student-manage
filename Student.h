#pragma once

#include <string>

using namespace std;

class Student{

public:

	Student(string student[5]);
		
	
	string getName() const;
	string getStudentID() const;
	string getDept() const;
	string getAge() const;
	string getTel() const;

	bool operator<(const Student& std) const ; // Operator Overloading for sort

private:
	string name;
	string studentID;
	string dept;
	string age;
	string tel;
};
