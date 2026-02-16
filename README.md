# CIS5110-DFA-NFA

A short c++ project for converting NFA to DFA and testing results. No visualizations, but you can use print() on a DFA to see the states, alphabet,
transition table, start state, and final states. See src/main.cpp for example of two
NFAs accepting {a, b}*abb.


If you don't have c++ build tools, this is the output from running the program as is:

```
--- Testing Simple NFA to DFA Conversion ---
--NFA input:--
NFA Information:
        States: {0, 1, 2, 3, }
        Alphabet: {a, b, }
        Transition Function:
                {{0, a}, 0}
                {{0, a}, 1}
                {{0, b}, 0}
                {{1, b}, 2}
                {{2, b}, 3}

        Start State: 0
        Final States: {3, }

--NFA translated to DFA:--
DFA Information:
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

--Test results:--

-Testing NFA:-
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

-Testing DFA:-
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

Success: NFA and DFA results match!


--- Testing Complex NFA to DFA Conversion ---
--NFA input:--
NFA Information:
        States: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, }
        Alphabet: {a, b, }
        Transition Function:
                {{0, }, 1}
                {{0, }, 7}
                {{1, }, 2}
                {{1, }, 4}
                {{2, a}, 3}
                {{3, }, 6}
                {{4, b}, 5}
                {{5, }, 6}
                {{6, }, 1}
                {{6, }, 7}
                {{7, a}, 8}
                {{8, b}, 9}
                {{9, b}, 10}

        Start State: 0
        Final States: {10, }

--NFA translated to DFA:--
DFA Information:
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

--Test results:--

-Testing NFA:-
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

-Testing DFA:-
Word: 'abb' Result: Accepted
Word: 'aabb' Result: Accepted
Word: 'ab' Result: Rejected
Word: 'aabbb' Result: Rejected
Word: 'babb' Result: Accepted
Word: '' Result: Rejected

Success: NFA and DFA results match!
```