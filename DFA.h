#include "alphabet.h"

using namespace std;

/*
  DFA class
*/
template <typename state, typename FChar>
class DFA
{
public:

  bool (*Qstates)(state);
  state qStart;
  bool (*acceptingState)(state);
  state (*transition)(state, FChar);

  DFA(bool (Q)(state), state q0, bool (*F)(state), state (Delta)(state, FChar)) : Qstates(Q), qStart(q0), acceptingState(F), transition(Delta) {};

  bool accepts(RString<state> str)
    {
      int length = str.string.size();
      state qi = qStart;
      for (int i = 0; i < length; i++)
	qi = transition(qi, str[i]);
      return acceptingState(qi);
    }
};
