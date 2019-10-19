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

int main() {
	{
		cout << "Begin lemon testing to ensure basic functionality:\n_____________________________________" << endl;
		cout << "Testing namespace as a lemon test" << endl;
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
		testNood.setDistFromTallest(39);
		
		try {
			if (testNood.getDistFromTallest() != 39) throw runtime_error("Values are not equal when they should be!");
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
		cout << "Testing default NoodleBox creation..." << endl;
		
		try {
			NoodleBox<int> test;
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
		
		Noodle<int> testNood(39);
		NoodleBox<int> testBox;
		
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
		
		NoodleBox<int> testBox;
		
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
		cout << "Testing the insertion of a Noodle into a Box, with initializer list..." << endl;
		
		try {
			NoodleBox<int> testBox = {39, 42, 69, 100};
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
		
		Noodle<int> testNoodle(39);
		Noodle<int> compNoodle(39);
		NoodleBox<int> testBox;
		testBox.insertNoodle(testNoodle);
		
		try {
			//Noodle(39).getVal() == testBox[0].getVal();
			if (compNoodle.getVal() != testBox.getNoodleAt(0).getVal()) throw runtime_error("Values are not equal when they should be!");
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
		
		NoodleBox<int> testBox;
		testBox.insertNoodle(Noodle(39));
		
		try {
			if (testBox.getNoodleAt(0).getVal() != 39) throw runtime_error("Values are not equal when they should be!");
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
		
		vector<int> noodles = {1, 2, 5, 18, 22, 39, 42, 15, 6};
		NoodleBox<int> testBox = {1, 2, 5, 18, 22, 39, 42, 15, 6};
		
		try {
			for (unsigned int i=0; i<noodles.size(); i++) {
				if (noodles[i] != testBox[i]) throw runtime_error("Values are not equal when they should be!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle Lookup Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully found all Noodles in a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing to make sure that the distance of a noodle is correctly set..." << endl;
		
		NoodleBox<int> testBox = {10};
		
		try {
			if (testBox.getNoodleAt(0).getDistFromTallest() != 0) throw runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle distance Failure!!" << endl;
			cout << "(";
			for (unsigned int i=0; i<testBox.size(); i++) cout << testBox.getNoodleAt(i).getDistFromTallest() << ",";
			cout << ")" << endl;
			return 1;
		}
		
		cout << "Successfully verified Noodles' length in a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing to make sure that the distances from the longest noodle are correct..." << endl;
		
		vector<int> noodles = {1, 2, 5, 18, 22, 39, 42, 15, 6};
		vector<int> noodmax = {8, 7, 6, 3, 2, 1, 0, 4, 5};
		NoodleBox<int> testBox = {1, 2, 5, 18, 22, 39, 42, 15, 6};
		
		try {
			for (unsigned int i=0; i<noodles.size(); i++) {
				if (noodmax[i] != testBox.getNoodleAt(i).getDistFromTallest()) throw runtime_error("Values are not equal when they should be!");
			}
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical Noodle distance Failure!!" << endl;
			cout << "(";
			for (unsigned int i=0; i<testBox.size(); i++) cout << testBox.getNoodleAt(i).getDistFromTallest() << ","; 
			cout << ")" << endl;
			cout << "(";
			for (unsigned int i=0; i<testBox.size(); i++) cout << testBox[i] << ","; 
			cout << ")" << endl;
			return 1;
		}
		
		cout << "Successfully verified Noodles' length in a Box!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing to make sure that the index of the tallest noodle is correct..." << endl;
		
		unsigned int tallest = 6;
		NoodleBox<int> testBox = {1, 2, 5, 18, 22, 39, 42, 15, 6};
		
		try {
			if (testBox.getIdxOfTallest() != tallest) throw runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical tallest noodle index Failure!!" << endl;
			cout << testBox.getIdxOfTallest() << " != " << tallest << endl;
			return 1;
		}
		
		cout << "Successfully verified the index of the tallest noodle!!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing to make sure that the index of the tallest noodle is correct, but with floats!..." << endl;
		
		unsigned int tallest = 3;
		NoodleBox<float> testBox = {10.2, 6.8, 15.04, 22.9, 4.4};
		
		try {
			if (testBox.getIdxOfTallest() != tallest) throw runtime_error("Values are not equal when they should be!");
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical tallest noodle index Failure!!" << endl;
			cout << testBox.getIdxOfTallest() << " != " << tallest << endl;
			return 1;
		}
		
		cout << "Successfully verified the index of the tallest float noodle!!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing copying from another container..." << endl;
		
		vector<short> vecNood = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		
		try {
			NoodleBox<short> testBox = vecNood;
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical noodle container Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully created noodles from a vector!!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing copying from a double ended queue of negative noodles..." << endl;
		
		deque<long> vecNood = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0};
		
		try {
			NoodleBox<long> testBox(vecNood);
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical noodle container Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully created noodles from a deque!!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing copying from a list of chars..." << endl;
		
		list<char> vecNood = {'i', 't', 'a', 'L', 'y'};
		
		try {
			NoodleBox<char> testBox = vecNood;
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical noodle container Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully created noodles from a list!!" << endl;
	}
	
	cout << endl;
	
	{
		cout << "Testing copying from a std::array of chars..." << endl;
		
		array<char,5> vecNood = {'i', 't', 'a', 'L', 'y'};
		
		try {
			NoodleBox<char> testBox(vecNood.begin(), vecNood.end());
		}
		catch (const exception & e) {
			cout << e.what() << endl;
			cout << "Critical noodle container Failure!!" << endl;
			return 1;
		}
		
		cout << "Successfully created noodles from a list!!" << endl;
	}
	
	// Test copy and move ctors
	
	cout << endl;
	
	cout << "_____________________________________\nAll tests passed!" << endl;
	
	return 0;
}