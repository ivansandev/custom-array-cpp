#ifndef EXERCISE_PERSON_H
#define EXERCISE_PERSON_H

#include <ostream>
#include <iostream>
#include <fstream>

class Person {
private:
    char* name;
    char* egn;
    char* address;
public:
    Person();
    Person(char *name, char *egn, char *address);
    ~Person();
    Person(const Person&);

    Person& operator=(const Person& person_old);
    bool operator<(const Person &rhs) const;

    bool isEmpty() const;
    bool isNameEmpty();
    void deleteValues();
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
    void fromBinary(std::ifstream &fp);
    void toBinary(std::ofstream& fp);

    char *getName() const;
    void setName(char *name);
    char *getEgn() const;
    void setEgn(char *egn);
    char *getAddress() const;
    void setAddress(char *address);
};


#endif //EXERCISE_PERSON_H
