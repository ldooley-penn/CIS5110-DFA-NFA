#include "NondeterministicFiniteAutomaton.h"
#include "DeterministicFiniteAutomaton.h"

#include <iostream>

const std::vector<std::string> testWords = {
        "abb", 
        "aabb", 
        "ab", 
        "aabbb", 
        "babb",
        "\0"
    };

void RunTest(const NondeterministicFiniteAutomaton& nfa){
    std::vector<bool> nfaResults = nfa.runTest(testWords);

    DeterministicFiniteAutomaton dfaFromNFA(nfa);

    std::vector<bool> dfaResults =dfaFromNFA.runTest(testWords);

    std::cout<<"\nTest results:\n";

    if(nfaResults != dfaResults){
        std::cerr << "\tError: NFA and DFA results do not match!\n\n";
    } else {
        std::cout << "\tSuccess: NFA and DFA results match!\n\n";
    }

    dfaFromNFA.print();
}


int main(int, char**){
    // Simple NFA for accepting {a, b}*abb
    NondeterministicFiniteAutomaton simpleNfa(
        {0, 1, 2, 3},
        {'a', 'b'},
        {
            {{0, 'a'}, {0, 1}},
            {{0, 'b'}, {0}},
            {{1, 'a'}, {}},
            {{1, 'b'}, {2}},
            {{2, 'a'}, {}},
            {{2, 'b'}, {3}},
            {{3, 'a'}, {}},
            {{3, 'b'}, {}}
        },
        0,
        {3}
    );

    // Complex NFA for accepting {a, b}*abb
    NondeterministicFiniteAutomaton complexNfa(
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {'a', 'b'},
        {
            {{0, EPSILON}, {1, 7}},
            {{1, EPSILON}, {2, 4}},
            {{2, 'a'}, {3}},
            {{3, EPSILON}, {6}},
            {{4, 'b'}, {5}},
            {{5, EPSILON}, {6}},
            {{6, EPSILON}, {1, 7}},
            {{7, 'a'}, {8}},
            {{8, 'b'}, {9}},
            {{9, 'b'}, {10}}
        },
        0,
        {10}
    );

    std::cout << "--- Testing Simple NFA to DFA Conversion ---\n";
    RunTest(simpleNfa);

    std::cout << "\n--- Testing Complex NFA to DFA Conversion ---\n";
    RunTest(complexNfa);
}
