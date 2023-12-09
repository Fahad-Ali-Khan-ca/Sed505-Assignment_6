#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <vector>
#include <string>

// InputData class to simulate the extraction and pre-processing of text data
class InputData {
private:
    std::vector<std::string> reviews;

public:
    InputData(const std::vector<std::string>& inputReviews) : reviews(inputReviews) {}

    // Function to tokenize and clean the text data
    std::vector<std::string> getProcessedData() const {
        // For simplicity, we are returning the original reviews
        // Tokenization and cleaning would happen here
        return reviews;
    }
};

#endif // INPUTDATA_H
