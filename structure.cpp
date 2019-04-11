#include<iostream>
#include <cstring>
using namespace std;
struct Persons{
	char firstname[20];
	char lastname[20];
	int salary;
	int phone;
};
void getPerson( struct Persons person);
int main(){
	struct Persons person1;
	struct Persons person2;
	
	strcpy(person1.firstname, "TARIQUL");
	strcpy(person1.lastname, "ISLAM");
	person1.salary= 12345432;
	person1.phone= 13456343564;

	
	strcpy(person2.firstname, "NAZRUL");
	strcpy(person2.lastname, "ISLAM");
	person2.salary= 122342353;
	person2.phone= 111103094;
	
	getPerson(person1);
	cout<<"**************\n";
	getPerson(person2);
	return 0;
}
void getPerson(struct Persons person){
	cout<<"FIRST NAME: "<< person.firstname<<endl;
	cout<<"LAST NAME: "<<person.lastname<<endl;
	cout<<"SALARY: "<<person.salary<<endl;
	cout<<"PHONE: "<<person.phone<<endl;	
}
