#include "HashFunction.h"
#include "InputData.h"
#include "SentimentAnalysisModel.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


/*
Complex Code Problem: Feature Hashing for Text Classification
Problem Statement:
In a text classification task, we're often confronted with a vast vocabulary that can lead to a huge number of features
when using one-hot encoding or similar methods. This not only increases the computational burden but also affects the model's
performance due to the curse of dimensionality. For instance, processing user reviews to classify sentiments involves a vast
vocabulary with potentially millions of unique words.

How the Hash Feature Pattern Solves the Problem:
The Hash Feature pattern addresses this issue by transforming the high-dimensional
word features into a lower-dimensional space using a hash function.
This process, known as feature hashing or the hashing trick,
significantly reduces the feature space, which in turn decreases memory usage and speeds up the training process.

*/

int main() {
    // Example input data with potential user reviews
    std::vector<std::string> reviews = {
        "I love this product", "Hated the experience", "Best purchase ever", "Not worth the price"
    };

    // Initialize the input data handler and process the reviews
    InputData inputData(reviews);
    std::vector<std::vector<std::string>> processedData = inputData.getProcessedData();

    // Initialize the hash function with a chosen bucket size
    size_t bucketSize = 1000;  // Larger bucket size for a more realistic scenario
    HashFunction hashFunc(bucketSize);

    // Hash the processed data
    std::unordered_set<size_t> uniqueHashes; // Use a set to avoid duplicate hash values
    for (const auto& tokenVector : processedData) {
        for (const auto& token : tokenVector) {
            size_t hashValue = hashFunc(token);
            uniqueHashes.insert(hashValue); // Insert the hash value into the set
        }
    }

    // Convert the set of unique hash values into a vector for the model
    std::vector<size_t> hashedFeatures(uniqueHashes.begin(), uniqueHashes.end());

    // Initialize the sentiment analysis model and train it with hashed features
    SentimentAnalysisModel model;
    model.train(hashedFeatures);

    return 0;
}
