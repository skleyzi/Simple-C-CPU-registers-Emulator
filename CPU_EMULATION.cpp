#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function prototypes
void help();
void executeProgram(const vector<string>& program);

int main() {
    string command;
    vector<string> program;

    cout << "Welcome to CPU Emulator!\n";
    cout << "Type 'help' to see available commands.\n";

    while (true) {
        cout << "\nEnter a command: ";
        cin >> command;

        if (command == "help") {
            help();
        }
        else if (command == "prog") {
            cout << "Available instructions: mov add sub mul div\n";
            string programString;
            cout << "Enter your program (separate commands with whitespace): ";
            cin.ignore();
            getline(cin, programString);

            stringstream ss(programString);
            string token;
            while (ss >> token) {
                program.push_back(token);
            }

            cout << "Program entered successfully.\n";
        }
        else if (command == "run") {
            if (program.empty()) {
                cout << "No program entered. Please enter a program first.\n";
            }
            else {
                executeProgram(program);
            }
        }
        else if (command == "exit") {
            cout << "Exiting CPU Emulator.\n";
            break;
        }
        else {
            cout << "Invalid command. Type 'help' to see available commands.\n";
        }
    }

    return 0;
}

void help() {
    cout << "\nAvailable commands:\n";
    cout << "help - Display available commands\n";
    cout << "prog - Enter a program\n";
    cout << "run - Run the entered program\n";
    cout << "exit - Exit the program\n";
}

void executeProgram(const vector<string>& program) {
    int ax = 0, bx = 0, dx = 0;
    for (const string& instruction : program) {
        if (instruction == "add") {
            int value;
            cout << "Enter value to add to AX register: ";
            cin >> value;
            ax += value;
        }
        else if (instruction == "sub") {
            int value;
            cout << "Enter value to subtract from ax register: ";
            cin >> value;
            ax -= value;
        }
        else if (instruction == "mul") {
            int value;
            cout << "Enter value to multiply with dx register: ";
            cin >> value;
            dx *= value;
        }
        else if (instruction == "div") {
            int value;
            cout << "Enter value to divide dx register by: ";
            cin >> value;
            if (value != 0)
                dx /= value;
            else
                cout << "Error: Division by zero.\n";
        }
        else if (instruction == "mov") {
            string destRegister;
            string src;
            cout << "Enter destination register (ax, bx, or dx): ";
            cin >> destRegister;
            cout << "Enter source (register or value): ";
            cin >> src;

            int value;
            if (src == "ax") value = ax;
            else if (src == "bx") value = bx;
            else if (src == "dx") value = dx;
            else value = stoi(src);

            if (destRegister == "ax")
                ax = value;
            else if (destRegister == "bx")
                bx = value;
            else if (destRegister == "dx")
                dx = value;
            else
                cout << "Invalid register name.\n";
        }
        else {
            cout << "Invalid instruction: " << instruction << endl;
        }
    }
    cout << "Program execution complete.\n";
    cout << "ax = " << ax << ", bx = " << bx << ", dx = " << dx << endl;
}
