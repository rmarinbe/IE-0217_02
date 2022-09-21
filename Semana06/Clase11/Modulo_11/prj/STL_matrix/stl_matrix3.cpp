#include <iostream>
#include <vector>
using namespace std;

void main_stl_matrix3(void)
{
  int ii,jj;
   vector< vector<int> > vI2Matrix;
   vector<int> A, B;
   vector< vector<int> >::iterator iter_ii;
   vector<int>::iterator           iter_jj;

   A.push_back(10);
   A.push_back(20);
   A.push_back(30);
   B.push_back(100);
   B.push_back(200);
   B.push_back(300);

   vI2Matrix.push_back(A);
   vI2Matrix.push_back(B);

   cout << endl << "Using Iterator:" << endl;

   for(ii=0,iter_ii=vI2Matrix.begin(); iter_ii!=vI2Matrix.end(); iter_ii++,ii++)
   {
      for(jj=0,iter_jj=(*iter_ii).begin(); iter_jj!=(*iter_ii).end(); iter_jj++,jj++)
      {
         cout << "v[" <<ii <<"]["<<jj<<"]= "<< *iter_jj << endl;
      }
   }
}//___________________________________________________________________________________
