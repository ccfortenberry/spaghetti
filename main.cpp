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
#include <chrono>
// for std::chrono;

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
	
	{
		cout << "Testing sort for stability..." << endl;
		
		vector<int> vecOf39(10, 39);
		vector<int> copyVec(vecOf39.begin(), vecOf39.end());
		
		cout << "Start: ";
		for (auto i : vecOf39) cout << i << ", ";
		cout << endl << "Start: ";
		for (auto i : copyVec) cout << i << ", ";
		cout << endl;
		
		std::sort(vecOf39.begin(), vecOf39.end());
		spaghet::sort(copyVec.begin(), copyVec.end());
		
		cout << "Desired: ";
		for (auto i : vecOf39) cout << i << ", ";
		cout << endl << "Result: ";
		for (auto i : copyVec) cout << i << ", ";
		cout << endl;
		
		try {
			for(unsigned int i=0; i<copyVec.size(); i++) {
				if (vecOf39[i] != copyVec[i]) throw runtime_error("sorting Failure!!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			return 1;
		}
		
		cout << "SORTED, but the sort is UNSTABLE as the first value encountered for a repeated value will be sent to the back of its sequence" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing sort for stability..." << endl;
		
		vector<int> vecOf39(10, 39);
		vector<int> copyVec(vecOf39.begin(), vecOf39.end());
		
		cout << "Start: ";
		for (auto i : vecOf39) cout << i << ", ";
		cout << endl << "Start: ";
		for (auto i : copyVec) cout << i << ", ";
		cout << endl;
		
		std::sort(vecOf39.begin(), vecOf39.end());
		spaghet::sort_stable(copyVec.begin(), copyVec.end());
		
		cout << "Desired: ";
		for (auto i : vecOf39) cout << i << ", ";
		cout << endl << "Result: ";
		for (auto i : copyVec) cout << i << ", ";
		cout << endl;
		
		try {
			for(unsigned int i=0; i<copyVec.size(); i++) {
				if (vecOf39[i] != copyVec[i]) throw runtime_error("sorting Failure!!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			return 1;
		}
		
		cout << "SORTED, and the sort is STABLE" << endl;
	}
	
	cout << endl;
	
	cout << "_____________________________________\nAll tests passed!" << endl;
	
	cout << endl;
	
	{
		cout << "Comparing time to std::sort..." << endl;
		
		unsigned int size = 100000;
		
		vector<int> v1(size);
		generate(v1.begin(), v1.end(), []() { return rand()%100000; });
		vector<int> v2(v1);
		vector<int> v3(v1);
		
		auto start = std::chrono::high_resolution_clock::now();
		std::sort(v1.begin(), v1.end());
		auto stop = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> dur = stop - start;
		cout << "std::sort took: " << dur.count() << "s" << endl;
		
		start = std::chrono::high_resolution_clock::now();
		spaghet::sort(v2.begin(), v2.end());
		stop = std::chrono::high_resolution_clock::now();
		dur = stop - start;
		cout << "unstable spaghetti sort took: " << dur.count() << "s" << endl;
		
		start = std::chrono::high_resolution_clock::now();
		spaghet::sort_stable(v3.begin(), v3.end());
		stop = std::chrono::high_resolution_clock::now();
		dur = stop - start;
		cout << "stable spaghetti sort took: " << dur.count() << "s" << endl;
		
	}
	
	cout << endl;
	
	cout << "Testing complete!" << endl;
	return 0;
}