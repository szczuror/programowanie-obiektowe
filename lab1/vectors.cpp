#include <iostream>
#include <vector>
#include "vectors.hpp"
#include <algorithm>

namespace vectors {
    std::vector<int> reverse(std::vector<int>* old) {
      if(old->size() == 0) {
        return std::vector<int>(); //meow?
      }
   std::vector<int> new_vector = {};
   for(int i = old->size() -1 ; i >= 0; i--) {
     new_vector.push_back((*old)[i]);
   }
    return new_vector;
    }

  int max(std::vector<int>* vec){
    return *std::max_element(vec->begin(), vec->end());
  }
}
