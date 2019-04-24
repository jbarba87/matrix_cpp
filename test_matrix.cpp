#include <iostream>
#include <stdlib.h> 
#include <time.h>       /* time */

#include "Matrix.h"

using namespace std;

int main(){
  // initialize random seed:
    srand (time(NULL));

  // Creating 3 matrix
  Matrix A(100, 100);
  Matrix B(100, 100);
  Matrix C(100, 100);


  // Filling the matrices
  A.fill_R(100);
  B.fill_R(100);
  C.fill_N();

  C.mul(A, B);

  // Saving the matrices
  A.save("A.txt");
  B.save("B.txt");
  C.save("C.txt");

  // Showing Matrix
/*  A.show();
  B.show();
  C.show();
*/
  return 0;
}
