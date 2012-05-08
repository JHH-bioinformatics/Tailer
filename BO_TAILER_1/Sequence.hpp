/************************************************

*************************************************/

#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<array>
#include<boost/iterator/iterator_concepts.hpp>
using namespace std;
using namespace boost_concepts;

template <typename T, template <typename ELEM> class CONT = vector>
class Sequences
{
private:
  CONT<T> container;
public:
  Sequences () {};
  Sequences (const Sequences&);
  Sequences& operator=(const Sequences&);
  bool add2Back (const T&);
  bool add2Front (const T&);
  T popBack ();
  T popFront ();
  void printSequence (istream&);
};




#endif /* SEQUENCE_HPP_ */
