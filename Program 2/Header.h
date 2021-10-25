//Drew Childs, Program 2 Header File
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#pragma once
using namespace std;

class Student {
public:
	Student();				//<-- all other functions
	Student(int Student_ID, string Last_Name, string First_Name);
	void Grades(int Student_ID, int Quiz1, int Quiz2, int Midterm, int Final);
	int menu();
	void Roster();
	void RosterGrades();
	void RosterWeighted();
	bool info_ReadData(istream &in_file);
	bool grades_ReadData(istream &gr_file);
	string FullName();
	double FindAverage();

	int get_ID();					//<-- Getters and Setters
	void set_ID(int st_id);
	string get_first();
	void set_first(string first);
	string get_last();
	void set_last(string last);
	int get_q1();
	void set_q1(int quiz);
	int get_q2();
	void set_q2(int quiz);
	int get_midterm();
	void set_midterm(int mid);
	int get_final();
	void set_final(int finish);

private:
	int student_id, quiz1, quiz2, midterm, finale;		//<-- private variables and vectors
	string last_name;
	string first_name;
	vector<Student> info_vector;
	vector<Student> grade_vector;
};