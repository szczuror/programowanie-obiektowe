#ifndef MINI_VECTOR_HPP
#define MINI_VECTOR_HPP

#include <iostream>

namespace mini_vector {

const int INIT_CAPACITY = 4;

struct MiniVector {
    char* elements;
    int capacity;
    int size;
};

// Etap 1
void vector_init(MiniVector& vec, int capacity);
void vector_init_fill(MiniVector& vec, int capacity, char init_character);
void vector_print(const MiniVector& vec);
void vector_destroy(MiniVector& vec);

// Etap 2
void vector_expand(MiniVector& vec, int new_capacity);
void vector_shrink(MiniVector& vec, int new_capacity);

// Etap 3
void vector_add(MiniVector& vec, char element);
void vector_clear(MiniVector& vec);

// Etap 4
void vector_remove(MiniVector& vec, int idx);
void vector_remove_occurrences(MiniVector& vec, char value);

} 

#endif

