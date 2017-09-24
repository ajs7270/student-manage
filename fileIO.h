#ifndef _FILEIO_H_
#define _FILEIO_H_
#define NULL 0

#include <fstream>

using namespace std;

class FileIO{
private:
	static FileIO* instance;
	fstream* myfile;
	FileIO(){};
	FileIO(fstream* myfile);
	~FileIO(){};

public:
	static FileIO* GetInstance(fstream* myfile){
		if (NULL == instance){
			instance = new FileIO(myfile);
		}
		return instance;
	}
	FileIO* GetInstance(){
		return instance;
	}
	void readFile();
	void writeFIle();
	};
#endif