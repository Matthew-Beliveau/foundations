#include <stdlib.h>
#include <vector>
#include <stdarg.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define TEMPLATE template <class FChar>
using namespace std;

template <typename character>
class FCharacter
{
public:
  character c;
  FCharacter () {}
  FCharacter (character cz) { c = cz; }

  friend ostream &operator<<(ostream &output, const FCharacter<character> &right)
    {
      output << right.c;
      return output;
    }
};

/*
  A finite set of characters, could be [0,1] or [a, b] or whatever.
  Character is defined by a typename template for abstraction.
  Symbol: Σ
 */
TEMPLATE
class Alphabet
{
public:
  vector<FChar> set;
  Alphabet<FChar> (vector<FChar> l) { set = l; } 

  friend ostream &operator<<(ostream &output, const Alphabet<FChar> &right)
    {
      for (auto v : right.set)
	output << v;
      return output;
    }

  FChar& operator[] (int index) { return set[index]; }
};

/*
  Empty Alphabet.
  Symbol: Ø
 */
TEMPLATE
class Empty_Alphabet : Alphabet<FChar> {};

TEMPLATE
class RString
{
public:
  vector<FChar> string;
  RString () {} 
  // Variadic constructor so I don't have to bother with an add function
  RString (int count, ...)
  {
    va_list ap;  
    //string.push_back (new Empty_FString<FChar> ());
    va_start(ap, count);
    for (int i = 0; i < count; i++)
    {
      string.push_back (va_arg(ap, FChar));
    }
    va_end(ap);
   }

  bool empty()
    {
      return string.empty();
    }

  FChar& operator[] (int index) { return string[index]; }


  friend ostream &operator<<(ostream &output, const RString<FChar> &right)
    {
      if (right.string.empty())
	output << "ε";
      for (auto v : right.string)
	output << v;
      return output;
    }
};

/*
  The empty string.
  Symbol: ε
 */
TEMPLATE
class Empty_FString : RString<FChar>
{
  bool isEmpty () { return true; }
  Empty_FString () {}
};

/*
  Generates the Nth string in a given Alphabet's lexicographical ordering,
  or Nth string in Σ*.
 */
TEMPLATE
RString<FChar> lexi(Alphabet<FChar> a, int n)
{
  RString<FChar> result;
  int x = a.set.size(); // Cardinality of the alphabet.
  int string_i; // length of the Nth string.
  int cardinality = x; // number of strings of string_i
  int position;

  /*
    Calculate string_i in order to determine the cardinality and number of sets
    needed to calculate cartesian product.
   */
  if (n == 0)
    string_i = cardinality = 0; //if n=0 then both length and cardinality are 0
  else
    {
      int total = 0;
      for (int i = 0; total <= n; i++)
	{
	  string_i = i;
	  total += pow (x, i);
	}
     // Calculate the cardinality of strings of length string_i
      cardinality = pow (x , string_i);
      position = cardinality - (total - n);
    }
 
  /*
    Generate Nth string by pretending to generate all strings of length
    string_i that come before the Nth string but only recording the elements
    we want. 
   */
  int temp_card = cardinality/x;
  for (int i = 0; i < string_i; i++)
    {
      int p = 0; // position for result
      for (int j = 0; j < pow (x, i+1); j++)
	{
	  for (int k = 0; k < temp_card && p <= position; k++)
	    {
	      if (p == position)
		result.string.push_back (a[j%x]);
	      p++;
	    }
	}
      temp_card /= x;
    }

  return result;
}
