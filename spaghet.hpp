/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* spaghet.hpp last rev. 2019-16-10
***********************************/
#ifndef SPAGHET_INCLUDED // Somebody toucha my spaghet!
#define SPAGHET_INCLUDED

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <vector> // May need to take away this so it can
                  // have its own functionality, someday

namespace spaghet {
	void printmeme() {
		std::cout << "Somebody toucha my spaghet!" << std::endl;
	}
	
	template <class T>
	class Noodle {
		public:
			Noodle():_val(0), _distFromTallest(-1) {};
			
			Noodle(const T & val):_val(val), _distFromTallest(-1) {
				// Calculate new noodle distance from the tallest
				// This will be done in the box and updated accordingly
			}
			
			T getVal() const {
				return _val;
			}
			
			int getDistFromTallest() const {
				return _distFromTallest;
			}
			
			void setVal(T val) {
				_val = val;
			}
			
			void setDistFromTallest(const int & distFromTallest) {
				_distFromTallest = distFromTallest;
			}
		private:
			T _val;
			int _distFromTallest;
	};
	
	template <class T>
	class NoodleBox {
		public:
			NoodleBox():_noodleVec(), _idxOfTallest(0) {};
			
			NoodleBox(const std::initializer_list<T> & list):_idxOfTallest(0) {
				for (auto i : list) {
					insertNoodle(Noodle<T>(i));
				}
			}
			
			template <typename Iter>
			NoodleBox(Iter first, Iter last):_idxOfTallest(0) {
				for (auto f=first; f!=last; f++)
					insertNoodle(Noodle<T>(*f));
			}
			
			template <template <typename> class AT>
			NoodleBox(const AT<T> & list):_idxOfTallest(0) {
				*this = list;
			}
			
			template <template <typename> class AT>
			NoodleBox(AT<T> && list):_idxOfTallest(0) {
				*this = std::move(list);
			}
			
			template <template <typename> class AT>
			void operator=(const AT<T> & list) {
				for (auto i=list.begin(); i!=list.end(); i++) {
					insertNoodle(Noodle<T>(*i));
				}
			}
			
			template <template <typename> class AT>
			void operator=(AT<T> && list) {
				for (auto i=list.begin(); i!=list.end(); i++) {
					insertNoodle(Noodle<T>(*i));
				}
			}
			
			NoodleBox(const NoodleBox<T> & other) {
				*this = other;
			}
			
			NoodleBox(NoodleBox<T> && other) {
				*this = std::move(other);
			}
			
			void operator=(const NoodleBox & other) {
				for (auto i=0; i<other.size(); i++) {
					_noodleVec[i] = other[i];
				}
				_idxOfTallest = other.getIdxOfTallest();
			}
			
			void operator=(NoodleBox<T> && other) {
				for (auto i=0; i<other.size(); i++) {
					_noodleVec[i] = std::move(other[i]);
				}
				_idxOfTallest = std::move(other.getIdxOfTallest());
			}
			
			~NoodleBox()=default;
			
			Noodle<T> getTallest() const {
				return _noodleVec[_idxOfTallest];
			}
			
			unsigned int getIdxOfTallest() const {
				return _idxOfTallest;
			}
			
			//void setTallest();
			
			/* void setIdxOfTallest(int idxOfTallest) {
				_idxOfTallest = idxOfTallest;
			} */
			
			// allow insert by a value instead of a raw noodle?
			
			std::size_t size() {
				return _noodleVec.size();
			}
			
			void insertNoodle(const Noodle<T> & noodle) {
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
			
			void insertNoodle(Noodle<T> && noodle) {
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
			
			Noodle<T> getNoodleAt(const unsigned int & index) {
				return _noodleVec[index];
			}
			
			T operator[](const unsigned int & index) {
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
			std::vector<Noodle<T>> _noodleVec;
			unsigned int _idxOfTallest;
	};
	
	template <typename T>
	void sort(const NoodleBox<T> & b) {
		
	}
	
	template <typename RAIter>
	void sort(RAIter first, RAIter last) {
		
	}
}

#endif //SPAGHET_INCLUDED