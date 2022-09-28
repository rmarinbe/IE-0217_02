#include <map>
#include <iostream>
#include <cstring>
using namespace std;

struct lessthan_str
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

int main(void)
{
  map<const char*, int,lessthan_str> months;
  months["january"] = 31;
  months["february"] = 28;
  months["march"] = 31;
  months["april"] = 30;
  months["may"] = 31;
  months["june"] = 30;
  months["july"] = 31;
  months["august"] = 31;
  months["september"] = 30;
  months["october"] = 31;
  months["november"] = 30;
  months["december"] = 31;
  map<const char*, int,lessthan_str>::iterator begin,end;
  pair<const char*, int> data;
  begin=months.begin();
  end=months.end();
  while(begin != end)
  {
      data=*begin;
      cout << "Mes: " << data.first << " tiene " << data.second << " dias" << endl;
      begin++;
  }
}//main


