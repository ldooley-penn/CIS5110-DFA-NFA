#include "NondeterministicFiniteAutomaton.h"

#include <stack>
#include <iostream>

std::set<int> NondeterministicFiniteAutomaton::getEpsilonClosure(int state) const
{
    std::set<int> epsilonClosure;

    // Stack for dfs
    std::stack<int> stack;

    // Given state always inckuded in epsilon closure
    epsilonClosure.insert(state);
    // Start dfs from given state
    stack.push(state);

    while(!stack.empty()){
        // Get next state to search for closure
        int q = stack.top();
        stack.pop();

        // Find which states are reachable via epsilon transition
        std::set<int> nextStates = evaluateTransition(q, EPSILON);
        for (int nextState : nextStates) {
            // Only add next state if we haven't already
            if (epsilonClosure.count(nextState) == 0) {
                epsilonClosure.insert(nextState);
                stack.push(nextState);
            }
        }
    }

    return epsilonClosure;
}

std::set<int> NondeterministicFiniteAutomaton::getEpsilonClosure(std::set<int> states) const
{
    std::set<int> combinedEpsilonClosure;

    // Get epsilon closure for each state
    for (int state : states) {
        std::set<int> stateEpsilonClosure = getEpsilonClosure(state);
        combinedEpsilonClosure.insert(stateEpsilonClosure.begin(), stateEpsilonClosure.end());
    }

    return combinedEpsilonClosure;
}

std::set<int> NondeterministicFiniteAutomaton::evaluateTransition(int state, char input) const
{
    auto transitionRow = m_transitionFunction.find({state, input});
    if (transitionRow != m_transitionFunction.end()) {
        return transitionRow->second;
    }

    return {};
}

std::set<int> NondeterministicFiniteAutomaton::evaluateTransitionWithEpsilonClosure(std::set<int> states, char input) const
{
    std::set<int> result;

    for (int state : states) {
        // Get states from immediate transition
        std::set<int> nextStates = evaluateTransition(state, input);
        result.insert(nextStates.begin(), nextStates.end());
    }
    
    // Get epsilon closure after non-epsilon transition
    result = getEpsilonClosure(result);

    return result;
}

std::vector<bool> NondeterministicFiniteAutomaton::runTest(std::vector<std::string> testWords) const
{
    std::vector<bool> results;
    std::cout << "\n-Testing NFA:-\n";
    for(const std::string& word : testWords){
        results.push_back(isWordAccepted(word));
        if(results[results.size() - 1]){
            std::cout << "Word: '" << word << "' Result: Accepted\n";
        } else {
            std::cout << "Word: '" << word << "' Result: Rejected\n";
        }
    }
    return results;
}

bool NondeterministicFiniteAutomaton::isWordAccepted(const std::string& word) const
{
    std::set<int> currentStates = getEpsilonClosure(m_startState);

    // Traverse NFA
    for (char letter : word) {
        currentStates = evaluateTransitionWithEpsilonClosure(currentStates, letter);
        if (currentStates.empty()) {
            return false;
        }
    }

    // Check if any states are final
    for (int state : currentStates) {
        if (isStateFinal(state)) {
            return true;
        }
    }

    return false;
}

void NondeterministicFiniteAutomaton::print() const
{
    // Print title
    std::cout << "NFA Information:\n";

    // Print states
    std::cout << "\tStates: {";
    for(int state : m_states){
        std::cout << state << ", ";
    }
    std::cout << "}\n";

    // Print alphabet
    std::cout << "\tAlphabet: {";
    for(char letter : m_alphabet){
        std::cout << letter << ", ";
    }
    std::cout << "}\n";

    // Print transition function
    std::cout << "\tTransition Function:\n";
    for (const auto& transition : m_transitionFunction) {
        int initialState = transition.first.first;
        char letter = transition.first.second;
        const std::set<int>& transitionedStates = transition.second;

        for (int transitionedState : transitionedStates) {
            std::cout << "\t\t{{" << initialState << ", " << letter << "}, " << transitionedState << "}\n";
        }
    }
    std::cout<< "\n";

    // Print start state
    std::cout << "\tStart State: " << m_startState << "\n";

    // Print final states
    std::cout<<"\tFinal States: {";
    for(int finalState : m_finalStates){
        std::cout << finalState << ", ";
    }
    std::cout << "}\n";
}