#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function declarations
void makePancakeStack(stack<string>& pancakeStack);
bool checkPancakeStack(stack<string>& pancakeStack);

int main() {
    stack<string> myPancakeStack;
    makePancakeStack(myPancakeStack);

    if (checkPancakeStack(myPancakeStack)) {
        cout << "Yum! This is a perfect pancake stack!" << endl;
    }
    else {
        cout << "Uh-oh, these pancakes are all wrong!" << endl;
    }

    return 0;
}

// Function to build a pancake stack using a stack
void makePancakeStack(stack<string>& pancakeStack) {
    string topping;
    cout << "Enter meal items one by one to build your stack (type 'done' to finish): \n";
    while (true) {
        cout << "Add item: ";
        getline(cin, topping);
        if (topping == "done") break;
        pancakeStack.push(topping);
    }
}

// Function to check if the pancake stack matches the perfect stack
bool checkPancakeStack(stack<string>& pancakeStack) {
    stack<string> perfectStack;
    perfectStack.push("Plate");
    perfectStack.push("Pancake");
    perfectStack.push("Pancake");
    perfectStack.push("Whipped Cream");
    perfectStack.push("Blueberry");
    perfectStack.push("Syrup");

    // Compare each element of both stacks
    while (!pancakeStack.empty() && !perfectStack.empty()) {
        if (pancakeStack.top() != perfectStack.top()) return false;
        pancakeStack.pop();
        perfectStack.pop();
    }

    // Check both stacks separately for better clarity
    if (pancakeStack.empty() && perfectStack.empty()) {
        return true;  // Both stacks are empty, so they match
    }
    else {
        return false; // One stack still has elements, so they don't match
    }
}
