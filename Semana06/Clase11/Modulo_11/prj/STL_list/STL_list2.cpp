// STL_list2.cpp
//+++++++++++++++

#include <iostream>
#include <string>
#include <list>
#include <ctype.h>  //isalpha() y tolower()
using namespace std;

//++++++++++++++++
// Template class
//++++++++++++++++
template <typename T> 
bool isPalindrome(const list<T>& inlist)
{
  list<T> copylist(inlist);
  while(copylist.size() >1 )
  {
    if (copylist.front() != copylist.back()) return false;
    copylist.pop_front();
    copylist.pop_back();
  }
  return true;       
}//_________________________________________________________


//+++++++++++++++
// Main()
//+++++++++++++++

int main(void)
{
  string str;
  list<char> charList;
  char ch;
  str="Madam I'm Adam";
  for (int i=0;i<str.length();i++)
  {
    ch = str[i];
    if (isalpha(ch))  charList.push_back(tolower(ch));
  }
  cout << "'" << str << "'" ;
  if (!isPalindrome(charList))  cout << "no";
  cout << " es palindrome " << endl;
}//________________________________________________________
