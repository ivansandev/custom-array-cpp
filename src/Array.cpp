#include "../inc/Array.h"

template<size_t N>
Array<N>::Array() {
    for (int i = 0; i <= size(); i++) {
        people[i] = new Person;
    }
}

template<size_t N>
Array<N>::~Array() {
    for (int i = 0; i < size(); i++) {
        delete (people)[i];
    }
}

template<size_t N>
Array<N>::Array(const Array &old_arr) {
    for (int i = 0; i < size(); i++) {
        people[i] = old_arr.people[i];
    }
}

template<size_t N>
Array<N> &Array<N>::operator=(const Array &old_arr) {
    for (int i = 0; i < size(); i++) {
        people[i] = old_arr.people[i];
    }
    return *this;
}

template<size_t N>
void Array<N>::insert(int index, const char *name, const char *egn, const char *address) {
    delete people[index];
    people[index] = new Person(const_cast<char *> (name), const_cast<char *>(egn), const_cast<char *>(address));
}

template<size_t N>
size_t Array<N>::size() const {
    return N;
}

template<size_t N>
bool Array<N>::empty() const {
    for (int i = 0; i < size(); i++) {
        if (!(people[i].isEmpty()))
            return false;
    }
    return true;
}

template<size_t N>
void Array<N>::deleteAt(int index) {
    if (people[index]->isEmpty()) {
        std::cout << "Values at index " << index << " are already empty." << std::endl;
    } else {
        people[index]->deleteValues();
    }
}

template<size_t N>
void Array<N>::deleteCriteria(const char *criteria) {
    for (int i = 0; i < size(); i++) {
        if (!(people[i]->isNameEmpty())) {
            if (strcmp(people[i]->getName(), criteria) == 0) {
                people[i]->deleteValues();
                return;
            }
        }
    }
}

template<size_t N>
void Array<N>::print() {
    for (auto person: people) {
        if (!(person->isEmpty()))
            std::cout << *person << std::endl;
    }
}

template<size_t N>
void Array<N>::printSorted() {
    Person *sorted_people[N];
    // Creating a copy so that we don't change the order of the initial array
    for (int i = 0; i < size(); ++i) {
        sorted_people[i] = people[i];
    }
    // Bubble sorting based on member 'name'
    // Operation for '<' is defined in class Person
    for (int i = 0; i < size() - 1; i++) {
        for (int j = 0; j < size() - i - 1; j++) {
            if (*sorted_people[j] < *sorted_people[j + 1]) {
                std::swap(sorted_people[j], sorted_people[j + 1]);
            }
        }
    }
    for (auto person: sorted_people) {
        if (!(person->isEmpty()))
            std::cout << *person << std::endl;
    }
}

template<size_t N>
bool Array<N>::stringCompare(const char *addressNeeded, const char *personAddress) {
    std::string s_addressNeeded(addressNeeded);
    std::string s_personAddress(personAddress);
    // Transforming all characters to lower characters, because the matching should not be dependant on char case
    transform(s_addressNeeded.begin(), s_addressNeeded.end(), s_addressNeeded.begin(), ::tolower);
    transform(s_personAddress.begin(), s_personAddress.end(), s_personAddress.begin(), ::tolower);
    if (s_addressNeeded == s_personAddress)
        return true;
    return false;
}

template<size_t N>
void Array<N>::peoplePerAddress(const char *address) {
    int counter = 0;
    for (auto person: people)
        if (person->getAddress() != nullptr)
            if (stringCompare(address, person->getAddress()))
                ++counter;
    std::cout << counter << " people live on address \"" << address << "\"" << std::endl;
}

template<size_t N>
void Array<N>::saveBinary(const std::string &filename) {
    std::ofstream fp;
    fp.open(filename, std::ios::out | std::ios::binary);
    if (fp.good()) {
        // Saving array size
        int int_size = size();
        fp.write((char *) &int_size, sizeof(int_size));
        // Saving array data
        for (auto &person : people) {
            person->toBinary(fp);
        }
        fp.close();
    } else {
        std::cout << "Cannot open bin file for writing." << std::endl;
    }
}

template<size_t N>
void Array<N>::loadBinary(const std::string &filename) {
    std::ifstream fp;
    fp.open(filename, std::ios::in | std::ios::binary);
    if (fp.good()) {
        // Load array size
        int int_size = 0;
        fp.read((char *) &int_size, sizeof(int_size));
        if (int_size > N) {
            std::cout << "ERROR: Data that's trying to be read has a bigger array than the one you've specified"
                      << std::endl;
            std::cout << "DEBUGGING: Your array size: " << size() << "; " << filename << " array size: " << int_size
                      << std::endl;
            std::cout << "Exiting..." << std::endl;
        } else {
            // Load array data
            for (int i = 0; i < size(); i++) {
                people[i]->fromBinary(fp);
            }
        }
        fp.close();
    } else {
        std::cout << "Cannot open bin file for writing." << std::endl;
    }
}

