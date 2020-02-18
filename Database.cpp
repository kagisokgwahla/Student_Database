#include <fstream>  
#include <iostream> 
#include <sstream>  
#include <string>  
#include <vector> 
#include "Database.h"

using namespace std;
//using namespace KGWKAG001;


	
	KGWKAG001::Data Data1;
	vector < KGWKAG001::Data> dataV;
	vector <string> vecWords;
	
	void KGWKAG001 :: addStudent(){
		string name;
		string surname;
		string studentnumber;
		string classrecord;
		int done=0;
		
		cout<<"Enter name:"<<endl;
		cin>> name;
		cout<<"Enter surname:"<<endl;
		cin>> surname;
		cout<<"Enter student number:"<<endl;
		cin>> studentnumber;
		cout<<"Enter class record (separate marks with spaces):"<<endl;
		cin.ignore();
		getline(cin,classrecord);
		
		for(unsigned int i=0; i<dataV.size();++i){
			if(studentnumber.compare(dataV[i].studentnumber)==0){
				dataV[i].name=name;
				dataV[i].surname=surname;
				dataV[i].classrecord=classrecord;
				done=1;
				}
			}
		if(done==0){
			
			Data1.name=name;
			Data1.surname=surname;
			Data1.studentnumber= studentnumber;
			Data1.classrecord= classrecord;
		
			dataV.push_back(Data1);
			}
		
		
		}
	
	void KGWKAG001::toVector(){
		cout<<"function toVector() called"<<endl;
		string filename= "Data.txt";
		ifstream in(filename.c_str());
		if(!in){
			ofstream file1;
			file1.open("Data.txt");
			file1.close(); 
			}
			
		else{
			string S;
			string oneword;
			char cSpace=' ';
			
			while(getline(in,S)){
				stringstream ss(S);
				
				while(getline(ss, oneword,cSpace)){
					
					vecWords.push_back(oneword);
					
					}
				Data1.name=vecWords[0];
				Data1.surname=vecWords[1];
				Data1.studentnumber=vecWords[2];
				Data1.classrecord=vecWords[3]+" "+vecWords[4]+" "+vecWords[5]+ " "+vecWords[6];
				
				vecWords.clear();
				
				dataV.push_back(Data1);
				
				
				
				
				}
			
			}
			
		in.close();
		}
	
	void KGWKAG001::displayStudent(){
		cout<<"function displayStudent() called"<<endl;
		cout<<"Enter student number:"<<endl;
		string input;
		cin >> input;
		int caught=0;
		
		for(unsigned int i =0; i<dataV.size(); ++i){
			if(input.compare(dataV[i].studentnumber)==0){
				cout<< dataV[i].name+" "+dataV[i].surname+ " " + dataV[i].studentnumber+ " "+ dataV[i].classrecord<< endl;
				caught=1;
				}
			
			}
		if(caught==0){
			cout<< "Student Not Found"<< endl;
			}
			
		}
	
	void KGWKAG001::saveData(){
		ofstream myfile;
		myfile.open("Data.txt");
		for(unsigned int i =0; i< dataV.size(); ++i){
			myfile<< dataV[i].name+" "+dataV[i].surname+ " " + dataV[i].studentnumber+ " "+ dataV[i].classrecord << endl;
		  }
		 cout<<"function saveData() called"<<endl;
		 cout<<"Saved Data"<<endl;
		}	
		
	void KGWKAG001::readData(){
		cout<<"function readData() called"<<endl;
		for(unsigned int i =0; i< dataV.size(); ++i){
			cout<< dataV[i].name+" "+dataV[i].surname+ " " + dataV[i].studentnumber+ " "+ dataV[i].classrecord<< endl;
			
			}
	
		if(dataV.size()==0){
			cout<< "Database is empty"<< endl;
			}
		}
	
	void KGWKAG001::Grade(){
		cout<<"function Grade() called"<<endl;
		string grade;
		string input;
		cout<<"Enter student number:"<<endl;
		cin>> input;
		int fn=0;
		
		for(unsigned int i=0; i<dataV.size();++i){
			if(input.compare(dataV[i].studentnumber)==0){
				grade=dataV[i].classrecord;
				fn=1;
				}
			}
		if(fn==1){
			istringstream ss(grade);
			int total;
			int dv=0;
		
			for(int i =0; i<4;++i){
				ss>>total;
				dv+=total;
			
			}
			cout<<"Student Average:"<<endl;
			int average = dv/4;
			cout<<average<<endl;
			
			}
		else{
			cout<< "Student Not Found"<< endl;
			}
		
		}
