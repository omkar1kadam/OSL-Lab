#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
#define BSIZE 5
using namespace std;

typedef struct Client{
    long int telephoneNo;
    string name;
}CLIENT;


class TelephoneDirectory{
    private:
        CLIENT LPHashtable[BSIZE];
        CLIENT QPHashtable[BSIZE];
        CLIENT cObj;
    
    public:
        TelephoneDirectory(){
            for(int i=0; i<BSIZE; i++){
                LPHashtable[i].telephoneNo = -1;
                QPHashtable[i].telephoneNo = -1;
            }
        }

        void init(){
            for(int i=0; i<BSIZE; i++){
                LPHashtable[i].telephoneNo = -1;
                QPHashtable[i].telephoneNo = -1;
            }
        }

        void readData();
        void printData();

        void insertRecordLP();
        void displayRecordLP();
        void searchRecordLP(long int);

        void insertRecordQP();
        void displayRecordQP();
        void searchRecordQP();
};

void TelephoneDirectory::readData(){
    long int telephoneNo;
    string name;
    cout<<"\nEnter Client Telephone No.:: ";
    cin>>cObj.telephoneNo;
    cout<<"\nEnter Client name.:: ";
    cin>>cObj.name;
}

void TelephoneDirectory::printData(){
    cout<<"The Client telephone No.:: "<<cObj.telephoneNo<<endl;
    cout<<"The Client name:: "<<cObj.name<<endl;
}

void TelephoneDirectory::insertRecordLP(){
    int hi,noc,i;
    readData();
    printData();
    hi = cObj.telephoneNo % BSIZE;

    if(LPHashtable[hi].telephoneNo == -1){
        LPHashtable[hi] = cObj;
    } else {
        i = (hi +1) % BSIZE;
        while(i != hi){
            if(LPHashtable[i].telephoneNo == -1){
                LPHashtable[i] = cObj;
                break;
            }
            i = (i +1)% BSIZE;
        }
        if(i == hi){
            cout<<"\n Hash Table Full!!";
        }
    }
}

void TelephoneDirectory::searchRecordLP(long int telephoneNo){
    int hi,noc,i;
    hi = telephoneNo % BSIZE;
    noc = 0;
    i = hi;

    if(LPHashtable[i].telephoneNo == telephoneNo){
        noc++;
        cout<<"\nRecord Found with noc: "<<noc<<endl;
    } else {
        i = (hi+1)% BSIZE;
        while(i != hi){
            noc++;
            if(LPHashtable[i].telephoneNo == telephoneNo){
                cout<<"\nRecord Found with noc: "<<noc<<endl;
                break;
            }
            i = (i +1) % BSIZE;
            if (i == hi){
            cout<<"Record not found"<<endl;
            break;
            }
        }
        
    }
}

void TelephoneDirectory::displayRecordLP(){
    for(int i=0; i<BSIZE; i++){
        cout<<"\n"<<LPHashtable[i].telephoneNo<<"\t\t"<<LPHashtable[i].name<<endl;
    }
}

void TelephoneDirectory::insertRecordQP(){
    int hi,newHI;

    readData();

    hi = cObj.telephoneNo % BSIZE;

    if(QPHashtable[hi].telephoneNo == -1){
        QPHashtable[hi] = cObj;
        return;
    }

    for(int i=0; i<BSIZE; i++){
        newHI = (hi + i*i) % BSIZE;

        if(QPHashtable[newhI].telephoneNo == -1){
            QPHashtable[newHI] = cObj;
            return;
        }
    }

    cout<<"Record could not be stored!";
}

void TelephoneDirectory::searchRecordQP(){
    int hi, newHI, noc = 0;

    hi = telephoneNo % BSIZE;

    if(QPHashtable[hi].telephoneNo == telephoneNo){
        cout<<"\nRecord found after 1 comaprison "<<endl;
        return;
    }

    for(int i=1; i<BSIZE; i++){
        newHI = (hi + i*i) % BSIZE;
        noc++;

        if(QPHashtable[newHI].telephoneNo == telephoneNo){
            cout<<"Record Found with noc: "<<noc+1<<endl;
            return;
        }

        if(QPHashtable[newHI].telephoneNo == -1){
            break;
        }
    }

    cout<<"\nRecord NOT found even after "<<noc+1<<" comparisons!";
}

void TelephoneDirectory::displayRecordsQP(){
	cout<<"\nTelephone No."<<"\t"<<"   Name  ";
	for (int i=0;i<BSIZE;i++)
		cout<<"\n"<<QPHashTable[i].telephoneNo<<"\t"<<QPHashTable[i].name;
}

int main(){
    TelephoneDirectory t1;

    t1.insertRecordQP();
    t1.insertRecordQP();
    cout<<"displaying";
    t1.displayRecordQP();
    t1.searchRecordQP(123);
    t1.searchRecordQP(234);

}














