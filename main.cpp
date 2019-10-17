#include "alphabet.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      cout << "Insufficient amount of arguments" << endl;
      exit(1);
    }
  FCharacter<char> Zero ('0');
  FCharacter<char> One ('1');
  FCharacter<char> Two ('2');
  vector<FCharacter<char>> my_vector ({Zero, One, Two});

  Alphabet<FCharacter<char>> my_alphabet (my_vector);

  RString<FCharacter<char>> str1(4, Zero, One, Two);
  cout << str1 << endl;

  cout << "Alphabet: " << my_alphabet << endl;
 
  RString<FCharacter<char>> str2 = lexi (my_alphabet, atoi(argv[1]));
  
  cout << str2 << endl;

  return 0;
}
