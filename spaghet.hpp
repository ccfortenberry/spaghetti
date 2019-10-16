/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* spaghet.hpp last rev. 2019-16-10
***********************************/
#ifndef SPAGHET_INCLUDED // Somebody toucha my spaghet!
#define SPAGHET_INCLUDED

#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector> // May need to take away this so it can
                  // have its own functionality, someday

namespace spaghet {
	void printmeme() {
		std::cout << "Somebody toucha my spaghet!" << std::endl;
	}
	
	class Noodle {
		public:
			Noodle()=default;
			
			Noodle(const int & val):_val(val), _distFromTallest(-1) {
				// Calculate new noodle distance from the tallest
				// This will be done in the box and updated accordingly
			}
			
			int getVal() {
				return _val;
			}
			
			int getDistFromTallest() {
				return _distFromTallest;
			}
			
			void setVal(int val) {
				_val = val;
			}
			
			void setDistFromTallest(int distFromTallest) {
				_distFromTallest = distFromTallest;
			}
		private:
			int _val;
			int _distFromTallest;
	};
	
	class NoodleBox {
		public:
			NoodleBox()=default;
			
			NoodleBox(const std::initializer_list<int> & initList) {
				for (auto i : initList) {
					this->insertNoodle(Noodle(i));
				}
			}
			// copy & move ctor
			// copy & move assignment
			
			Noodle getTallest() {
				return _noodleVec[_idxOfTallest];
			}
			
			int getIdxOfTallest() {
				return _idxOfTallest;
			}
			
			//void setTallest();
			
			void setIdxOfTallest(int idxOfTallest) {
				_idxOfTallest = idxOfTallest;
			}
			
			// allow insert by a value instead of a raw noodle?
			
			void insertNoodle(const Noodle & noodle) {
				_noodleVec.push_back(noodle);
				// Adjust elements to accurately have
				// distance from the tallest noodle
			}
			
			void insertNoodle(Noodle && noodle) {
				_noodleVec.push_back(noodle);
				// Adjust elements to accurately have
				// distance from the tallest noodle
			}
			
			int operator[](const unsigned int & index) {
				return _noodleVec[index].getVal();
			}
			
			Noodle getNoodleAt(const unsigned int & index) {
				return _noodleVec[index];
			}
			
			void removeNoodle(const unsigned int & noodleIdx) {
				_noodleVec.erase(_noodleVec.begin()+noodleIdx);
				// Adjust elements to have accurate distFromTallest
			}
		private:
			//std::vector<std::unique_ptr<Noodle>> _noodleVec; taking references to noodles instead of noodle
			//objects as an optimization. But would we want to have a box of noodles that only contain the
			//locations of noodles instead of actual noodles themselves? sounds unappetizing to me...
			std::vector<Noodle> _noodleVec;
			int _idxOfTallest;
	};
}

#endif //SPAGHET_INCLUDED