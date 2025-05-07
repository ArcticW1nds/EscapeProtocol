#include <iostream>
#include <string>
#include "JRPG.hpp"
#include "Scientist.hpp"
#include "LabRat.hpp"

int main() {
    LabRat rat(10000, 10, 5);
    Scientist cornifer(120, 50, 4);
    Battle1v1(&rat, &cornifer);

    return 0;
}