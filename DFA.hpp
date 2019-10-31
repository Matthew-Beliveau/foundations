#include "alphabet.hpp"

using namespace std;

/*
TODO: add abstraction for types of strings
  DFA class
*/
template <typename state> // maybe <state, fchar>?
class DFA
{
public:

  //shouldn't have to make these a pointer
  bool (*Qstates)(state);
  state qStart;
  bool (*acceptingState)(state);
  state (*transition)(state, char);

  DFA(bool (Q)(state), state q0, bool (*F)(state), state (Delta)(state, char)) : Qstates(Q), qStart(q0), acceptingState(F), transition(Delta) {};

  bool accepts(RString<state> string)
    {
      size_t length = string.length();
      state qi = qStart;
      for (int i = 0; i < length; i++)
	qi = transition(qi, string[i]);
      return acceptingState(qi);
    }
};
