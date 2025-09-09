// wellThatsJustPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Factorizer {
public:
    std::vector<int> primeFactors(int n) {
        std::vector<int> factors;
        if (n <= 1) return factors;  // empty vector for n <= 1

        // Check for factors of 2 first
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }

        // Check odd factors from 3 up to sqrt(n)
        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }

        // If n > 2, then n is prime itself
        if (n > 2) {
            factors.push_back(n);
        }

        return factors;
    }
};

// Helper function to print vector
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Test function
void runTests() {
    Factorizer factorizer;

    std::cout << "primeFactors(0): ";
    printVector(factorizer.primeFactors(0));  // []

    std::cout << "primeFactors(1): ";
    printVector(factorizer.primeFactors(1));  // []

    std::cout << "primeFactors(9): ";
    printVector(factorizer.primeFactors(9));  // [3, 3]

    std::cout << "primeFactors(10): ";
    printVector(factorizer.primeFactors(10)); // [2, 5]

    std::cout << "primeFactors(100): ";
    printVector(factorizer.primeFactors(100)); // [2, 2, 5, 5]

    std::cout << "primeFactors(17): ";
    printVector(factorizer.primeFactors(17)); // [17]
}

int main() {
    runTests();
    return 0;
}