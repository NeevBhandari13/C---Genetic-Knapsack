#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 

struct Item {
    int value;
    int weight;
};

std::vector<Item> generateRandomItems(int nItems, int valueRange, int weightRange) {
    std::vector<Item> items;
    for (int i = 0; i < nItems; ++i) {
        Item item;
        item.value = rand() % valueRange + 1;
        item.weight = rand() % weightRange + 1;
        items.push_back(item);
    }
    return items;
}

// generate random solution
std::vector<bool> generateRandomSolution(int nItems) {
    std::vector<bool> solution(nItems);
    for (int i = 0; i < nItems; ++i) {
        solution[i] = rand() % 2;  // Randomly assign 0 or 1
    }
    return solution;
}

// generate initial pool of random solutions
std::vector<std::vector<bool> > randomSolutionsPool(int nItems) {
    // Number of solutions to initially generate
    const int NUM_SOLS = 8; 
    std::vector<std::vector<bool> > sols(NUM_SOLS);
    for (int i = 0; i < NUM_SOLS; ++i) {
        sols[i] = generateRandomSolution(nItems);  // Randomly assign 0 or 1
    }
    return sols;
}

// Fitness function to test suitability of all generated solutions
std::vector<int> fitnessFunc(std::vector<std::vector<bool> > sols, int nItems, std::vector<Item> items, int weightLimit) {
    std::vector<int> fitness(sols.size());
    // check each solution
    for (int i = 0; i < sols.size(); i++) { 
        int currentValue = 0;
        int currentWeight = 0;
        // check each item in solution
        for (int j = 0; j < nItems ; j++) {
            if (sols[i][j] == 1) {
                currentValue += items[j].value;
                currentWeight += items[j].weight;

            }
        }
        if (currentWeight < weightLimit) {
            fitness[i] = currentValue;
        } else {
            fitness[i] = 0;
        }
        
    }
    return fitness;
}

int main() {
    // seed for random
    srand(time(nullptr));

    int knapsackWeight, nItems, valueRange, weightRange;

    // User input for 
    std::cout << "Enter weight of knapsack: ";
    std::cin >> knapsackWeight;
    std::cout << "Enter number of items: ";
    std::cin >> nItems;
    std::cout << "Enter maximum value range: ";
    std::cin >> valueRange;
    std::cout << "Enter maximum weight range: ";
    std::cin >> weightRange;

    // Generate items
    std::vector<Item> items = generateRandomItems(nItems, valueRange, weightRange);

// Print items
std::cout << "Items:\n";
for (const auto& item : items) {
    std::cout << "Value: " << item.value << ", Weight: " << item.weight << std::endl;
}
std::cout << std::endl;

// Generate initial pool of solutions
std::vector<std::vector<bool> > sols = randomSolutionsPool(nItems);

// Print solutions
std::cout << "Solutions:\n";
for (const auto& solution : sols) {
    for (bool included : solution) {
        std::cout << included << " ";
    }
    std::cout << std::endl;
}
std::cout << std::endl;

// Check score of each solution
std::vector<int> fitness = fitnessFunc(sols, nItems, items, knapsackWeight);

// Print fitness
std::cout << "Fitness of each solution:\n";
for (int fit : fitness) {
    std::cout << fit << std::endl;
}
std::cout << std::endl;

    return 0;
}

