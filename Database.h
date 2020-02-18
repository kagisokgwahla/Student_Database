
#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>  
#include <iostream> 
#include <sstream>  
#include <string>  
#include <vector> 

using namespace std;

namespace KGWKAG001{
	void toVector();
	void addStudent();
	void readData();
	void saveData();
	void displayStudent();
	void Grade();
	struct Data{
		string name;
		string surname;
		string studentnumber;
		string classrecord;
		};
	}
	
#endif
	
	
