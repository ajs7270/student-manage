#pragma once

#include <cstdio>
#include <fstream>

class StudentDB;

using namespace std;

class FileIO{
private:
	static FileIO* instance;
	string fileName;
	
	FileIO(){}; //singleton pattern
	FileIO(string fileName); // constructor use singleton pattern
	~FileIO(){};

public:
	static FileIO* GetInstance(string fileName); // singleton pattern
	FileIO* GetInstance(); // singleton pattern

	void readFile(StudentDB* DB); // read file to initalize DB
	void writeFIle(StudentDB* DB); // write file using DB
};