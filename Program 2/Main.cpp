//Drew Childs, Program 2 Main file
#include <iostream>
#include <stdexcept>
#include "Header.h"
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main() {
	int option;
	char main_menu = 'h';
	bool check1, check2;

	ifstream info("INFO.txt");		//opening files and running checks
	ifstream grades("Grades.txt");
	Student student_info;
	check1 = student_info.info_ReadData(info);
	check2 = student_info.grades_ReadData(grades);

	if (check1 && check2) {		//ensures both files are readable
		cout << "Welcome to the Weighted Average Application" << endl;
		cout << "----------------------------------------------------------" << endl;
		do {
			try {
				option = student_info.menu();		//ensures user enters a correct value
			}
			catch (runtime_error &exception) {
				cout << exception.what() << endl;
				continue;
			}

			switch (option) {		//runs the appropriate print function
			case 1:
				student_info.Roster();
				break;
			case 2:
				student_info.RosterGrades();
				break;
			case 3:
				student_info.RosterWeighted();
				break;
			case 4:
				exit(3);
				break;
			default:
				break;
			}

			cout << "----------------------------------------------------------" << endl;		//asks user if they'd like to return to main menu
			cout << "Press any key to return to main menu. Press N to stop --> ";
			cin >> main_menu;
			cout << "----------------------------------------------------------" << endl;
		} while (toupper(main_menu) != 'N');
	}
	else {
		cout << "Unable to locate or read files..." << endl << endl;		//what is printed if files aren't read correctly
	}

	info.close();
	grades.close();
	return 0;
}