#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */

class Matrix{
  private:
    int Nrows;
    int Ncols;
    int N;
    float *data;

  public:
    Matrix(int, int);

    void fill_N();
    void fill_R(int);
    void show();
    int sum(Matrix, Matrix);
    int mul(Matrix, Matrix);
    int save(char *);
};


