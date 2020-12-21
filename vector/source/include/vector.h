/**
 * @file vector.h
 * @author Társila Samille (tarsillasamile@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-11-08
 *
 * @section DESCRIÇÃO
 * Implementação da classe vector, array com alocação dinamica.
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib> 	// size_t
#include <iostream>	
using std::cerr;
using std::distance;
#include <exception>
#include <algorithm>       	
using std::min;
#include <initializer_list>	
using std::initializer_list;
#include <iterator>
#include <stdexcept>	
using std::out_of_range;
#include <string>   	
using std::to_string;
#include "./MyIterator.h"

namespace sc {
  template < typename T >
    class vector {
      public:
        using size_type = unsigned long; //!< The size type.
        using value_type = T; //!< The value type.
        using pointer = value_type * ; //!< Pointer to a value stored in the container.
        using reference = value_type & ; //!< Reference to a value stored in the container.
        using const_reference = const value_type & ; //!< Const reference to a value stored in the container.
        using iterator = MyIterator < T > ; //!< Iterator that points to a specific element of type T.
        using const_iterator = MyIterator < const T > ; //!< Const iterator that points to a specific element of type T.

      /** @name [I] Special members
       *i. Regular constructor;
       *ii. Destructor;
       *iii. Copy constructor;
       *iv. Constructor from range;
       *v. Constructor from initialize list;
       *vi. Assignment operator;
       */
      ///@{
        vector() {
          m_end = 0;
          m_capacity = 0;
          m_storage = new T[m_capacity];
        }

        ~vector() {
          delete[] m_storage;
        }

      explicit vector(size_type count) {
        m_end = 0;
        m_capacity = count;
        m_storage = new T[m_capacity];
      }

      vector(const vector & other) {
        m_end = other.size();
        m_capacity = 2 * m_end;
        m_storage = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = other.m_storage[i];
      }

      vector(std::initializer_list < T > ilist) {
        m_end = ilist.size();
        m_capacity = m_end;
        m_storage = new T[m_end];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = * (ilist.begin() + i);
      }

      vector(vector && other) {
        m_end = other.size();
        m_capacity = 2 * m_end;
        m_storage = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = other.m_storage[i];
      }

      template < typename InputIt >
        vector(InputIt first, InputIt last) {
          m_end = last - first;
          m_capacity = 2 * m_end;
          m_storage = new T[m_capacity];

          for (auto i(0u); i < m_end; i++)
            m_storage[i] = * first++;
        }

      vector & operator = (const vector & other) {
        m_end = other.size();
        m_capacity = other.capacity();
        m_storage = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = other.m_storage[i];
        return *this;
      }

      vector & operator = (vector && other) {
        m_end = other.size();
        m_capacity = other.capacity();
        m_storage = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = other.m_storage[i];

        other = {};
        return *this;
      }
      vector & operator = (std::initializer_list < T > ilist) {
        m_end = ilist.size();
        m_capacity = m_end;
        m_storage = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = * (ilist.begin() + i);

        return *this;
      }
      //!@}
      /** @name [II] Iterator methods
       */
      ///@{
      iterator begin() {
        iterator it( & m_storage[0]);
        return it;
      }

      iterator end() {
        iterator it( & m_storage[m_end]);
        return it;
      }

      const_iterator cbegin() const {
        const_iterator it( & m_storage[0]);
        return it;
      }

      const_iterator cend(void) const {
        const_iterator it( & m_storage[m_end]);
        return it;
      }
      //!@}
      /** @name [III] Capacity
       */
      ///@{
      size_type size() const {
        return m_end;
      }

      size_type capacity() const {
        return m_capacity;
      }

      bool empty() {
        return m_end == 0;
      }
      //!@}
      /** @name [IV] Modifiers
       */
      ///@{
      void clear() {
        m_end = 0;
      }

      void push_front(const_reference value) {
        reserve(m_end + 1);

        for (int i = m_end; i > 0; i--)
          m_storage[i] = m_storage[i - 1];

        m_storage[0] = value;

        ++m_end;
      }

      void push_back(const_reference value) {
        reserve(m_end + 1);
        m_storage[m_end] = value;
        ++m_end;
      }

      void pop_back() {
        --m_end;
      }

      void pop_front() {
        for (auto i(0u); i < m_end - 1; i++)
          m_storage[i] = m_storage[i + 1];
        --m_end;
      }

      iterator insert(iterator pos, const_reference value) {
        std::ptrdiff_t deslocation = pos - begin();

        if (deslocation > m_end)
          return begin();

        reserve(m_end + 1);
        m_end++;

        iterator new_position = begin() + deslocation;
        iterator end( & m_storage[m_end - 1]);

        while (end != new_position) {
          * end = * (end - 1);
          end--;
        }

        * end = value;
        return new_position;
      }

      template < typename InputItr >
        iterator insert(iterator pos, InputItr first, InputItr last) {

          std::ptrdiff_t deslocation = pos - begin();

          if (deslocation > m_end)
            return begin();

          int dist = std::distance(first, last);

          reserve(m_end + dist);
          m_end += dist;

          iterator new_position = begin() + deslocation;
          iterator old_end = end() - (dist + 1);
          iterator end( & m_storage[m_end - 1]);

          while (old_end != (new_position - 1)) {
            * end = * old_end;
            old_end--;
            end--;
          }

          last--;
          while (last != (first - 1)) {
            * end = * last;
            last--;
            end--;
          }

          return new_position;
        }

      iterator insert(iterator pos,
        const std::initializer_list < value_type > & ilist) {
        std::ptrdiff_t deslocation = pos - begin();

        if (deslocation > m_end)
          return begin();

        int size = ilist.size();

        reserve(m_end + size);
        m_end += size;

        iterator new_position = begin() + deslocation;
        iterator old_end = end() - (size + 1);
        iterator end( & m_storage[m_end - 1]);
        while (old_end != (new_position - 1)) {
          * end = * old_end;
          old_end--;
          end--;
        }

        auto first = ilist.begin();
        auto last = ilist.end() - 1;
        while (last != (first - 1)) {
          * end = * last;
          last--;
          end--;
        }
        return new_position;
      }

      void reserve(size_type new_cap) {
        if (new_cap < capacity())
          return;

        m_capacity = m_capacity == 0 ? 2 : 2 * m_capacity;
        T * new_data = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          new_data[i] = m_storage[i];

        m_storage = new_data;
      }

      void shrink_to_fit() {
        m_capacity = m_end;
        T * new_data = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          new_data[i] = m_storage[i];

        m_storage = new_data;
      }

      void assign(size_type count, const_reference value) {
        m_end = count;
        if (count > capacity())
          m_capacity = count;

        T * new_data = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          new_data[i] = value;

        m_storage = new_data;
      }

      void assign(const std::initializer_list < T > & ilist) {
        int size = ilist.size();
        m_end = size;
        if (size > capacity())
          m_capacity = size;

        T * new_data = new T[m_capacity];

        for (auto i(0u); i < m_end; i++)
          m_storage[i] = * (ilist.begin() + i);

        m_storage = new_data;
      }

      template < typename InputItr >
        void assign(InputItr first, InputItr last) {
          int size = last - first;
          m_end = size;
          if (size > capacity())
            m_capacity = size;

          T * new_data = new T[m_capacity];

          iterator it = & new_data[0];
          while (first != last) {
            * it = * first;
            it++;
            first++;
          }

          m_storage = new_data;

        }

      iterator erase(iterator first, iterator last) {
        iterator past_last = first;
        iterator actual_last = last;
        while (first != actual_last) {
          * first = * last;
          m_end--;
          first++;
          last++;
        }

        return past_last;
      }

      iterator erase(iterator pos) {
        iterator past_last = pos;
        while (pos != end()) {
          * pos = * (pos + 1);
          pos++;
        }

        m_end--;

        return past_last;
      }
      //!@}
      /** @name [V] Element access
       */
      ///@{
      const_reference front() const {
        return m_storage[0];
      }

      reference front() {
        return m_storage[0];
      }

      const_reference back() const {
        return m_storage[m_end - 1];
      }

      reference back() {
        return m_storage[m_end - 1];
      }

      reference operator[](size_type pos) {
        return m_storage[pos];
      }

      const_reference operator[](size_type pos) const {
        return m_storage[pos];
      }

      const_reference at(size_type pos) const {
        if (pos < 0 || pos >= m_end)
          throw std::out_of_range(std::to_string(pos));
        return m_storage[pos];
      }

      reference at(size_type pos) {
        if (pos < 0 || pos >= m_end)
          throw std::out_of_range(std::to_string(pos));
        return m_storage[pos];
      }
      //!@}
      /** @name [VI] Operators
       */
      ///@{
      bool operator == (const vector & other) const {
        if (size() == other.size()) {
          for (auto i(0u); i < m_end; i++)
            if (m_storage[i] != other.m_storage[i])
              return false;
        } else {
          return false;
        }

        return true;
      }

      bool operator != (const vector & other) const {
        if (size() != other.size()) {
          return true;
        } else {
          for (auto i(0u); i < m_end; i++)
            if (m_storage[i] != other.m_storage[i])
              return true;
        }

        return false;
      }
      //!@}
      private:
        size_type m_end; //!< Current list size (or index past-last valid element).
        size_type m_capacity; //!< List’s storage capacity.
        T * m_storage; //!< Data storage area for the dynamic array.
    };
} // namespace sc
#endif