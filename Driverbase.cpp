#include <fstream>  
#include <iostream> 
#include <sstream>  
#include <string>  
#include <vector> 
#include "Database.h"

using namespace KGWKAG001;
using namespace std;


int main(){
	
	string exit= "";
	toVector();
	
	cout<< "0: Add Student" << endl;
	cout<< "1: Read Database" << endl;
	cout<< "2: Save Database" << endl;
	cout<< "3: Display Given Student Data" << endl;
	cout<< "4: Grade Student" << endl;
	cout<< "q: Quit" << endl;
	cout<< "Enter a number (or q to quit) and press return..." << endl;
	
	
	
	string input;
	cin>> input;
	
	while(input.compare("q")!=0){
		
		if(input.compare("0")==0){
			addStudent();
			}
		
		else if(input.compare("1")==0){
			readData();
			}
		else if(input.compare("2")==0){
			saveData();
			}
		else if(input.compare("3")==0){
			displayStudent();
			}
		else if(input.compare("4")==0){
			Grade();
			}
		else{
			cout<<"Incorrect input"<<endl;
			}
			
		cout<< "0: Add Student" << endl;
		cout<< "1: Read Database" << endl;
		cout<< "2: Save Database" << endl;
		cout<< "3: Display Given Student Data" << endl;
		cout<< "4: Grade Student" << endl;
		cout<< "q: Quit" << endl;
		cout<< "Enter a number (or q to quit) and press return..." << endl;	
        
        cin>>input;
	
			
		}
		return 0;
	
	}


