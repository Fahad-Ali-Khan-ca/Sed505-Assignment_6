#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// Usually we make separate header and cpp files for each class but here I thought to keep the code simple.

// Define a simple hash function class
class HashFunction {
public:
    // This hash function is a simple wrapper around the std::hash
    size_t operator()(const std::string& key) const {
        return std::hash<std::string>{}(key) % 10;  // Modulus to keep the hash value within bounds
    }
};

// Input data class
class InputData {
private:
    std::vector<std::string> data;

public:
    InputData(const std::vector<std::string>& inputData) : data(inputData) {}

    // Method to get the data - in a real scenario, this could be reading from a file or database
    std::vector<std::string> getData() const {
        return data;
    }
};

// Model class that uses hashed features
class Model {
private:
    std::unordered_map<size_t, double> weights;  // Simulates model weights for each hashed feature

public:
    // Dummy model initialization with random weights
    Model() {
        for (int i = 0; i < 10; ++i) {  // Assuming a hash table size of 10 for simplicity
            weights[i] = static_cast<double>(rand()) / RAND_MAX;  // Random weight initialization
        }
    }

    // A mock method to 'train' the model which just prints out the hash and corresponding weight
    void train(const std::vector<size_t>& hashedData) {
        for (size_t hash : hashedData) {
            std::cout << "Feature hash: " << hash << " Weight: " << weights[hash] << std::endl;
        }
    }
};

int main() {
    // Example input data
    std::vector<std::string> categories = { "apple", "banana", "cherry", "date", "elderberry" };
    InputData inputData(categories);

    // Get the data and hash it
    std::vector<size_t> hashedData;
    HashFunction hashFunc;
    for (const auto& category : inputData.getData()) {
        hashedData.push_back(hashFunc(category));
    }

    // Initialize the model and 'train' it with the hashed data
    Model model;
    model.train(hashedData);

    return 0;
}
