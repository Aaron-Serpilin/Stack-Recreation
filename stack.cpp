#include <iostream>
#include <limits>
#include <vector>
#include <string>

class Stack {

    public:
        Stack();
        bool isEmpty() const;
        int top() const;
        int pop();
        void push(int i);
        std::string toString() const;
        
    private:
        std::vector<int> elements;
};

Stack::Stack() {}

bool Stack::isEmpty() const {
    if (elements.size() == 0) {
        return true;
    }
    return false;
}

int Stack::top() const {
    return elements.at(elements.size() - 1);
}

int Stack::pop() {

    if (elements.size() == 0) {
        throw std::runtime_error("stack is empty");
    }

    int lastVal = elements.at(elements.size() - 1);
    elements.pop_back();
    return lastVal;
}

void Stack::push(int i) {
    elements.push_back(i);
}

std::string Stack::toString() const {

    std::string stringVals = "[";

    for (int i = elements.size() - 1; i >= 0; i--) {
        int currVal = elements.at(i);

        if (i != 0) {
            stringVals += std::to_string(currVal);
            stringVals += ",";
        } else {
            stringVals += std::to_string(currVal);
        }
        
    }

    stringVals += "]";
    return stringVals;
}


int main() {
    Stack stack;
    
    while (true) {
        try {
            std::cout << "stack> ";
            std::cout << std::endl;
            
            std::string command;
            std::cin >> command;
            
            if ( (command.compare("end") == 0) || std::cin.eof() ){

                break;

            } else if (command.compare("top") == 0) {

                std::cout << stack.top() << std::endl;

            } else if (command.compare("pop") == 0) {

                std::cout << stack.pop() << std::endl;

            } else if (command == "push") {

                if ( std::cin.eof() ) break;
                int i;
                std::cin >> i;
                bool failed = std::cin.fail();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (failed) {

                  throw std::runtime_error("not a number");

                }

                stack.push(i);

            } else if ( command.compare("list") == 0){

                std::cout << stack.toString() << std::endl;

            } else {

                throw std::runtime_error("invalid command");

            }
        } catch (std::runtime_error& e) {

            std::cout << "error: " << e.what() << std::endl;

        }
    }

    return 0;
}