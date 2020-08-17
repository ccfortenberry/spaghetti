/***********************************
* Curtis Fortenberry
* Spaghetti Sort
* spaghet.hpp last rev. 2019-24-10
***********************************/
#ifndef SPAGHET_INCLUDED // Somebody toucha my spaghet!
#define SPAGHET_INCLUDED

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

namespace spaghet {
	/**************************************************************************
	* -- Noodle class --
	* DESC: really just so i have one less header to include (ie. pair)
	* CONSTRAINTS: T should be an ordinal type
	**************************************************************************/
	template <class T>
	class Noodle {
		public:
			Noodle():_val(0), _order(-1) {};
			
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
	
	/**************************************************************************
	* -- sort --
	* DESC: the sorting algorithm, based on Spaghetti Sort
	* IN: iterators to the begin() and end() of a given container
	* OUT: none
	* SE: sorts the given range and loads it back to the given container using 
	* its iterators
	**************************************************************************/
	template <typename Iter>
	void sort(Iter first, Iter last) {
		// Initialization of temporaries needed to make the alg work
		// This makes the sort not in-place, with linear complexity
		auto it = first;
		auto size = std::distance(first, last);
		using T = typename std::iterator_traits<Iter>::value_type;
		std::vector<Noodle<T>> temp;
		temp.reserve(size);
		
		// Insertion and max tracking
		// Time: O(n^2)
		for (unsigned int i=0; i<size; i++) {
			temp.push_back(*it++);
			auto width = temp.size();
			
			for (unsigned int j=0; j<width; j++) {
				if (temp[width-1].getVal() > temp[j].getVal()) 
					temp[j].setOrder(temp[j].getOrder()+1);
				else 
					temp[width-1].setOrder(temp[width-1].getOrder()+1);
			}
		}
		
		// Debug output
		/* std::cout << "Dist: ";
		for (auto i : temp) std::cout << i.getOrder() << ", ";
		std::cout << std::endl << "Val: ";
		for (auto i : temp) std::cout << i.getVal() << ", ";
		std::cout << std::endl; */
		
		// The Sort
		// Time: O(n)
		for (unsigned int i=0; i<size; i++) 
			*(last-temp[i].getOrder()-1) = temp[i].getVal();
	}
	
	/**************************************************************************
	* -- stable sort --
	* DESC: same as above, but stable
	**************************************************************************/
	template <typename Iter>
	void sort_stable(Iter first, Iter last) {
		// Initialization of temporaries needed to make the alg work
		// This makes the sort not in-place, with linear complexity
		auto it = first;
		auto size = std::distance(first, last);
		using T = typename std::iterator_traits<Iter>::value_type;
		std::vector<Noodle<T>> temp;
		temp.reserve(size);
		
		// Naive insertion and max tracking
		// O(n^2)
		for (unsigned int i=0; i<size; i++) {
			temp.push_back(*it++);
			auto width = temp.size();
			
			for (unsigned int j=0; j<width; j++) {
				if (temp[width-1].getVal() >= temp[j].getVal()) 
					temp[j].setOrder(temp[j].getOrder()+1);
				else 
					temp[width-1].setOrder(temp[width-1].getOrder()+1);
			}
		}
		
		// Debug output
		/* std::cout << "Dist: ";
		for (auto i : temp) std::cout << i.getOrder() << ", ";
		std::cout << std::endl << "Val: ";
		for (auto i : temp) std::cout << i.getVal() << ", ";
		std::cout << std::endl; */
		
		// The Sort
		// Time: O(n)
		for (unsigned int i=0; i<size; i++) 
			*(last-temp[i].getOrder()-1) = temp[i].getVal();
	}
}

#endif //SPAGHET_INCLUDED