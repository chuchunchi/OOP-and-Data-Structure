#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    string name;
    int exam_scores[4]; 
	Student(string student_name); 
    int get_minimum_final_score();
    void print_name_and_score();
    
};

int main() {
    
    string student_name;
    cin >> student_name;
    Student student(student_name);
    for(int i = 0; i < 3; i++){
        cin >> student.exam_scores[i];
    }
    student.get_minimum_final_score();
    student.print_name_and_score();
    return 0;
}

Student::Student(string student_name):name(student_name){//constructor
}
int Student::get_minimum_final_score(){
	int sum1to3=0,final_score,i;
	for(i=0;i<3;i++){
		if(exam_scores[i]<0){
			exam_scores[i] = 0;
		}
		sum1to3+=exam_scores[i];
	}
	final_score = 60*4 - sum1to3;
	if(final_score<0){
		final_score = 0;
	}
	return final_score;
}

void Student::print_name_and_score(){
	cout << name << ' ' << get_minimum_final_score() << endl;
}
