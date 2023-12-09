#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <locale>

// InputData class for pre-processing text data
class InputData {
private:
    std::vector<std::string> reviews;

    // Helper function to convert a string to lowercase
    std::string toLower(const std::string& str) const {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return lowerStr;
    }

    // Helper function to tokenize a string into words
    std::vector<std::string> tokenize(const std::string& str) const {
        std::istringstream iss(str);
        std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>{} };
        return tokens;
    }

public:
    InputData(const std::vector<std::string>& inputReviews) : reviews(inputReviews) {}

    // Function to clean and tokenize the text data
    std::vector<std::vector<std::string>> getProcessedData() const {
        std::vector<std::vector<std::string>> processedData;
        for (const auto& review : reviews) {
            std::string cleanedReview = toLower(review); // Convert to lowercase
            std::vector<std::string> tokens = tokenize(cleanedReview); // Tokenize the review
            processedData.push_back(tokens); // Add the tokens to the processed data
        }
        return processedData;
    }
};

#endif // INPUTDATA_H
