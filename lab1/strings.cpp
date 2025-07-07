#include <iostream>
#include <string>
#include "strings.hpp"

namespace strings {
    int COMBINE_COUNT = 0;
    std::string combine_strings(std::string s1, std::string s2){
      COMBINE_COUNT++;
      std::string s3 = s1 + " " + s2;
      return s3;
      }
}
