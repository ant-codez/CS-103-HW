#include "cperson.h"
#include <iostream>
#include <string.h>

using namespace std;

//default constructor
CPerson::CPerson(){
	cout << "Default Constructor!\n\n";

    m_name = new char[256];
	strcpy(m_name, "Clark Kent");
    m_age = 0;
}

//type constructor
CPerson::CPerson(char *name, int age){
	cout << "Type Constructor!\n\n";

    m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	m_age = age;
}

//copy constructor
CPerson::CPerson(CPerson &copy) {
	cout << "Copy Constructor!\n\n";

    m_name = new char[strlen(copy.m_name) + 1];
	strcpy(m_name, copy.m_name);
	m_age = copy.m_age;
}

CPerson::~CPerson() {
    cout << "Destructor\n";

    delete m_name;
}

// function prototypes
void CPerson::DisplayData() {
	cout << "Name: " << m_name << endl;
	cout << "Age: " << m_age;
}

void CPerson::GetData() {
	cin >> m_name >> m_age;
}

void CPerson::SetAge(int age){
    m_age = age;
}

void CPerson::SetName(char *name){
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

bool CPerson::operator==(const CPerson &a){
	if (m_age == a.m_age){
		return true;
	}
	else{
		return false;
	}
}

bool CPerson::operator>(const CPerson &a){
	if (m_age > a.m_age){
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream &outStream, CPerson &a){
	//a.DisplayData();
    outStream << "Name: " << a.GetName() << endl;
    outStream << "\tAge: " << a.GetAge();

	return outStream;
}

istream& operator >>(istream &inStream, CPerson &a) {
	char name[256];
	int	 age;

	inStream >> name >> age;

	a.SetName(name);
	a.SetAge(age);

	return inStream;
}