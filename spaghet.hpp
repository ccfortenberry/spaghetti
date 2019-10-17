/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* spaghet.hpp last rev. 2019-16-10
***********************************/
#ifndef SPAGHET_INCLUDED // Somebody toucha my spaghet!
#define SPAGHET_INCLUDED

#include <iostream>
#include <cstddef>
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
			
			Noodle(const int & val):_val(val) {
				// Calculate new noodle distance from the tallest
				// This will be done in the box and updated accordingly
			}
			
			int getVal() const {
				return _val;
			}
			
			int getDistFromTallest() const {
				return _distFromTallest;
			}
			
			void setVal(int val) {
				_val = val;
			}
			
			void setDistFromTallest(const int & distFromTallest) {
				_distFromTallest = distFromTallest;
			}
		private:
			int _val = 0;
			int _distFromTallest = -1;
	};
	
	class NoodleBox {
		public:
			NoodleBox()=default;
			
			// Template for abstract types?
			NoodleBox(const std::initializer_list<int> & initList) {
				for (auto i : initList) {
					insertNoodle(Noodle(i));
				}
			}
			// copy & move ctor
			// copy & move assignment
			
			Noodle getTallest() const {
				return _noodleVec[_idxOfTallest];
			}
			
			unsigned int getIdxOfTallest() const {
				return _idxOfTallest;
			}
			
			//void setTallest();
			
			void setIdxOfTallest(int idxOfTallest) {
				_idxOfTallest = idxOfTallest;
			}
			
			// allow insert by a value instead of a raw noodle?
			
			std::size_t size() {
				return _noodleVec.size();
			}
			
			void insertNoodle(const Noodle & noodle) {
				_noodleVec.push_back(noodle);
				
				for (unsigned int i=0; i<_noodleVec.size(); i++) {
					if (_noodleVec[size()-1].getVal() > _noodleVec[i].getVal()) {
						_noodleVec[i].setDistFromTallest(_noodleVec[i].getDistFromTallest()+1);
					}
					else {
						_noodleVec[size()-1].setDistFromTallest(_noodleVec[size()-1].getDistFromTallest()+1);
					}
				}
				if (_noodleVec[size()-1].getVal() > _noodleVec[_idxOfTallest].getVal()) _idxOfTallest = size()-1;
			}
			
			void insertNoodle(Noodle && noodle) {
				_noodleVec.push_back(noodle);
				
				for (unsigned int i=0; i<_noodleVec.size(); i++) {
					if (_noodleVec[size()-1].getVal() > _noodleVec[i].getVal()) {
						_noodleVec[i].setDistFromTallest(_noodleVec[i].getDistFromTallest()+1);
					}
					else {
						_noodleVec[size()-1].setDistFromTallest(_noodleVec[size()-1].getDistFromTallest()+1);
					}
				}
				if (_noodleVec[size()-1].getVal() > _noodleVec[_idxOfTallest].getVal()) _idxOfTallest = size()-1;
			}
			
			Noodle getNoodleAt(const unsigned int & index) {
				return _noodleVec[index];
			}
			
			int operator[](const unsigned int & index) {
				return _noodleVec[index].getVal();
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
			unsigned int _idxOfTallest = 0;
			
			void incDistFromTallest(const unsigned int & ignore) {
				for (unsigned int i=0; i<_noodleVec.size(); i++) 
					if (i != ignore) _noodleVec[i].setDistFromTallest(_noodleVec[i].getDistFromTallest()+1);
			}
			
			void decDistFromTallest() {
				for (auto i : _noodleVec) i.setDistFromTallest(i.getDistFromTallest()-1);
			}
	};
}

#endif //SPAGHET_INCLUDED