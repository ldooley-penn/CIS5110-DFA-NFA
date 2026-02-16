#pragma once

static constexpr char EPSILON = '\0';

#include <string>
#include <vector>
#include <set>
#include <map>

struct NondeterministicFiniteAutomaton {
    NondeterministicFiniteAutomaton(std::vector<int> states, 
        std::set<char> alphabet, 
        std::map<std::pair<int, char>, std::set<int>> transitionFunction, 
        int startState, 
        std::set<int> finalStates) :
        m_states(states),
        m_alphabet(alphabet),
        m_transitionFunction(transitionFunction),
        m_startState(startState),
        m_finalStates(finalStates)
    {
    }

    ~NondeterministicFiniteAutomaton() = default;

    std::set<int> getEpsilonClosure(int state) const;
    std::set<int> getEpsilonClosure(std::set<int> states) const;
    std::set<int> evaluateTransition(int state, char input) const;
    std::set<int> evaluateTransitionWithEpsilonClosure(std::set<int> states, char input) const;
    bool isStateFinal(int state) const {
        return m_finalStates.count(state) > 0;
    }

    std::vector<bool> runTest(std::vector<std::string> testWords) const;
    bool isWordAccepted(const std::string& word) const;

    void print() const;

    std::vector<int> m_states;
    std::set<char> m_alphabet;
    std::map<std::pair<int, char>, std::set<int>> m_transitionFunction;
    int m_startState;
    std::set<int> m_finalStates;
};