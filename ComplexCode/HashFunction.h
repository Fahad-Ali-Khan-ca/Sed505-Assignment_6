#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>

class HashFunction {
private:
    size_t bucketSize;

public:
    HashFunction(size_t size) : bucketSize(size) {}

    size_t operator()(const std::string& key) const {
        // Simple hash function (modulus operator)
        return std::hash<std::string>{}(key) % bucketSize;
    }
};

#endif // HASHFUNCTION_H
