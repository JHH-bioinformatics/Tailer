/************************************************

*************************************************/

#ifndef SEQUENCE_HPP_
#define SEQUENCE_HPP_

#include <string>
/** forward declarations
 *
 */
namespace std
{
  template <typename, typename>  /// forward declaration of pair
  struct pair;
  template <typename, typename>  /// forward declaration of vector
  class vector;
  template <typename, typename>  /// forward declaration of deque
  class deque;
  template <typename, typename>  /// forward declaration of list
  class list;
  template <typename, typename, typename>  /// forward declaration of set
  class set;
  template <typename, typename, typename, typename>  /// forward declaration of map
  class map;
  template <typename, typename, typename, typename, typename>  /// forward declaration of unordered_map
  class unordered_map;
}
/**declaration of TRAIT
 *
 */
template <typename T>
class TRAIT {};

/**specialization of TRAIT for string
 *
 */
template <>
class TRAIT <std::string>
{

};

/**specialization of TRAIT for int
 *
 */
template <>
class TRAIT <int>
{

};
/**specialization of TRAIT for char*
 *
 */
template <>
class TRAIT <char*>
{

};

/**
 * primary declaration of Sequence class
 * */
template <typename T, ///data type
  template < typename ...  > class CONT = std::vector> ///container type
class Sequences
{
  typedef T                                                     value_type;
  typedef TRAIT<T>                                              T_TRAIT;
  typedef CONT<T, std::allocator<T>>                            CONTAINER;
  typedef typename CONTAINER::iterator                          Iterator;
  typedef typename std::iterator_traits<Iterator>::value_type   Iterator_value_type;

protected:
  CONTAINER container;

public:
  Sequences () {}; ///default constructor
  Sequences (const Sequences& ); ///copy constructor
  Sequences (      Sequences&&); ///move constructor
  Sequences&
    operator=(const Sequences& ); ///copy assignment operator
  Sequences&
    operator=(      Sequences&&); ///move assignment operator
  ~Sequences() ///destructor
  {
    container.clear();
  }
  Iterator&
    insert  (const T& );
  Iterator&
    emplace (      T&&);
  Iterator&
    erase   (Iterator );
  Iterator&
    erase   (Iterator, Iterator);
};


template <typename T, ///data type
  template < typename ...  > class CONT = std::map>  ///container type
class Parser : public Sequences<T,CONT>
{

};

#endif
