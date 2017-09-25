#ifndef _FILEIO_H_
#define _FILEIO_H_
#define NULL 0

#include <fstream>
#include "StudentDB.h"

using namespace std;

class FileIO{
private:
	static FileIO* instance;
	string fileName;
	FileIO(){};
	FileIO(string fileName);
	~FileIO(){};

public:
	static FileIO* GetInstance(string fileName){
		if (NULL == instance){
			instance = new FileIO(fileName);
		}
		return instance;
	}
	FileIO* GetInstance(){
		return instance;
	}
	void readFile(StudentDB* DB);
	void writeFIle(StudentDB* DB);	
};
#endif