#include "HashFunction.h"
#include "InputData.h"
#include "SentimentAnalysisModel.h"
#include <iostream>
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

    // Initialize the input data handler
    InputData inputData(reviews);

    // Processed data
    std::vector<std::string> processedData = inputData.getProcessedData();

    // Initialize the hash function with a bucket size
    size_t bucketSize = 100;  // For demonstration
    HashFunction hashFunc(bucketSize);

    // Hash the processed data
    std::vector<size_t> hashedFeatures;
    for (const auto& review : processedData) {
        hashedFeatures.push_back(hashFunc(review));
    }

    // Initialize the sentiment analysis model and train it with hashed features
    SentimentAnalysisModel model;
    model.train(hashedFeatures);

    return 0;
}
