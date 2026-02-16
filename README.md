# CIS5110-DFA-NFA

A short c++ project for converting NFA to DFA and testing results. No visualizations, but you can use print() on a DFA to see the states, alphabet,
transition table, start state, and final states. See src/main.cpp for example.


If you don't have c++ build tools, this is the output from running the program as is:

```
--- Testing Simple NFA to DFA Conversion ---

Testing NFA:
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

Testing DFA:
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

Test results:
        Success: NFA and DFA results match!

DFA Information
        States: {0, 1, 2, 3, }
        Alphabet: {a, b, }
        Transition Function:
                {{0, a}, 1}
                {{0, b}, 0}
                {{1, a}, 1}
                {{1, b}, 2}
                {{2, a}, 1}
                {{2, b}, 3}
                {{3, a}, 1}
                {{3, b}, 0}

        Start State: 0
        Final States: {3, }

--- Testing Complex NFA to DFA Conversion ---

Testing NFA:
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

Testing DFA:
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

Test results:
        Success: NFA and DFA results match!

DFA Information
        States: {0, 1, 2, 3, 4, }
        Alphabet: {a, b, }
        Transition Function:
                {{0, a}, 1}
                {{0, b}, 2}
                {{1, a}, 1}
                {{1, b}, 3}
                {{2, a}, 1}
                {{2, b}, 2}
                {{3, a}, 1}
                {{3, b}, 4}
                {{4, a}, 1}
                {{4, b}, 2}

        Start State: 0
        Final States: {4, }
```