#include "../inc/Person.h"

// CONSTRUCTOR
Person::Person() {
    name = strdup("N/A");
    address = strdup("N/A");
    egn = strdup("N/A");
}

// CONSTRUCTOR
Person::Person(char *name, char *egn, char *address) {
    this->name = new char[sizeof(name)];
    strcpy(this->name, name);

    this->egn = new char[sizeof(egn)];
    strcpy(this->egn, egn);

    this->address = new char[sizeof(address)];
    strcpy(this->address, address);
}

// DECONSTRUCTOR
/*
Person::~Person() {
//    Memory for char* is already being freed at Array class
    delete name;
    delete address;
    delete egn;
}
*/

// COPY CONSTRUCTOR
Person::Person(const Person &person_old) {
    name = new char(strlen(person_old.name));
    strcpy(name, person_old.name);
    egn = new char(strlen(person_old.egn));
    strcpy(egn, person_old.egn);
    address = new char(strlen(person_old.address));
    strcpy(address, person_old.address);
}

// COPY ASSIGNMENT OPERATOR
Person &Person::operator=(const Person &person_old) {
    name = new char(strlen(person_old.name));
    strcpy(name, person_old.name);
    egn = new char(strlen(person_old.egn));
    strcpy(egn, person_old.egn);
    address = new char(strlen(person_old.address));
    strcpy(address, person_old.address);

    return *this;
}

// OVERLOADING OPERATOR <<
std::ostream &operator<<(std::ostream &os, const Person &person) {
    if (person.isEmpty()) {
        os << "No info.";
        return os;
    }
    if (person.name != nullptr) {
        os << person.name << ", ";
    } else {
        os << "N/A" << ", ";
    }
    if (person.egn != nullptr) {
        os << person.egn << ", ";
    } else {
        os << "N/A" << ", ";
    }
    if (person.address != nullptr) {
        os << person.address;
    } else {
        os << "N/A";
    }
    return os;
}

bool Person::isEmpty() const {
    if (name == nullptr && egn == nullptr && address == nullptr)
        return true;
    if (strcmp(name, "N/A") == 0 && strcmp(egn, "N/A") == 0 && strcmp(address, "N/A") == 0)
        return true;
    return false;
}

void Person::deleteValues() {
    name = strdup("N/A");
    egn = strdup("N/A");
    address = strdup("N/A");
}

bool Person::isNameEmpty() {
    if (name == nullptr)
        return true;
    if (strcmp(name, "N/A") == 0)
        return true;
    if (name[0] == '\0')
        return true;
    return false;
}

// OVERLOAD OPERATOR < FOR COMPARING NAMES
bool Person::operator<(const Person &rhs) const {
    if (rhs.name == nullptr || strcmp(rhs.name, "N/A") == 0) {
        return false;
    }
    if (name == nullptr || strcmp(name, "N/A") == 0) {
        return true;
    }
    if (tolower(name[0]) > tolower(rhs.name[0])) {
        return true;
    }
    return false;
}

void Person::toBinary(std::ofstream &fp) {
    if (!(isEmpty())) {
        size_t str_len;
        // Null (in else statements) is used for safe checking in situations where the user deleted
        // some memory from a Person object
        const char *NA = "N/A";
        size_t str_len_NA = strlen(NA);

        if ((name != nullptr) || (name[0] != '\0') || strlen(name) > 0) {
            str_len = strlen(name);
            fp.write((char *) &str_len, sizeof(str_len));
            fp.write(name, str_len);
        } else {
            fp.write((char *) &str_len_NA, sizeof(str_len_NA));
            fp.write(NA, str_len_NA);
        }

        if ((egn != nullptr) || (egn[0] != '\0') || strlen(egn) > 0) {
            str_len = strlen(egn);
            fp.write((char *) &str_len, sizeof(str_len));
            fp.write(egn, str_len);
        } else {
            fp.write((char *) &str_len_NA, sizeof(str_len_NA));
            fp.write(NA, str_len_NA);
        }

        if ((address != nullptr) || (address[0] != '\0') || strlen(address) > 0) {
            str_len = strlen(address);
            fp.write((char *) &str_len, sizeof(str_len));
            fp.write(address, str_len);
        } else {
            fp.write((char *) &str_len_NA, sizeof(str_len_NA));
            fp.write(NA, str_len_NA);
        }
    }
}

void Person::fromBinary(std::ifstream &fp) {
    size_t str_len = 0;

    fp.read((char *) &str_len, sizeof(str_len));
    name = new char(str_len);
    fp.read(name, str_len);
    name[str_len] = '\0';
    str_len = 0;

    if (strlen(name) == 0) {
        name = strdup("N/A");
        egn = strdup("N/A");
        address = strdup("N/A");
        return;
    }

    fp.read((char *) &str_len, sizeof(str_len));
    egn = new char(str_len);
    fp.read(egn, str_len);
    egn[str_len] = '\0';
    str_len = 0;

    fp.read((char *) &str_len, sizeof(str_len));
    address = new char(str_len);
    fp.read(address, str_len);
    address[str_len] = '\0';
}


// GETTERS / SETTERS

char *Person::getName() const {
    return name;
}

void Person::setName(char *name) {
    Person::name = name;
}

char *Person::getEgn() const {
    return egn;
}

void Person::setEgn(char *egn) {
    Person::egn = egn;
}

char *Person::getAddress() const {
    return address;
}

void Person::setAddress(char *address) {
    Person::address = address;
}


