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
	
	template <typename Iter>
	void sort(Iter first, Iter last) {
		auto it = first;
		auto size = std::distance(first, last);
		std::vector<Noodle<typename std::iterator_traits<Iter>::value_type>> temp;
		
		// Naive insertion and max tracking
		// O(n*lg(n))
		for (unsigned int i=0; i<size; i++) {
			temp.push_back(*it++);
			auto width = temp.size();
			
			for (unsigned int j=0; j<width; j++) {
				if (temp[temp.size()-1].getVal() > temp[j].getVal()) 
					temp[j].setOrder(temp[j].getOrder()+1);
				else 
					temp[temp.size()-1].setOrder(temp[temp.size()-1].getOrder()+1);
			}
		}
		
		// Debug output
		/* std::cout << "Dist: ";
		for (auto i : temp) std::cout << i.getOrder();
		std::cout << std::endl << "Val: ";
		for (auto i : temp) std::cout << i.getVal();
		std::cout << std::endl << "Max idx: " << maxIdx << std::endl; */
		
		// The Sort
		// O(n)
		for (unsigned int i=0; i<size; i++) 
			*(last-temp[i].getOrder()-1) = temp[i].getVal();
	}
}

#endif //SPAGHET_INCLUDED