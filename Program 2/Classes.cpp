//Drew Childs, Program 2 Classes File
#include <iostream>
#include <stdexcept>
#include <string>
#include "Header.h"
#include <vector>
using namespace std;

int Student::get_ID() { return student_id; }			//Getters and setter function definitions
void Student::set_ID(int st_id) { student_id = st_id; }
string Student::get_first() { return first_name; }
void Student::set_first(string first) { first_name = first; }
string Student::get_last() { return last_name; }
void Student::set_last(string last) { last_name = last; }
int Student::get_q1() { return quiz1; }
void Student::set_q1(int quiz) { quiz1 = quiz; }
int Student::get_q2() { return quiz2; }
void Student::set_q2(int quiz) { quiz2 = quiz; }
int Student::get_midterm() { return midterm; }
void Student::set_midterm(int mid) { midterm = mid; }
int Student::get_final() { return finale; }
void Student::set_final(int finish) { finale = finish; }

Student::Student() {		//default constructor
	student_id = -1;
	last_name = "NoName";
	first_name = "NoName";
}

Student::Student(int Student_ID, string Last_Name, string First_Name) {			//constructor for new student
	if (Student_ID < 0) {
		student_id = -1;
	}
	else {
		student_id = Student_ID;
	}
	last_name = Last_Name;
	first_name = First_Name;
}

void Student::Grades(int Student_ID, int Quiz1, int Quiz2, int Midterm, int Final) {	//constructor for grades for students	
	student_id = Student_ID;
	quiz1 = Quiz1;
	quiz2 = Quiz2;
	midterm = Midterm;
	finale = Final;
}

int Student::menu() {		//function prints menu and returns appropriate value to main function
	int option;
	cout << "Please make a selection:" << endl;
	cout << "(1) Print class roster" << endl;
	cout << "(2) Print class roster with their grades" << endl;
	cout << "(3) Print class roster with students' weighted grades" << endl;
	cout << "(4) Exit" << endl;
	cout << "Enter your choice: ";
	cin >> option;

	if (cin.fail()) {		//if the user enters in something invalid
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	throw runtime_error("Invalid input. Please enter a integer between 1 and 4.");
	}
	if (option < 1 || option > 4) {
	throw runtime_error("Invalid input. Please enter a integer between 1 and 4.");
	}

	return option;
}

void Student::Roster() {		//prints out student names and id's
	cout << endl << "Reading file... The class has " << info_vector.size() << " students:" << endl;
	for (unsigned i = 0; i < info_vector.size(); i++) {
		cout << info_vector.at(i).get_ID() << "\t" << info_vector.at(i).FullName() << endl;
	}
}

void Student::RosterGrades() {		//prints out student names and their grades
	cout << endl << "Reading the grades file..." << endl;
	for (unsigned i = 0; i < info_vector.size(); i++) {		//loops ensure it prints acurrate data with corresponding student id's
		for (unsigned z = 0; z < grade_vector.size() - 1; z++) {
			if (info_vector.at(i).get_ID() == grade_vector.at(z).get_ID()) {
				cout << info_vector.at(i).FullName() << "\t" << grade_vector.at(z).get_q1() << " " << grade_vector.at(z).get_q2() << " ";
				cout << grade_vector.at(z).get_midterm() << " " << grade_vector.at(z).get_final() << endl;
			}
		}
	}
}

void Student::RosterWeighted() {		//prints out students name and final grade
	cout << endl;
	for (unsigned i = 0; i < info_vector.size(); i++) {		////loops ensure it prints acurrate data with corresponding student id's
		for (unsigned z = 0; z < grade_vector.size() - 1; z++) {
			if (info_vector.at(i).get_ID() == grade_vector.at(z).get_ID()) {
				cout << "Weighted average score of\t" << info_vector.at(i).FullName() << " is\t";
				cout << grade_vector.at(z).FindAverage() << "\tout of 100%" << endl;
			}
		}
	}
}

bool Student::info_ReadData(istream &in_file) {		//reads data from the info file
	int id;
	string first, last;

	try {
		while (in_file.good()) {		//reads data and puts it in respective vector
			in_file >> id >> first >> last;
			Student currStudent(id, last, first);
			info_vector.push_back(currStudent);
		}
	}
	catch (...) {
		return false;
	}
	return true;
}

bool Student::grades_ReadData(istream &gr_file) {		//reads data from the grades file
	int id, Quiz1, Quiz2, Midterm, Final;

	try {
		while (gr_file.good()) {		//reads data and puts it in the respective vector
			Student currGrade;
			gr_file >> id >> Quiz1 >> Quiz2 >> Midterm >> Final;
			currGrade.Grades(id, Quiz1, Quiz2, Midterm, Final);
			grade_vector.push_back(currGrade);
		}
	}
	catch (...) {
		return false;
	}

	return true;
}

string Student::FullName() {		//returns student's full name
	return last_name + ", " + first_name;
}

double Student::FindAverage() {		//finds student's final grade
	return (((((quiz1 * 10) + (quiz2 * 10)) / 2) * 0.25) + (midterm * 0.25) + (finale * 0.5));
}