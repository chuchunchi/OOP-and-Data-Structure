#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_address(){
    	//TODO 
		string address; 
		address = "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm " + \
		getDormitory() + ", (" + getID() + ") " + getFirstName() + " " + getLastName();
		return address;   
    }

  	//Please implement the remain class
  	string getFirstName() const{
  		return first_name;
	}
	string getLastName() const{
  		return last_name;
	}
	string getDormitory() const{
  		return dormitory;
	}
	string getID() const{
  		return ID;
	}
	void setFirstName(string fname){
  		first_name = fname;
	}
	void setLastName(string lname){
  		last_name = lname;
	}
	void setDormitory(string dor){
  		dormitory = dor;
	}
	void setID(string id){
  		ID = id;
	}
private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
    /* Enter your code here. Read input from STDIN */
    string fname,lname,dor,id;
    cin >> fname >> lname >> dor >> id ;
    mStudent.setFirstName(fname);
    mStudent.setLastName(lname);
    mStudent.setDormitory(dor);
    mStudent.setID(id);
    //cout << mStudent.getDormitory();
    //cout << mStudent.getFirstName();
    //cout << mStudent.getLastName();
    //cout << mStudent.getID();
  	cout << mStudent.generate_address() << endl;
    return 0;
}
