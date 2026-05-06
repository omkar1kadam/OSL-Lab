/*AIM:
Company maintains employee information as employee ID, name, designation and salary.
Allow user to add, delete information of employee. 
Display information of particular employee.
If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details. 
Use sequential file to maintain the data.

1. Create File
2. Open File
3. Read File
4. Write in File
5. Update in File
6. Search in File
7. Display File

INPUT: Employee Information

OUTPUT: Employee Information in Sequential File  

Author: Dr. Sunil Damodar Rathod.

DATE:16.03.2026

*/
#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
#include <cstring>
#include<fstream>
#include<iomanip>
#define MAX 20
using namespace std;

//Employee ATD
typedef struct Employee{
	 int EID;
	 string name;
	 string designation;
	 float salary;
}EMP;


//Implementation Class 
class SequentialFile
{
	private:
		EMP obj;
		
	public:
		//SequentialFile();
		void readData();
		void printData();
		void insertRecord();
		void displayRecords();
		void deleteRecord(string);
		void updateRecord(string);
		void searchRecord(string);
};
//Function to read user input data from keyboard	
void SequentialFile::readData(){
			cout<<"\nEnter Employee ID:";
			cin>>obj.EID;
			
			cout<<"\nEnter Employee Name:";
			cin>>obj.name;
			
			cout<<"\nEnter Employee Designation:";
			cin>>obj.designation;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer before taking new input
			
			cout<<"\nEnter Employee Salary:";
			cin>>obj.salary;
}

//Function to print user input data on terminal		
void SequentialFile::printData(){
			cout<<"\nEmployee ID:"<<obj.EID;
			cout<<"\nEmployee Name:"<<obj.name;
			cout<<"\nEmployee Designation:"<<obj.designation;
			cout<<"\nEmployee Salary:"<<obj.salary;
}

void SequentialFile::insertRecord(){
    fstream out;

    out.open("employee.txt",ios::app|ios::binary);
    readData();
    out.write((char*)&obj,sizeof(obj));
    out.close();
}

void SequentialFile::displayRecords(){
    fstream in;

    in.open("employee.txt",ios::in|ios::binary);

    while(in.read((char*)&obj,sizeof(obj))){
        cout<<"\n"<<obj.EID<<setw(15)<<obj.name<<setw(15)<<obj.designation<<setw(15)<<obj.salary;
    }
    in.close();
}

void SequentialFile::searchRecord(string name){
    fstream in;

    in.open("employee.txt",ios::in|ios::binary);

    while(in.read((char*)&obj,sizeof(obj))){
        if(obj.name == name){
            cout<<"\n"<<obj.EID<<setw(15)<<obj.name<<setw(15)<<obj.designation<<setw(15)<<obj.salary;
            return;
        }
    }
    in.close();
    
}

void SequentialFile::updateRecord(string name){
    fstream inout;
    int count =0;
    inout.open("employee.txt",ios::in|ios::out|ios::binary);

    while(inout.read((char*)&obj,sizeof(obj))){
        count++;
        if(obj.name == name){
            readData();
            inout.seekp(sizeof(obj)*(count-1),ios::beg);
            inout.write((char*)&obj,sizeof(obj));
            return;
        }
    }
}

void SequentialFile::deleteRecord(string name){
    fstream in;

    in.open("employee.txt",ios::in|ios::binary);

    fstream out;
    out.open("temp.txt",ios::out | ios:: binary);

    while(in.read((char*)&obj,sizeof(obj))){
        if(obj.name != name){
            out.write((char*)&obj,sizeof(obj));
        }
    }
    in.close();
    out.close();

    remove("employee.txt");
    rename("temp.txt","employee.txt");
}