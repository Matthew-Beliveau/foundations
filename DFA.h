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

  DFA(FChar n)
    {
      Qstates = [](int qi) { return qi == 0 || qi == 1 || qi == 2; };
      qStart = 0;
      acceptingState = [](int qi) { return qi == 1;};
      auto Delta = [n](int qi, FChar c)
	{
	  if (qi == 0 && c == n) { return 1; }
	  else if (qi == 0 && c != n) { return 2; }
	  if (qi == 1) { return 2; }
	  if (qi == 2) { return 2; }
	};
      static auto static_Delta = Delta;
      transition = [](int qi, FChar c) { return static_Delta (qi, c);};
    }
};
