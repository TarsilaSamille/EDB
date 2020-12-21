 /**
  * @file MyIterator.h
  * @author Társila Samille (tarsillasamile@gmail.com)
  * @brief 
  * @version 0.1
  * @date 2020-11-08
  *
  * @section DESCRIÇÃO
  * Iterator usado pela classe vector.
  * @copyright Copyright (c) 2020
  * 
  */
 template < typename T > class MyIterator {
   public:
      typedef std::ptrdiff_t difference_type; //!< Difference type used to calculated distance between iterators.
      typedef T value_type; //!< Value type the iterator points to.
      typedef T * pointer; //!< Pointer to the value type.
      typedef T & reference; //!< Reference to the value type.
      typedef std::bidirectional_iterator_tag iterator_category; //!< Iterator category.

   MyIterator() {
     current = nullptr;
   }

   MyIterator & operator = (const MyIterator & other) {
     current = other.current;
     return *this;
   }

   MyIterator(pointer ref) {
     current = ref;
   }

   reference operator * () const {
     return *current;
   }

   pointer operator -> (void) const {
     assert(current != nullptr);
     return current;
   }

   MyIterator & operator++() // ++it;
   {
     current++;
     return *this;
   }

   MyIterator operator++(int n) // it++;
   {
     MyIterator temp = * this;
     current++;
     return temp;
   }

   MyIterator & operator--() // --it;
   {
     current--;
     return *this;
   }

   MyIterator operator--(int n) // it--;
   {
     MyIterator temp = * this;
     current--;
     return temp;
   }

   friend MyIterator operator + (difference_type n, MyIterator it) {
     it.current += n;
     return it;
   }

   friend MyIterator operator + (MyIterator it, difference_type n) {
     it.current += n;
     return it;
   }

   friend difference_type operator + (MyIterator it, MyIterator other) {
     return it.current + other.current;
   }

   friend MyIterator operator - (difference_type n, MyIterator it) {
     it.current -= n;
     return it;
   }

   friend MyIterator operator - (MyIterator it, difference_type n) {
     it.current -= n;
     return it;
   }

   friend difference_type operator - (MyIterator it, MyIterator other) {
     return it.current - other.current;
   }

   bool operator == (const MyIterator & other) const {
     return (current - other.current) == 0;
   }

   bool operator != (const MyIterator & other) const {
     return (current - other.current) != 0;
   }

   private:
     T * current;
 };