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

  DFA(bool (Q)(state),
      state q0,
      bool (*F)(state),
      state (Delta)(state, FChar))
    : Qstates(Q), qStart(q0), acceptingState(F), transition(Delta) {};

  bool accepts(RString<state> str)
    {
      int length = str.string.size();
      state qi = qStart;
      for (int i = 0; i < length; i++)
	qi = transition(qi, str[i]);
      return acceptingState(qi);
    }
};

template <typename state, typename FChar>
DFA<state, FChar> character_DFA(state a, state b, state c, FChar n)
  {
    auto x = new DFA<int, FChar>
       ([](int qi) {return qi == 0 || qi == 1 || qi == 2;},
	 a,
       [](int qi) {return qi == 2;},
       [=n](int qi, FChar c) 
       { 
        if (qi == 0 && c == n) { return 2; } 
        else if (qi == 0 && c != n) { return 1; }
        if (qi == 1) { return 2; }
        if (qi == 2) { return 2; }
       });
    return x;
  }
