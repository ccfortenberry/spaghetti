/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* main.cpp last rev. 2019-16-10
***********************************/
#include "spaghet.hpp"
using spaghet::Noodle;
using spaghet::NoodleBox;

// iostream included in header
using std::cout;
using std::endl;
#include <exception>
using std::exception;

int main() {
	{
		cout << "Testing namespace as a lemon test" << endl;
		spaghet::printmeme();
	}
	
	cout << endl;
	
	{
		cout << "Testing default Noodle creation..." << endl;
		
		try {
			Noodle testNoodle;
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Failure!" << endl;
			return 1;
		}
		
		cout << "Successfully created a default Noodle!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing default NoodleBox creation..." << endl;
		
		try {
			NoodleBox test;
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical NoodleBox Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully made a box of noodles!!" << endl;
	}
	
	return 0;
}