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
//    Person();
    Person();

    Person(char *name, char *egn, char *address);

    ~Person();

    Person(const Person&);

    Person& operator=(const Person& person_old);

    void toBinary(std::ofstream& fp);

    bool isEmpty() const;

    void deleteValues();

    char *getName() const;

    void setName(char *name);

    char *getEgn() const;

    void setEgn(char *egn);

    char *getAddress() const;

    void setAddress(char *address);

    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    bool operator<(const Person &rhs) const;

    bool isNameEmpty();

    void fromBinary(std::ifstream &fp);
};


#endif //EXERCISE_PERSON_H
