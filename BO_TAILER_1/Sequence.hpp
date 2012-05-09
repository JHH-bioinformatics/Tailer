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

/**
 * forward declaration of map
 * */
template < class Key, class T, class Compare = std::less<Key>,
           class Allocator = std::allocator<std::pair<const Key,T>>>
class map;

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
 * declaration of Sequence class, continuous container version
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
  CONTAINER container;
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
/**
 * declaration of Process class, continuous container version
 */
template <typename T,
  template <typename, typename > class CONT = std::vector,
  typename T_TRAIT = TRAIT<T>>
class Process : public Sequences<T,CONT,T_TRAIT>
{

};

/**
 * declaration of Sequence class, associate container version
 * */
template <typename T_Key,
  typename T_Value,
  template <typename, typename, typename, typename> class CONT = std::map,
  typename Key_TRAIT = TRAIT<T_Key>,
  typename Value_TRAIT = TRAIT<T_Value>>
class Sequences2
{
  typedef std::pair<T_Key, T_Value>  value_type;
  typedef T_Key                      key_type;
  typedef CONT<T_Key, T_Value, std::less<T_Key>, std::allocator<std::pair<const T_Key, T_Value>>> CONTAINER;
  typedef typename CONTAINER::iterator Iterator;
  typedef typename std::iterator_traits<Iterator>::value_type Iterator_value_type;

protected:
  CONTAINER container;
public:
  Sequences2 () {}; ///default constructor
  Sequences2 (const Sequences2& ); ///copy constructor
  Sequences2 (      Sequences2&&); ///move constructor
  Sequences2& operator=(const Sequences2& ); ///copy assignment operator
  Sequences2& operator=(      Sequences2&&); ///move assignment operator
  ~Sequences2()
  {
    container.clear();
  } ///destructor
  Iterator& insert  (std::pair<T_Key, T_Value>& );
  Iterator& emplace (std::pair<T_Key, T_Value>&&);
  Iterator& erase   (Iterator );
  Iterator& erase   (Iterator, Iterator);
};
/**
 * declaration of Process class, associate container version
 */
template <typename T_Key,
  typename T_Value,
  template <typename, typename, typename, typename> class CONT = std::map,
  typename Key_TRAIT = TRAIT<T_Key>,
  typename Value_TRAIT = TRAIT<T_Value>>
class Process2 : public Sequences2<T_Key, T_Value, CONT, Key_TRAIT, Value_TRAIT>
{

};
#endif /* SEQUENCE_HPP_ */



