#include <iostream>
#include <string>
#include <stdexcept>

const int kNumStates = 6;
const int kNumSymbols = 3;
int kTransitionTable[kNumStates][kNumSymbols] = {
    {5, 5, 1},
    {5, 2, 5},
    {2, 3, 2},
    {2, 3, 4},
    {5, 5, 5},
    {5, 5, 5}
};
bool kAcceptTable[kNumStates] = {false, false, false, false, true, false};

int getSymbolIndex(char ch);

bool simulateDFA(std::string input) {
    int state = 0;
    for (char ch : input) {
        int symbolIndex = getSymbolIndex(ch);
        state = kTransitionTable[state][symbolIndex];
    }
    return kAcceptTable[state];
}

int getSymbolIndex(char ch) {
    switch (ch) {
        case 'a': return 0;
        case '*': return 1;
        case '/': return 2;
        default: throw std::invalid_argument("Símbolo no válido: " + ch);
    }
}

int main() {
    std::string input;
    std::cout << "Ingrese el valor: ";
    std::cin >> input;
    bool isValid = simulateDFA(input);
    std::cout << "La cadena \"" << input << "\" es: " << (isValid ? "aceptable" : "no aceptable") << std::endl;
    return 0;
}

