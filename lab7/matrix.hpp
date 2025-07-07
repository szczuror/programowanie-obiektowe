#pragma once

#include <array>
#include <cstddef>
#include <initializer_list>
#include <iostream>

template <typename T, std::size_t Rows = 4, std::size_t Cols = 4> class Matrix {
protected:
  std::array<std::array<T, Cols>, Rows> elements;

public:
  Matrix();
  Matrix(std::initializer_list<std::initializer_list<T>> list);

  std::array<T, Cols> &operator[](std::size_t row);
  const std::array<T, Cols> &operator[](std::size_t row) const;

  Matrix<T, Rows, Cols> operator+(const Matrix<T, Rows, Cols> &other) const;
  Matrix<T, Rows, Cols> operator-(const Matrix<T, Rows, Cols> &other) const;

  Matrix<T, Cols, Rows> transpose() const;

  template <typename U, std::size_t R, std::size_t C>
  friend std::ostream &operator<<(std::ostream &os,
                                  const Matrix<U, R, C> &matrix);
};

template <typename T, std::size_t Rows, std::size_t Cols>
Matrix<T, Rows, Cols>::Matrix() {
  for (auto &row : elements)
    row.fill(T{});
}

template <typename T, std::size_t Rows, std::size_t Cols>
Matrix<T, Rows, Cols>::Matrix(
    std::initializer_list<std::initializer_list<T>> list) {
  std::size_t i = 0;
  for (const auto &rowList : list) {
    if (i >= Rows)
      break;
    std::size_t j = 0;
    for (const auto &val : rowList) {
      if (j >= Cols)
        break;
      elements[i][j] = val;
      ++j;
    }
    for (; j < Cols; ++j)
      elements[i][j] = T{};
    ++i;
  }
  for (; i < Rows; ++i)
    elements[i].fill(T{});
}

template <typename T, std::size_t Rows, std::size_t Cols>
std::array<T, Cols> &Matrix<T, Rows, Cols>::operator[](std::size_t row) {
  return elements[row];
}

template <typename T, std::size_t Rows, std::size_t Cols>
const std::array<T, Cols> &
Matrix<T, Rows, Cols>::operator[](std::size_t row) const {
  return elements[row];
}

template <typename T, std::size_t Rows, std::size_t Cols>
Matrix<T, Rows, Cols>
Matrix<T, Rows, Cols>::operator+(const Matrix<T, Rows, Cols> &other) const {
  Matrix<T, Rows, Cols> result;
  for (std::size_t i = 0; i < Rows; ++i)
    for (std::size_t j = 0; j < Cols; ++j)
      result[i][j] = elements[i][j] + other[i][j];
  return result;
}

template <typename T, std::size_t Rows, std::size_t Cols>
Matrix<T, Rows, Cols>
Matrix<T, Rows, Cols>::operator-(const Matrix<T, Rows, Cols> &other) const {
  Matrix<T, Rows, Cols> result;
  for (std::size_t i = 0; i < Rows; ++i)
    for (std::size_t j = 0; j < Cols; ++j)
      result[i][j] = elements[i][j] - other[i][j];
  return result;
}

template <typename T, std::size_t Rows, std::size_t Cols>
Matrix<T, Cols, Rows> Matrix<T, Rows, Cols>::transpose() const {
  Matrix<T, Cols, Rows> result;
  for (std::size_t i = 0; i < Rows; ++i)
    for (std::size_t j = 0; j < Cols; ++j)
      result[j][i] = elements[i][j];
  return result;
}

template <typename U, std::size_t R, std::size_t C>
std::ostream &operator<<(std::ostream &os, const Matrix<U, R, C> &matrix) {
  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      os << matrix[i][j];
      if (j < C - 1)
        os << " ";
    }
    os << "\n";
  }
  os << "\n";
  return os;
}
