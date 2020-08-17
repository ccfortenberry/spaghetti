# Spaghetti Sort
A lot of people say that this is just a joke sort that isn't reasonably implementable in the way it was originally described by Alexander Dewdney in his Scientific American column, and to them I say HOW DARE YOU! Joke sorts are perfectly reasonable to implement even if they are only supposed to be a physical model of a linear-time sorting algorithm! The joke is only funny if we understand the context behind it.

## Goal
+ Time complexity: O(n)
+ Space complexity: O(n) - doesn't need to be in-place
+ Stable: yes

## Current
+ Time complexity: O(n*log(n))
+ Space complexity: O(n)
+ Stable: no\* (\*but can be made to be)

## Analysis
Even though the sort itself is worst case Linear-time, the process which I actually track the maximum is always Linearithmic since it updates the orders of each value every time a new value is inserted.  

The sort itself is also unstable as the first value it encounters for a sequence of given equivalent values will be put at the end of the sequence in the sorted array. This makes sense when you think about the physical model that inspired this. If we have two noodles that are of equivalent length and we take the "first" one and put it at the next available spot in the result pile, this will reverse the order in which the equivalent noodles are encountered (exactly how it works in the current implementation). However, if we change how we insert equivalent noodles then the sort can easily be made stable. In the physical model it's as simple as just putting the noodle behind its equivalent counterparts, in the code it's as simple as changing a `>` into a `>=` (ie. `temp[temp.size()-1].getVal() > temp[j].getVal()` into `temp[temp.size()-1].getVal() >= temp[j].getVal()`). This difference is shown in the stable vs. normal versions of the sort.

## Todo
- Get max tracking down to linear time
