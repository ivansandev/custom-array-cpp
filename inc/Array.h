#ifndef EXERCISE_ARRAY_H
#define EXERCISE_ARRAY_H

#include <iostream>
#include "Person.h"
#include <fstream>

template<size_t N>
class Array : public std::exception{
private:
    Person *people[N];

    bool stringCompare(const char *addressNeeded, const char *personAddress);

public:
    // Constructor
    Array();
    //  Deconstructor
    ~Array();
    // Copy constructor
    Array(const Array&);

    // REQUIRED METHODS
    void insert(int index, const char* name, const char* egn, const char* address);
    void deleteAt(int index);
    void deleteCriteria(const char *criteria);
    bool empty() const;
    void print();
    void printSorted();
    void peoplePerAddress(const char* address);
    void saveBinary(const std::string& name);
    void loadBinary(const std::string &filename);

    // ARRAY-LIKE METHODS
    Person* data() { return people; }
    const Person* data() const { return people; }
    size_t size() const;

    // OPERATOR OVERLOADING
    Person& operator[](size_t index) { return *people[index]; }
    const Person& operator[](size_t index) const { return *people[index]; }
    Array& operator = (const Array &old_arr);
    friend std::ostream &operator<<(std::ostream &os, const Array &array) {
        for (auto& person : array.people) {
            if (!(person->isEmpty()))
                std::cout << *person << std::endl;
        }
        return os;
    }
};


#endif //EXERCISE_ARRAY_H
