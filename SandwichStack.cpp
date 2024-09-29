#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function declarations
void makeSandwich(stack<string>& sandwich);
bool checkSandwich(stack<string>& sandwich);

int main() {
    stack<string> mySandwich;
    makeSandwich(mySandwich);

    if (checkSandwich(mySandwich)) {
        cout << "Delicious! This is a perfect sandwich!" << endl;
    }
    else {
        cout << "Oops, this is not quite right!" << endl;
    }

    return 0;
}

// Function to build a sandwich using a stack
void makeSandwich(stack<string>& sandwich) {
    string ingredient;
    cout << "Enter ingredients one by one to build your sandwich (type 'done' to finish): \n";
    while (true) {
        cout << "Add ingredient: ";
        getline(cin, ingredient);
        if (ingredient == "done") break;
        sandwich.push(ingredient);
    }
}

// Function to check if the sandwich matches the perfect sandwich
bool checkSandwich(stack<string>& sandwich) {
    stack<string> perfectSandwich;
    perfectSandwich.push("Bread");
    perfectSandwich.push("Bacon");
    perfectSandwich.push("Lettuce");
    perfectSandwich.push("Tomato");
    perfectSandwich.push("Bread");

    // Compare each element of both stacks
    while (!sandwich.empty() && !perfectSandwich.empty()) {
        if (sandwich.top() != perfectSandwich.top()) return false;
        sandwich.pop();
        perfectSandwich.pop();
    }

    // Check both stacks separately
    if (sandwich.empty() && perfectSandwich.empty()) {
        return true;  // Both stacks are empty, so they match
    }
    else {
        return false; // One stack still has elements, so they don't match
    }
}
