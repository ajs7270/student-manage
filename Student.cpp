#include "Student.h"

Student::Student(string student[5]) 
	: name(student[0])
	, studentID(student[1])
	, dept(student[2])
	, age(student[3])
	, tel(student[4]){}

bool Student::operator<(const Student &std) const { 
	if (this->getName() < std.getName()){ // sort by dictionary
		return true;
	}
	return false;
}

string Student::getName() const {
	return name;
}

string Student::getStudentID() const{
	return studentID;
}

string Student::getDept() const{
	return dept;
}

string Student::getAge() const{
	return age;
}

string Student::getTel() const{
	return tel;
}

