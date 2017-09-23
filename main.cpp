#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "manage.h"

using namespace std;

int main(int argc, char *argv[]){

#ifdef _DEBUG
	fstream myfile("file1.txt", ios::in | ios::out);
#endif

#ifndef _DEBUG
	fstream myfile(argv[1], ios::in | ios::out);
#endif

	return 0;
}
