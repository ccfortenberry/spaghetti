/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* spaghet.hpp last rev. 2019-16-10
***********************************/
#ifndef SPAGHET_INCLUDED // Somebody toucha my spaghet!
#define SPAGHET_INCLUDED

#include <iostream> // To be removed whenever
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
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
			Noodle():_val(0), _order(-1) {};
			
			// Calculate new noodle distance from the tallest
			// This will be done in the box and updated accordingly
			Noodle(const T & val):_val(val), _order(-1) {}
			
			Noodle(T && val):_val(std::move(val)), _order(-1) {}
			
			T getVal() const {
				return _val;
			}
			
			unsigned int getOrder() const {
				return _order;
			}
			
			void setVal(const T & val) {
				_val = val;
			}
			
			void setOrder(const unsigned int & val) {
				_order = val;
			}
		private:
			T _val;
			unsigned int _order;
	};
	
	template <class T>
	class NoodleBox {
		public:
			// Default Ctor
			NoodleBox():_noodleVec(), _idxOfTallest(0) {};
			
			// Ctor from initializer_list
			NoodleBox(const std::initializer_list<T> & list):_idxOfTallest(0) {
				//_noodleVec.resize(std::distance(list.begin(), list.end()));
				for (auto i : list) {
					insertNoodle(Noodle<T>(i));
				}
			}
			
			// Ctor from iterators
			template <typename Iter>
			NoodleBox(Iter first, Iter last):_idxOfTallest(0) {
				for (auto f=first; f!=last; f++) {
					insertNoodle(Noodle<T>(*f));
				}
			}
			
			// Ctor from container by const reference
			template <template <typename> class Container>
			NoodleBox(const Container<T> & list):_idxOfTallest(0) {
				for (auto i=list.begin(); i!=list.end(); i++) {
					insertNoodle(Noodle<T>(*i));
				}
			}
			
			// Ctor from container by r-value reference
			template <template <typename> class Container>
			NoodleBox(Container<T> && list):_idxOfTallest(0) {
				for (auto i=list.begin(); i!=list.end(); i++) {
					insertNoodle(Noodle<T>(*i));
				}
			}
			
			// Assignment from container by const reference
			template <template <typename> class Container>
			NoodleBox<T> & operator=(const Container<T> & list) {
				return *NoodleBox<T>(list);
			}
			
			// Assignment from container by r-value reference
			template <template <typename> class Container>
			NoodleBox<T> & operator=(Container<T> && list) {
				return *NoodleBox<T>(std::move(list));
			}
			
			// Copy ctor
			NoodleBox(const NoodleBox<T> & other):_idxOfTallest(other.getIdxOfTallest()) {
				for (std::size_t i=0; i<other.size(); i++) {
					insertNoodle(other[i]);
				}
			}
			
			// Move ctor
			NoodleBox(NoodleBox<T> && other):_idxOfTallest(std::move(other.getIdxOfTallest())) {
				for (std::size_t i=0; i<other.size(); i++) {
					insertNoodle(other[i]);
				}
			}
			
			// Copy assignment
			NoodleBox<T> & operator=(const NoodleBox<T> & other) {
				return *NoodleBox<T>(other);
			}
			
			// Move assignment
			NoodleBox<T> & operator=(NoodleBox<T> && other) {
				return *NoodleBox<T>(std::move(other));
			}
			
			// Dtor
			~NoodleBox()=default;
			
			Noodle<T> getTallest() const {
				return _noodleVec[_idxOfTallest];
			}
			
			unsigned int getIdxOfTallest() const {
				return _idxOfTallest;
			}
			
			std::size_t size() const {
				return _noodleVec.size();
			}
			
			void insertNoodle(const Noodle<T> & noodle) {
				_noodleVec.push_back(noodle);
				
				for (unsigned int i=0; i<_noodleVec.size(); i++) {
					if (_noodleVec[size()-1].getVal() > _noodleVec[i].getVal()) {
						_noodleVec[i].setOrder(_noodleVec[i].getOrder()+1);
					}
					else {
						_noodleVec[size()-1].setOrder(_noodleVec[size()-1].getOrder()+1);
					}
				}
				if (_noodleVec[size()-1].getVal() > _noodleVec[_idxOfTallest].getVal()) _idxOfTallest = size()-1;
			}
			
			void insertNoodle(Noodle<T> && noodle) {
				_noodleVec.push_back(std::move(noodle));
				
				for (unsigned int i=0; i<_noodleVec.size(); i++) {
					if (_noodleVec[size()-1].getVal() > _noodleVec[i].getVal()) {
						_noodleVec[i].setOrder(_noodleVec[i].getOrder()+1);
					}
					else {
						_noodleVec[size()-1].setOrder(_noodleVec[size()-1].getOrder()+1);
					}
				}
				if (_noodleVec[size()-1].getVal() > _noodleVec[_idxOfTallest].getVal()) _idxOfTallest = size()-1;
			}
			
			// allow insert by a value instead of a raw noodle?
			
			Noodle<T> getNoodleAt(const unsigned int & index) const {
				return _noodleVec[index];
			}
			
			T operator[](const unsigned int & index) const {
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
			std::vector<Noodle<T> > _noodleVec;
			unsigned int _idxOfTallest;
	};
	
	template <typename T>
	void sort(NoodleBox<T> & b) {
		
	}
	
	template <typename RAIter>
	void sort(RAIter first, RAIter last) {
		NoodleBox<typename std::iterator_traits<RAIter>::value_type> temp(first, last);
		sort(temp);
		for (unsigned int i=0; i<temp.size(); i++)
			*first++ = temp[i];
	}
}

#endif //SPAGHET_INCLUDED