#include <iostream>
#include <fstream>
#include <string>
#include "StackType.hpp"

using std::string;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::exception;
using std::cout;
using std::cin;


int main() {
    char input = NULL, inputMethod; // input is for input from either the text file or manual input | inputMethod is for getting user's input preferance
    string fileName; // Takes user's file path
    StackType stack; // Create stack instance
    ItemType item; // Create item instance to be used for stack

    
    try {
        ofstream outFile; // Get an output file to write data out to
        outFile.open("Output.txt"); // Get file ready to write data to
        
        cout << "Do you want to use a File (F) or Manual (M) input (F/M): ";
        cin >> inputMethod; // Take in whether user wants to use an input file or manual input
        
        // Check if they entered F or f for file input
        if(inputMethod == 'F' || inputMethod == 'f'){
            cout << "\nPlease enter the file path name: ";
            cin >> fileName; // Get filename from user
        
            ifstream inFile; // Get an input file of data to process
            inFile.open(fileName); // Get file ready to read input
            
            cout << "\nOriginal: ";
            outFile << "\nOriginal: ";
            while(inFile >> input){ // While file continues to scan in items from file: print input, set item = input so it can be added to stack
                item = input; // Set item to input to be pushed onto stack
                stack.Push(item); // Push item onto stack
                cout << input; // Cout input to console
                outFile << input; // Write to file
            }
           inFile.close(); // Close input file
        // If manual input
        }else{
            cout << "\nPlease enter a string that you want to be reversed (Press '0' to quit): ";
            while(input != '0'){ // While input doesn't equal 0 (which terminates input sequence)
                cin >> input; // Take in input from user
                item = input; // Set item to input to be pushed onto stack
                stack.Push(item); // Push item onto stack
            }
        }
        
        cout << "\nStack: ";
        outFile << "\nStack: ";
        while(!stack.IsEmpty()){ // While stack is not empty, print contents
            if(stack.Top() == '0'){ // If top of stack is a 0, pop it off so the '0' isn't printed to the output file
                stack.Pop();
            }
            cout << stack.Top(); // Console log next item
            outFile << stack.Top(); // Write to outFile next item
            stack.Pop(); // Pop current item to get next item in stack
        }
        cout << endl;
        
        outFile.close(); // Close output file
        
    } catch (exception& ex) {
        cerr << "\nSomething went wrong...\n"; // If something goes wrong
    }
    return 0;
}
