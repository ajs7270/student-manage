#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

using namespace std;

class Student{
public:
	Student(string student[5])
		: name(student[0])
		, studentID(student[1]) 
		, dept(student[2])
		, age(student[3])
		, tel(student[4]){}
	string name;
	string studentID;
	string dept;
	string age;
	string tel;
};

#endif