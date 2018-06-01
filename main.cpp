#include <iostream>
#include "LinkedList.h"

using namespace std;

typedef struct SStudent{
	char name[20];
	int age;
} Student;

void clean_stdin(){
	char key;
	do{
		key = getchar();
	} while(key != '\n' && key != EOF);
}



int main(int argc, char** argv) {
	
	char key;
	int index;
	LinkedList<Student> list_student;
	
	do{
		cout << "1. Insert a new student to list\n";
		cout << "2. Delete a student from list\n";
		cout << "3. Edit a student in list\n";
		cout << "4. Print out list of student\n";
		cout << "5. Exit\n";
		cin >> key;
		clean_stdin();
		switch(key){
			case '1':
				Student student;
				cout << "Enter name: ";
				cin.getline(student.name,sizeof(student.name));
				cout << "Enter age: ";
				cin >> student.age;
				clean_stdin();
				list_student.push_back(student);
				break;
			case '2':				
				cout << "Enter index: ";
				cin >> index;
				clean_stdin();
				list_student.delete_at(index);
				break;
			case '3':
				cout << "Enter index: ";
				cin >> index;
				clean_stdin();
				Student stTemp;
				cout << "Enter name: ";
				cin.getline(stTemp.name,sizeof(stTemp.name));
				cout << "Enter age: ";
				cin >> stTemp.age;
				clean_stdin();
				list_student.edit_at(index,stTemp);
				break;
			case '4':{
				
					Student st_temp;
					unsigned int len = list_student.len();
					cout << "\n------\n";
					for(unsigned int i = 0; i< len; i++){
						st_temp = list_student.get(i);
						cout << "Name: " << st_temp.name << ", age: " << st_temp.age << endl;
						
					}
					cout << "\n------\n";
				}
				break;
			case '5':
				return 0;
				break;
			default:
				break;
		}
	}while(1);
	
	return 0;
}

