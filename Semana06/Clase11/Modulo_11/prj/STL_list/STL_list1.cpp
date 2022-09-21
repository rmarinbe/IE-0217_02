//+++++++++++++++++++++++++++++++++++++++++++++++++
// STL_list1.cpp
// Codigo para prueba de concepto vector de STL
//+++++++++++++++++++++++++++++++++++++++++++++++++
#define __MINMAX_DEFINED 
#include <list> 
#include <iostream>

using namespace std;

int main (void)
{
  list<int> bit_seq; // define a list of int
  int input = 0; // value read from cin
  int count_1 = 0; // counter for number of 1's
  cout << "Insert values 0 and 1, another value to stop input..." << endl;
  while (cin >> input) 
  {
    if (!(input == 0 || input == 1)) break;
    bit_seq.push_back (input); // list member function push_back
  }//while
  
  // output loop
  cout << "Original bit sequence:" << endl;
  
  // define an iterator to the first list element
  list<int>::iterator first = bit_seq.begin();
  // define an iterator past(!) the last list element
  list<int>::iterator last = bit_seq.end();
  while (first != last)
    cout << *first++; // dereference iterator to get value
    
  // then increment iterator
  cout << endl;
  
  // create a new list for bit_stuffing
  list<int> bit_stuffed_seq (bit_seq);
  
  // define loop iterators
  first = bit_stuffed_seq.begin();
  last = bit_stuffed_seq.end();
  
  // bit stuff loop
  while (first != last) 
  {
    if (*first == 0)
      count_1 = 0;       // reset 1's-counter
    else if (*first == 1)
      count_1++;         // increment number of
                         // consecutive 1's
    first++; // go to the next list element
    if (count_1 == 5) 
    {
      // insert a 0 after the fifth consecutive 1
      bit_stuffed_seq.insert (first, 0);
      count_1 = 0; // reset counter
    }//if
  }//while

  // output loop
  cout << "Bit-stuffed bit sequence:" << endl;
  first = bit_stuffed_seq.begin();
  last = bit_stuffed_seq.end();
  while (first != last)
    cout << *first++; // dereference iterator to get value
    
  // then increment iterator
  cout << endl;
}//_______________________________________________________________
