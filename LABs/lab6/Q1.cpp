#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void trim(string &str){
	//TODO
	str = str.erase(0,str.find_first_not_of(" "));
	str = str.erase(str.find_last_not_of(" ")+1);
	
}


void reverse(string &str){
	//TODO
	std::reverse(str.begin(),str.end());
	
}

int main()
{
    string input_line;
  	//TODO
  	int i;
  	getline(cin,input_line);
	trim(input_line);
  	reverse(input_line);
  	
    cout << input_line;
    return 0;
}
