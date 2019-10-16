/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* spaghet.hpp last rev. 2019-16-10
***********************************/
#ifndef SPAGHET_INCLUDED // Somebody toucha my spaghet!
#define SPAGHET_INCLUDED

#include <iostream>
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
			
			void insertNoodle(const Noodle & noodle) {
				_noodleVec.push_back(noodle);
			}
			
			void insertNoodle(Noodle && noodle) {
				_noodleVec.push_back(noodle);
			}
			
			void removeNoodle(const unsigned int & noodleIdx) {
				_noodleVec.erase(_noodleVec.begin()+noodleIdx);
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