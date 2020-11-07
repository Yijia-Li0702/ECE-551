#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>


//YOUR CODE GOES HERE!
template<typename T>
class Matrix {
 private:
  int numRows;
  int numColumns;
  std::vector<std::vector<T> > rows;

 public:
  Matrix();
  Matrix(int r, int c);
  Matrix(const Matrix<T> & rhs);
  Matrix<T> & operator=(const Matrix<T> & rhs);
  int getRows() const;
  int getColumns() const;
  const std::vector<T> & operator[](int index) const;
  std::vector<T> & operator[](int index);
  bool operator==(const Matrix<T> & rhs) const;
  Matrix operator+(const Matrix<T> & rhs) const;
};

template<typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs);

template<typename T>
Matrix<T>::Matrix() : numRows(0), numColumns(0), rows(0) {
}

template<typename T>
Matrix<T>::Matrix(int r, int c) :
    numRows(r),
    numColumns(c),
    rows(std::vector<std::vector<T> >(r)) {
  for (int i = 0; i < r; i++) {
    rows[i] = std::vector<T>(c);
  }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> & rhs) :
    numRows(rhs.numRows),
    numColumns(rhs.numColumns),
    rows(rhs.rows) {
}

template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & rhs) {
  numRows = rhs.numRows;
  numColumns = rhs.numColumns;
  rows = rhs.rows;
  return *this;
}

template<typename T>
int Matrix<T>::getRows() const {
  return numRows;
}

template<typename T>
int Matrix<T>::getColumns() const {
  return numColumns;
}

template<typename T>
const std::vector<T> & Matrix<T>::operator[](int index) const {
  assert(index < numRows && index >= 0);
  return rows[index];
}

template<typename T>
std::vector<T> & Matrix<T>::operator[](int index) {
  assert(index < numRows && index >= 0);
  return rows[index];
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T> & rhs) const {
  return numRows == rhs.numRows && numColumns == rhs.numColumns && rows == rhs.rows;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & rhs) const {
  assert(numRows == rhs.numRows && numColumns == rhs.numColumns);
  Matrix<T> ans(rhs.numRows, rhs.numColumns);
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      ans[i][j] = (*this)[i][j] + rhs[i][j];
    }
  }
  return ans;
}

template<typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs) {
  int nR = rhs.getRows();
  int nC = rhs.getColumns();
  s << "[ ";
  for (int i = 0; i < nR; i++) {
    s << "{";
    for (int j = 0; j < nC; j++) {
      s << rhs[i][j];
      if (j != nC - 1) {
        s << ", ";
      }
    }
    s << "}";
    if (i != nR - 1) {
      s << "," << std::endl;
    }
  }
  s << " ]";
  return s;
}
#endif
