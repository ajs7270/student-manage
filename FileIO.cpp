#include "FileIO.h"
#include <cstring>
#include <iostream> // debug

FileIO* FileIO::instance = NULL;

FileIO::FileIO(string fileName): fileName(fileName){}

void FileIO::readFile(StudentDB *DB){
	ifstream file(fileName);
	string student[5];

	while (file.eof() != NULL){
		char inputLine[100] = { 0, };
		
		file.getline(inputLine, 100);

		if (inputLine[0] == NULL){ break; }

		//splite line
		char* pch;
		pch = strtok(inputLine, "/");
		for (int i = 0; i < 5 && pch !=NULL; i++){
			student[i] = string(pch);
			cout << student[i]<< endl; //debug
			pch = strtok(NULL, "/");
		}

		DB->setDB(student);
	}
	file.close();
}

void FileIO::writeFIle(StudentDB *DB){
	ofstream file(fileName);

	for (int i = 0; i < DB->getDBSize; i++){
		file << DB->getStudentLine(i) << endl;
	}

	file.close();
}
