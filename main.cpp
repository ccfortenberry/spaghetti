/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* main.cpp last rev. 2019-16-10
***********************************/
#include "spaghet.hpp"
using spaghet::Noodle;

// iostream included in header
using std::cout;
using std::endl;
// vector included in header
using std::vector;
#include <deque>
using std::deque;
#include <list>
using std::list;
#include <array>
using std::array;
#include <exception>
using std::exception;
using std::runtime_error;
#include <algorithm>
// for std::sort;

int main() {
	{
		cout << "Begin lemon testing to ensure basic functionality:\n_____________________________________" << endl;
		cout << "Testing namespace as the lemon-est lemon test" << endl;
		spaghet::printmeme();
	}
	
	cout << endl;
	
	{
		cout << "Testing default Noodle creation..." << endl;
		
		try {
			Noodle<int> testNoodle;
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
			Noodle<int> testNoodle(39);
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
		cout << "Testing Noodle distance from tallest..." << endl;
		
		Noodle<int> testNood(39);
		testNood.setOrder(0);
		
		try {
			if (testNood.getOrder() != 0) throw runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle by value Failure!" << endl;
			return 1;
		}
		
		cout << "Successfully tested noodle distance from tallest!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing sort..." << endl;
		
		array<char,5> chararr = {'i', 't', 'a', 'L', 'y'};
		vector<char> charvec(chararr.begin(), chararr.end());
		
		cout << "Start: ";
		for (auto i : chararr) cout << i;
		cout << endl << "Start: ";
		for (unsigned int i=0; i<charvec.size(); i++) cout << charvec[i];
		cout << endl;
		
		std::sort(chararr.begin(), chararr.end());
		spaghet::sort(charvec.begin(), charvec.end());
		
		try {
			for(unsigned int i=0; i<charvec.size(); i++) {
				if (chararr[i] != charvec[i]) throw runtime_error("sorting Failure!!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Desired: ";
			for (auto i : chararr) cout << i;
			cout << endl << "Result: ";
			for (unsigned int i=0; i<charvec.size(); i++) cout << charvec[i];
			cout << endl;
			
			return 1;
		}
		
		cout << "SORTED" << endl;
	}
	
	// Test copy and move ctors
	
	cout << endl;
	
	cout << "_____________________________________\nAll tests passed!" << endl;
	
	return 0;
}