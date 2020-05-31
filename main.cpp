#include <iostream>
#include "scoped_ptr.h"
#include "shared_ptr.h"
#include "tests_scoped_ptr.h"
#include "tests_shared_ptr.h"

int main() {
    test_scoped_ptr();
    test_shared_ptr();
    std::cout<<"its ok"<<std::endl;
    return 0;
}
