#include "Matrix.h"


// Constructor
// Constructior of a Row major order matrix
Matrix::Matrix(int _Nrows, int _Ncols){
  this->Nrows = _Nrows;
  this->Ncols = _Ncols;
  this->data = new float[_Nrows*_Ncols];
  this->N = _Nrows*_Ncols;
}

// Function to Fill the matrix with ceros
void Matrix::fill_N(){
  int i, l = this->Ncols*this->Nrows;
  for (i=0; i<l; i++) this->data[0] = 0.0;
}

// Function to Fill the matrix with random numbers from 0 to max
void Matrix::fill_R(int max){
  int i, l = this->N;
  for (i=0; i<l; i++) this->data[i] = float(rand()%max);
}

// Print the matrix
void Matrix::show(){
  int r, c;
  int Nrows = this->Nrows;
  int Ncols = this->Ncols;

  for (r=0; r<Nrows; r++){
    for (c=0; c<Ncols; c++){
      std::cout << this->data[r*Ncols + c] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// Sum of two matrix
int Matrix::sum(Matrix A, Matrix B){
  int r, c, i;
  int Ar = A.Nrows;
  int Ac = A.Ncols;
  int Br = B.Nrows;
  int Bc = B.Ncols;
  float *Ad = A.data, *Bd = B.data;

  int l = this->N;

  if (Ar == Br && Ac == Bc){
    for (i=0; i<l; i++) this->data[i] = Ad[i] + Bd[i];
    return 1;
  }
  else {
    return 0;
  }
}

// Multiplication of two matrix
int Matrix::mul(Matrix A, Matrix B){
  int r, c, i; 
  int Ar = A.Nrows;
  int Ac = A.Ncols;
  int Br = B.Nrows;
  int Bc = B.Ncols;
  float *Ad = A.data, *Bd = B.data;

  if (Ar == Bc && Ac == Br){
    
    for (r=0; r<Br; r++){
      for (c=0; c<Bc; c++){
        for (i=0; i<Bc; i++){
          this->data[r*Ac + c] += Ad[r*Ac + i]*Bd[i*Bc + c];
        }
      }
    }
    return 1;
  }
  else {
    return 0;
  }
}

// Save the matrix with the name *name
int Matrix::save(char *name){

  int r, c, R, C;

  R = this->Nrows; C = this->Ncols;

  std::ofstream f;
  f.open(name);

  // Save the matrix using Matlab syntax

  f << '[';
  for (r=0; r<R; r++){
    for (c=0; c<C; c++){
      f << this->data[r*R + c] << ' ';
    }
    f << "; ";
  }
  f << "];" << std::endl;
/*
  for (i=0; i<l; i++){
    f << this->data[i] << ' ';
  }
*/
  f.close();

  return 0;
}



