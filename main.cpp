#include "DFA.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
  // if (argc != 2)
  //   {
  //     cout << "Insufficient amount of arguments" << endl;
  //     exit(1);
  //   }
  
  FCharacter<char> Zero ('0');
  FCharacter<char> One ('1');
  FCharacter<char> Two ('2');
  vector<FCharacter<char>> my_vector ({Zero, One, Two});

  Alphabet<FCharacter<char>> my_alphabet (my_vector);

  RString<FCharacter<char>> str1(3, Zero, One, Two);
  
  //Task 5: DFA that accepts no string; very confused on how to get this to
  //work
  
  auto noStrings = new DFA<int>
    ([](int qi) { return qi == 0; },
     0,
     [](int qi) { return qi == -1; },
     [](int qi, char c) { return 0; });

  return 0;
}
