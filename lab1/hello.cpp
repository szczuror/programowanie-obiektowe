#include <iostream>
#include <string>
#include "hello.hpp"


namespace hello {
    static int HELLO_COUNT = 0;

  void print(std::string name){
    HELLO_COUNT++;
    std::cout << HELLO_COUNT << std::endl;
    std::cout << HELLO_COUNT << ". Hello " << name << std::endl;
    }
}
