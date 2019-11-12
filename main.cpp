#include "DFA.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
  FCharacter<char> Zero ('0');
  FCharacter<char> One ('1');
  FCharacter<char> Two ('2');
  vector<FCharacter<char>> my_vector ({Zero, One, Two});

  Alphabet<FCharacter<char>> my_alphabet (my_vector);

  RString<FCharacter<char>> str1(3, Zero, One, Two);
  
  //Task 5: DFA that accepts no strings
 
  FCharacter<int> intZero (0);
  FCharacter<int> intOne (1);

  RString<int> test1 (2, intZero, intZero);
  RString<int> test2 (3, intZero, intZero, intOne);
  RString<int> test3 (3, intOne, intZero, intOne);
  RString<int> test4 (0); //empty string
  RString<int> test5 (1, intOne);

  auto noStrings = new DFA<int, FCharacter<int>>
    ([](int qi) { return qi == 0; },
     0,
     [](int qi) { return qi == -1; },
     [](int qi, FCharacter<int> c) { return 0; });

  cout << "Task 5: DFA that accepts no strings" << endl;
  cout << test1 << ": " << noStrings->accepts (test1) << " should be "
    << false << endl;
  cout << test2 << ": " << noStrings->accepts (test2) << " should be "
    << false << endl;
  cout << test3 << ": " << noStrings->accepts (test3) << " should be "
    << false << endl;
  cout << test4 << ": " << noStrings->accepts (test4) << " should be "
    << false << endl << endl;

  //Task 6: DFA that only accepts the empty string

  auto onlyEmpty = new DFA<int, FCharacter<int>>
    ([](int qi) { return qi == 0 || qi == 1; },
     0,
     [](int qi) { return qi == 0; },
     [](int qi, FCharacter<int> c) { return 1; });

  cout << "Task 6: DFA that accepts only the empty string" << endl;
  cout << test4 << ": " << onlyEmpty->accepts (test4) << " should be "
    << true << endl;
  cout << test1 << ": " << onlyEmpty->accepts (test1) << " should be "
    << false << endl;

  cout << endl;

  //Task 7: Function that generates a DFA that accepts only given character N
  DFA<int, FCharacter<int>> givenChar(intOne);

  cout << "Task 7: Function that generates a DFA that accepts only"
    " given character N" << endl;
  cout << test1 << ": " << givenChar.accepts (test1) << " should be "
    << false << endl;
  cout << test2 << ": " << givenChar.accepts (test2) << " should be "
    << false << endl;
  cout << test3 << ": " << givenChar.accepts (test3) << " should be "
    << false << endl;
  cout << test4 << ": " << givenChar.accepts (test4) << " should be "
    << false << endl;
  cout << test5 << ": " << givenChar.accepts (test5) << " should be "
    << true << endl;

  cout << endl;

  // DFA test that only accepts empty string and even length strings
  auto ex = new DFA<int, FCharacter<int>>
    ([](int qi) { return qi == 0 || qi == 1; },
     0,
     [](int qi) { return qi == 0; },
     [](int qi, FCharacter<int> c)
     { if (qi == 0) { return 1; } else { return 0; }});

  cout << "Example DFA that only accepts even length strings" << endl;
  cout << test1 << ": " << ex->accepts (test1) << " should be "
    << true << endl;
  cout << test2 << ": " << ex->accepts (test2) << " should be "
    << false << endl;
  cout << test3 << ": " << ex->accepts (test3) << " should be "
    << false << endl;
  cout << test4 << ": " << ex->accepts (test4) << " should be "
    << true << endl;

  return 0;
}
