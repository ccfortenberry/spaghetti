/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* main.cpp last rev. 2019-24-10
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
	cout << "Begin lemon testing to ensure basic functionality:\n_____________________________________" << endl;
	
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
		for (auto i : chararr) cout << i << ", ";
		cout << endl << "Start: ";
		for (auto i : charvec) cout << i << ", ";
		cout << endl;
		
		std::sort(chararr.begin(), chararr.end());
		spaghet::sort(charvec.begin(), charvec.end());
		
		cout << "Desired: ";
		for (auto i : chararr) cout << i << ", ";
		cout << endl << "Result: ";
		for (auto i : charvec) cout << i << ", ";
		cout << endl;
		
		try {
			for(unsigned int i=0; i<charvec.size(); i++) {
				if (chararr[i] != charvec[i]) throw runtime_error("sorting Failure!!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			return 1;
		}
		
		cout << "SORTED" << endl;
	}
		
	cout << endl;
		
	{
		cout << "Testing sort..." << endl;
		
		array<int,10> negarr = {0, -1, -2, -3, -4, -5, -6, -7, -8, -9};
		vector<int> negvec(negarr.begin(), negarr.end());
		
		cout << "Start: ";
		for (auto i : negarr) cout << i << ", ";
		cout << endl << "Start: ";
		for (auto i : negvec) cout << i << ", ";
		cout << endl;
		
		std::sort(negarr.begin(), negarr.end());
		spaghet::sort(negvec.begin(), negvec.end());
		
		cout << "Desired: ";
		for (auto i : negarr) cout << i << ", ";
		cout << endl << "Result: ";
		for (auto i : negvec) cout << i << ", ";
		cout << endl;
		
		try {
			for(unsigned int i=0; i<negvec.size(); i++) {
				if (negarr[i] != negvec[i]) throw runtime_error("sorting Failure!!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			return 1;
		}
		
		cout << "SORTED" << endl;
	}
	
	cout << endl;
		
	{
		cout << "Testing sort..." << endl;
		
		deque<float> floatdq = {10.2, 16.55, 22.22, 6.4, 39.0, 87.1, 87.2, 16.5, -59.4};
		vector<float> floatvec(floatdq.begin(), floatdq.end());
		
		cout << "Start: ";
		for (auto i : floatdq) cout << i << ", ";
		cout << endl << "Start: ";
		for (auto i : floatvec) cout << i << ", ";
		cout << endl;
		
		std::sort(floatdq.begin(), floatdq.end());
		spaghet::sort(floatvec.begin(), floatvec.end());
		
		cout << "Desired: ";
		for (auto i : floatdq) cout << i << ", ";
		cout << endl << "Result: ";
		for (auto i : floatvec) cout << i << ", ";
		cout << endl;
		
		try {
			for(unsigned int i=0; i<floatvec.size(); i++) {
				if (floatdq[i] != floatvec[i]) throw runtime_error("sorting Failure!!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			return 1;
		}
		
		cout << "SORTED" << endl;
	}
	
	cout << endl;
	
	cout << "_____________________________________\nAll tests passed!" << endl;
	
	return 0;
}