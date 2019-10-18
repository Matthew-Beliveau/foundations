#include "alphabet.hpp"

using namespace std;

/*
  TODO: Define the following: States, Alphabet, Start, accepting,
  and transition.
 ;*/
template <typename state> // maybe <state, fchar>?
class DFA
{
public:
  bool Qstates(state);
  state qStart;
  bool acceptingState(state);
  state transition(state, char);
};
