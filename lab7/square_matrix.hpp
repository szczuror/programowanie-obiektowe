#pragma once

#include "matrix.hpp"

template <typename T, std::size_t N = 4>
class SquareMatrix : public Matrix<T, N, N> {
private:
  T det;

  T computeDeterminant();

public:
  SquareMatrix(std::initializer_list<std::initializer_list<T>> list);

  T getDet() const;

  static SquareMatrix<T, N> identity();
};

template <typename T, std::size_t N>
SquareMatrix<T, N>::SquareMatrix(
    std::initializer_list<std::initializer_list<T>> list)
    : Matrix<T, N, N>(list) {
  det = computeDeterminant();
}

template <typename T, std::size_t N> T SquareMatrix<T, N>::getDet() const {
  return det;
}

template <typename T, std::size_t N>
T SquareMatrix<T, N>::computeDeterminant() {
  T A[N][N];
  std::copy(&this->elements[0][0], &this->elements[0][0] + N * N, &A[0][0]);

  int swaps = 0;
  for (std::size_t i = 0; i < N; ++i) {
    std::size_t maxRow = i;
    for (std::size_t k = i + 1; k < N; ++k) {
      if (std::abs(A[k][i]) > std::abs(A[maxRow][i]))
        maxRow = k;
    }
    if (std::abs(A[maxRow][i]) < 1e-12)
      return T{};

    if (i != maxRow) {
      std::swap_ranges(A[i], A[i] + N, A[maxRow]);
      swaps++;
    }

    for (std::size_t k = i + 1; k < N; ++k) {
      T factor = A[k][i] / A[i][i];
      for (std::size_t j = i; j < N; ++j)
        A[k][j] -= factor * A[i][j];
    }
  }

  T determinant = (swaps % 2 == 0) ? T{1} : T{-1};
  for (std::size_t i = 0; i < N; ++i)
    determinant *= A[i][i];

  return determinant;
}

template <typename T, size_t N>
SquareMatrix<T, N> SquareMatrix<T, N>::identity() {
  SquareMatrix<T, N> result{};
  for (std::size_t i = 0; i < N; ++i)
    result[i][i] = T{1};
  result.det = T{1};
  return result;
}

template <typename T>
class SquareMatrix<T, 2> : public Matrix<T, 2, 2> {
private:
    T det;

    T computeDeterminant() {
        std::cout << "Calculating determinant in 2x2 square matrix class specialization" << std::endl;
        return this->elements[0][0] * this->elements[1][1] - this->elements[0][1] * this->elements[1][0];
    }

public:
    SquareMatrix(std::initializer_list<std::initializer_list<T>> list)
        : Matrix<T, 2, 2>(list) {
        det = computeDeterminant();
    }

    T getDet() const {
        return det;
    }

    static SquareMatrix<T, 2> identity() {
        SquareMatrix<T, 2> result{{{T{1}, T{0}}, {T{0}, T{1}}}};
        result.det = T{1};
        return result;
    }
};
