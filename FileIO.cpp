#define _CRT_SECURE_NO_WARNINGS

#include <cstring>

#include "FileIO.h"
#include "StudentDB.h"

FileIO* FileIO::instance = NULL;

FileIO::FileIO(string fileName): fileName(fileName){}

FileIO* FileIO::GetInstance(string fileName){
	if (NULL == instance){
		instance = new FileIO(fileName);
	}
	return instance;
}

FileIO* FileIO::GetInstance(){
	return instance;
}

void FileIO::readFile(StudentDB *DB){
	ifstream file(fileName);
	string student[5];

	while (!file.eof()){
		char inputLine[100] = { 0, };
		
		file.getline(inputLine, 100);

		if (inputLine[0] == NULL){ break; }

		//splite line
		char* pch;
		pch = strtok(inputLine, "/");
		for (int i = 0; i < 5 && pch !=NULL; i++){
			student[i] = string(pch);
			pch = strtok(NULL, "/");
		}

		DB->setDB(student);
	}
	file.close();
}

void FileIO::writeFIle(StudentDB *DB){
	ofstream file(fileName);

	for (int i = 0; i < DB->getDBSize(); i++){
		file << DB->getStudentLine(i) << endl;
	}

	file.close();
}
