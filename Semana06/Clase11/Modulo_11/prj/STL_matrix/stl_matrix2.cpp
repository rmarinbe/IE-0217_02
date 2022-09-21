#include <iostream>
#include <vector>

using namespace std;

void main_stl_matrix2(void )
{
  vector< vector< vector<int> > > vI3Matrix(2, vector< vector<int> > (3, vector<int>(4,0)) );
  int count=0;
  for(int kk=0; kk<4; kk++)
  {
    for(int jj=0; jj<3; jj++)
    {
      for(int ii=0; ii<2; ii++)
      {
        vI3Matrix[ii][jj][kk]=count++;
        cout << "v[" <<kk <<"]["<<jj<<"]["<<ii<<"]= "<< vI3Matrix[ii][jj][kk] << endl;
      }
    }
  }
}//__________________________________________________________________
