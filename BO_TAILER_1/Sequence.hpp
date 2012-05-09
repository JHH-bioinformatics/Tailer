/************************************************

*************************************************/

#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

#include<string>

/**
 * forward declaration of vector
 * */
template < typename T, typename Allocator = std::allocator<T> >
class vector;
/**declaration of TRAIT
 *
 */
template <typename T>
class TRAIT
{
};
/**specialization of TRAIT
 *
 */
template <>
class TRAIT <std::string>
{

};
template <>
class TRAIT <int>
{

};
template <>
class TRAIT <char*>
{

};
/**
 * declaration of Sequence class
 * */
template <typename T,
  template <typename, typename > class CONT = std::vector,
  typename T_TRAIT = TRAIT<T>>
class Sequences
{
  typedef T        value_type;
  typedef CONT<T, std::allocator<T>> CONTAINER;
  typedef typename CONTAINER::iterator Iterator;
  typedef typename std::iterator_traits<Iterator>::value_type Iterator_value_type;

protected:
  CONT<T, std::allocator<T> > container;
public:
  Sequences () {}; ///default constructor
  Sequences (const Sequences& ); ///copy constructor
  Sequences (      Sequences&&); ///move constructor
  Sequences& operator=(const Sequences& ); ///copy assignment operator
  Sequences& operator=(      Sequences&&); ///move assignment operator
  ~Sequences()
  {
    container.clear();
  } ///destructor
  Iterator& insert  (const T& );
  Iterator& emplace (      T&&);
  Iterator& erase   (Iterator );
  Iterator& erase   (Iterator, Iterator);
};

template <typename T,
  template <typename, typename > class CONT = std::vector,
  typename T_TRAIT = TRAIT<T>>
class Process : public Sequences<T,CONT,T_TRAIT>
{

};


#endif /* SEQUENCE_HPP_ */


