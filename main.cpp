#include <iostream>
#include "inc/Array.h"
#include "src/Array.cpp"
#include <array>

int main() {
    // CREATING ARRAY IN THE STACK
    Array<12> arr;

    // INSERTING ELEMENTS
    arr.insert(7, "Alberto Watson", "8291837162", "Wootton Ride");
    arr.insert(4, "Ivan Sandev", "3182739160", "");
    arr[4].setName("Boyan Kamenov");
    arr.insert(9, "Brad Pitt", "3718392073", "Ryat Drive");
    arr.insert(1, "Tommy Shelby", "3182930182", "Washington Link");
    arr.insert(3, "James Bond", "6554182734", "Ryat Drive");
    arr.insert(2, "Tony Stark", "1829537234", "Fisher Side");
    arr.insert(11, "Will Smith", "3938157239", "Ryat Drive");

    // CREATING A COPY OF THE ARRAY IN THE HEAP
//    Array<12> arr_copy_2 = arr;

    // PRINTING ARRAY WITH << OPERATOR
    std::cout << std::endl<< arr << std::endl;

    // DELETING ELEMENTS AT INDEX
    arr.deleteAt(9);
    // DELETING ELEMENTS BY SEARCH
    arr.deleteCriteria("Tommy Shelby");

    // PRINTING SORTED ARRAY
    arr.printSorted();
    std::cout << std::endl;

    // SHOWING NUMBER OF PEOPLE ON GIVEN ADDRESS
    arr.peoplePerAddress("Ryat Drive");
    std::cout << std::endl;

    // SAVING TO A BINARY
    arr.saveBinary("data.bin");

    // LOADING BINARY TO ANOTHER ARRAY
    Array<12> arr2;
    arr2.loadBinary("data.bin");
    // PRINTING DATA READ FROM BINARY FILE
    std::cout << arr2;

    return 0;
}