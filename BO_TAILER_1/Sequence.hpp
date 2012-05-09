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
/*you don't have to include these, you can just use "forward declaration". let user to include it when necessary, google it.*/
#include<boost/iterator/iterator_concepts.hpp>
using namespace std; /*<-- let's try not to use using...*/
using namespace boost_concepts; /*<---what is this for?*/

template <typename T,
  template <typename, typename > class CONT = vector>
/* all std container have two template parameters, your declaration will not work,I fixed it.
 * The alternative way of doing is like:
 * template <typename T, typename ContainerType = vector<T>>
 *  class qq
 *  {
 *  	Container container;
 *  };
 */

class Sequences
{
private:
  CONT<T, allocator<T> > container;
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
