#pragma once

#include "NondeterministicFiniteAutomaton.h"

#include <string>
#include <vector>
#include <set>
#include <map>

struct DeterministicFiniteAutomaton {
    DeterministicFiniteAutomaton(std::vector<int> states, 
        std::set<char> alphabet, 
        std::map<std::pair<int, char>, int> transitionFunction, 
        int startState, 
        std::set<int> finalStates) :
        m_states(states),
        m_alphabet(alphabet),
        m_transitionFunction(transitionFunction),
        m_startState(startState),
        finalStates(finalStates)
    {
    }
    
    DeterministicFiniteAutomaton(const NondeterministicFiniteAutomaton& nfa);
    ~DeterministicFiniteAutomaton() = default;

    std::vector<bool> runTest(std::vector<std::string> testWords) const;
    bool isWordAccepted(const std::string& word) const;

    void print() const;

    std::vector<int> m_states;
    std::set<char> m_alphabet;
    std::map<std::pair<int, char>, int> m_transitionFunction;
    int m_startState;
    std::set<int> finalStates;
};