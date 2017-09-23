#ifndef _FILEIO_H_
#define _FILEIO_H_
#define NULL 0

#include <fstream>

class FileIO{
private:
	static FileIO* instance;
	fstream * myfile;
	FileIO(){};
	FileIO(fstream* myfile);
	~FileIO(){};

public:
	static FileIO* GetInstance(fstream* myfile){
		if (NULL == instance){
			instance = new FileIO(fstream* myfile);
		}
		return instance;
	}
	int insertion(); //insertion student to file1.txt
	int searchID();
	int searchName();
	int searchAge();
	int deletion(); //deletion student by studentID
};
#endif