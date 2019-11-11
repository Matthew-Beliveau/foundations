#include "DFA.h"
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
  
  //Task 5: DFA that accepts no strings
 
  FCharacter<int> intZero (0);
  FCharacter<int> intOne (1);

  RString<int> test1(2, intZero, intZero);
  RString<int> test2(3, intZero, intZero, intOne);
  RString<int> test3(3, intOne, intZero, intOne);
  RString<int> test4(0); //empty string

  auto noStrings = new DFA<int, FCharacter<int>>
    ([](int qi) { return qi == 0; },
     0,
     [](int qi) { return qi == -1; },
     [](int qi, FCharacter<int> c) { return 0; });

  cout << "Task 5: DFA that accepts no strings" << endl;
  cout << noStrings->accepts(test1) << " should be " << false << endl;
  cout << noStrings->accepts(test2) << " should be " << false << endl;
  cout << noStrings->accepts(test3) << " should be " << false << endl;
  cout << noStrings->accepts(test4) << " should be " << false << endl;

  cout << endl;
  // DFA test that only accepts empty string and even length strings
  auto ex = new DFA<int, FCharacter<int>>
    ([](int qi) { return qi == 0 || qi == 1; },
     0,
     [](int qi) { return qi == 0; },
     [](int qi, FCharacter<int> c) { if (qi == 0) { return 1; } else { return 0; }});

  cout << "Example DFA that only accepts even length strings" << endl;
  cout << ex->accepts(test1) << " should be " << true << endl;
  cout << ex->accepts(test2) << " should be " << false << endl;
  cout << ex->accepts(test3) << " should be " << false << endl;
  cout << ex->accepts(test4) << " should be " << true << endl;

  return 0;
}
