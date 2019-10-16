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
		cout << "Testing Noodle creation by value..." << endl;
		
		try {
			Noodle testNoodle(39);
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle by value Failure!" << endl;
			return 1;
		}
		
		cout << "Successfully created a Noodle with a value!" << endl;
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
	
	cout << endl;
	
	{
		cout << "Testing the insertion of a Noodle into a Box..." << endl;
		
		Noodle testNood(39);
		NoodleBox testBox;
		
		try {
			testBox.insertNoodle(testNood);
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Insertion Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully inserted a Noodle into a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing the insertion of a Noodle rvalue into a Box..." << endl;
		
		NoodleBox testBox;
		
		try {
			testBox.insertNoodle(Noodle(39));
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Insertion Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully inserted a Noodle into a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing the lookup of a Noodle in a Box..." << endl;
		
		Noodle testNoodle(39);
		Noodle compNoodle(39);
		NoodleBox testBox;
		testBox.insertNoodle(testNoodle);
		
		try {
			//Noodle(39).getVal() == testBox[0].getVal();
			if (compNoodle.getVal() != testBox.getNoodleAt(0).getVal()) throw std::runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Lookup Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully found a Noodle in a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing the lookup of a Noodle in a Box, but with rvalues..." << endl;
		
		NoodleBox testBox;
		testBox.insertNoodle(Noodle(39));
		
		try {
			if (testBox.getNoodleAt(0).getVal() != 39) throw std::runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Lookup Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully found a Noodle in a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing the lookup of a Noodle in a Box, but with operator[]..." << endl;
		
		NoodleBox testBox;
		testBox.insertNoodle(Noodle(39));
		
		try {
			if (testBox[0] != 39) throw std::runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Lookup Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully found a Noodle in a Box!" << endl;
	}
	
	return 0;
}