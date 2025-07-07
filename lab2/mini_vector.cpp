#include "mini_vector.hpp"
#include <cstring> 
#include <algorithm>

namespace mini_vector {

// Etap 1
void vector_init(MiniVector& vec, int capacity) {
    vec.size = 0;
    vec.capacity = capacity;
    vec.elements = new char[capacity];
}

void vector_init_fill(MiniVector& vec, int capacity, char init_character) {
    vec.size = capacity;
    vec.capacity = capacity;
    vec.elements = new char[capacity];
    std::fill(vec.elements, vec.elements + capacity, init_character);
}

void vector_print(const MiniVector& vec) {
    if (vec.size == 0) {
        std::cout << "Vector elements: no elements in vector." << std::endl;
        return;
    }

    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size; ++i) {
        std::cout << vec.elements[i];
        if (i != vec.size - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

void vector_destroy(MiniVector& vec) {
    delete[] vec.elements;
    vec.elements = nullptr;
    vec.capacity = 0;
    vec.size = 0;
}

// Etap 2
void vector_expand(MiniVector& vec, int new_capacity) {
    if (new_capacity <= vec.capacity) {
        std::cout << "Cannot expand vector: new capacity is lower than current." << std::endl;
        return;
    }

    char* new_elements = new char[new_capacity];
    std::memcpy(new_elements, vec.elements, vec.size * sizeof(char));
    delete[] vec.elements;
    vec.elements = new_elements;
    vec.capacity = new_capacity;
}

void vector_shrink(MiniVector& vec, int new_capacity) {
    if (new_capacity >= vec.capacity) {
        std::cout << "Cannot shrink vector: new capacity is greater than current." << std::endl;
        return;
    }

    if (vec.size > new_capacity) {
        std::cout << "Cannot shrink vector: there are elements that would be lost in the process." << std::endl;
        return;
    }

    char* new_elements = new char[new_capacity];
    std::memcpy(new_elements, vec.elements, vec.size * sizeof(char));
    delete[] vec.elements;
    vec.elements = new_elements;
    vec.capacity = new_capacity;
}

// Etap 3
void vector_add(MiniVector& vec, char element) {
    if (vec.size == vec.capacity) {
        vector_expand(vec, vec.capacity * 2);
    }
    vec.elements[vec.size++] = element;
    std::cout << "Added " << element << std::endl;
}

void vector_clear(MiniVector& vec) {
    delete[] vec.elements;
    vec.capacity = INIT_CAPACITY;
    vec.size = 0;
    vec.elements = new char[vec.capacity];
}

// Etap 4
void vector_remove(MiniVector& vec, int idx) {
    if (idx < 0 || idx >= vec.size) {
        std::cout << "The requested element index is exceeding vector size. (Vector size: "
                  << vec.size << ". Requested idx for element removal: " << idx << ")" << std::endl;
        return;
    }

    for (int i = idx; i < vec.size - 1; ++i) {
        vec.elements[i] = vec.elements[i + 1];
    }
    vec.size--;

    if (vec.size * 2 < vec.capacity) {
        vector_shrink(vec, vec.capacity / 2);
    }
}

void vector_remove_occurrences(MiniVector& vec, char value) {
    int new_size = 0;
    for (int i = 0; i < vec.size; ++i) {
        if (vec.elements[i] != value) {
            vec.elements[new_size++] = vec.elements[i];
        }
    }
    vec.size = new_size;

    if (vec.size * 2 < vec.capacity) {
        vector_shrink(vec, std::max(INIT_CAPACITY, vec.capacity / 2));
    }
}

} 

