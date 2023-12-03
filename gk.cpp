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
std::vector<std::vector<bool>> randomSolutionsPool(int nItems) {
    // Number of solutions to initially generate
    const int NUM_SOLS = 8; 
    std::vector<std::vector<bool>> sols(NUM_SOLS);
    for (int i = 0; i < nItems; ++i) {
        sols[i] = generateRandomSolution(nItems);  // Randomly assign 0 or 1
    }
    return sols;
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

    

    return 0;
}

