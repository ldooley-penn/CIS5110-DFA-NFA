#include "DeterministicFiniteAutomaton.h"

#include <iostream>

DeterministicFiniteAutomaton::DeterministicFiniteAutomaton(const NondeterministicFiniteAutomaton& nfa) :
    m_states({0}),
    m_alphabet(nfa.m_alphabet),
    m_startState(0),
    finalStates({})
{
    std::set<int> s0 = nfa.getEpsilonClosure({nfa.m_startState});
    std::map<std::set<int>, int> setToStateMap;
    std::vector<std::set<int>> stateToSetVector;
    setToStateMap[s0] = 0;
    stateToSetVector.push_back(s0);

    int marked = 0;

    while(marked < m_states.size()){
        marked += 1;
        int currentState = m_states[marked - 1];
        std::set<int> currentSet = stateToSetVector[currentState];
        for(const char letter : m_alphabet){
            std::set<int> T = nfa.evaluateTransitionWithEpsilonClosure(currentSet, letter);
            if(setToStateMap.count(T) == 0){
                setToStateMap[T] = m_states.size();
                stateToSetVector.push_back(T);
                m_states.push_back(m_states.size());
            }
            m_transitionFunction[{currentState, letter}] = setToStateMap[T];
        }
    }

    // Get final states
    for(auto state : m_states){
        std::set<int> stateSet = stateToSetVector[state];
        for(int nfaState : stateSet){
            if(nfa.isStateFinal(nfaState)){
                finalStates.insert(state);
                break;
            }
        }
    }
}

std::vector<bool> DeterministicFiniteAutomaton::runTest(std::vector<std::string> testWords) const
{
    std::vector<bool> results;
    std::cout << "\nTesting DFA:\n";
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

bool DeterministicFiniteAutomaton::isWordAccepted(const std::string& word) const
{
    int currentState = m_startState;
    for(char letter : word){
        auto transitionRow = m_transitionFunction.find({currentState, letter});
        if(transitionRow == m_transitionFunction.end()){
            return false;
        }
        currentState = transitionRow->second;
    }

    return finalStates.count(currentState) > 0;
}

void DeterministicFiniteAutomaton::print() const
{ 
    // Print title
    std::cout << "DFA Information\n";

    // Print states
    std::cout <<"\tStates: {";
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
    for(const auto& transition : m_transitionFunction){
        std::cout << "\t\t{{" << transition.first.first 
                  << ", " << transition.first.second 
                  << "}, " << transition.second << "}\n";
    }
    std::cout << "\n";

    // Print start state
    std::cout<<"\tStart State: " << m_startState << "\n";

    // Print final states
    std::cout<<"\tFinal States: {";
    for(int finalState : finalStates){
        std::cout << finalState << ", ";
    }
    std::cout << "}\n";
}