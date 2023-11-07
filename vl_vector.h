#include <iostream>
#define DEF_CAP 16


template<class T, size_t StaticCapacity = DEF_CAP>
class vl_vector {

  size_t my_capacity;
  size_t const_cap =    StaticCapacity;
  size_t current;
  T *alloc_array;
  T array[StaticCapacity];
  size_t get_bigger(size_t size,size_t k);






 public:
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef std::reverse_iterator <const_iterator> const_reverse_iterator;
  using reverse_iterator = std::reverse_iterator <iterator>;

  iterator begin ()
  {
    return data ();
  }

  const_iterator begin () const
  {
    return data ();
  }

  const_iterator cbegin () const{
    return data ();
  }

  iterator end ()
  {
    return data () + current;
  }
  const_iterator end () const
  {
    return data () + current;
  }
  const_iterator cend () const
  {
    return data() + current;
  }


  reverse_iterator rbegin(){
    return reverse_iterator (data() + current);
  }

  const_reverse_iterator rbegin () const{
    return const_reverse_iterator (data () +current);
  }

  const_reverse_iterator crbegin () const{
    return const_reverse_iterator (data () +current);
  }

  reverse_iterator rend(){
    return reverse_iterator (data ());
  }

  const_reverse_iterator rend () const{
    return const_reverse_iterator (data ());
  }

  const_reverse_iterator crend () const{
    return const_reverse_iterator (data ());
  }






  vl_vector ();
  vl_vector (vl_vector const &v);
  vl_vector(int count, T const &element);
  template<class InputIterator>
  vl_vector(InputIterator first, InputIterator last);
  ~vl_vector();



  T *data ();
  const T *data() const;
  size_t size ();
  size_t capacity ();
  T at (int inx);
  T at (int inx) const;

  bool empty ();
  bool contains(T element);
  void push_back(T element);
  void pop_back();
  void clear();
  iterator insert(iterator position, const T &element);
  iterator erase(iterator position);
  template<class InputIterator>
  iterator erase(InputIterator first, InputIterator last);
  template<class InputIterator>
  iterator insert(iterator position,InputIterator first, InputIterator last);


  T &operator[](const int &ind);
  const T &operator[](const int &ind) const;
  vl_vector<T,StaticCapacity> &operator=
      (const vl_vector<T,StaticCapacity> &vec);
  bool operator==(const vl_vector<T,StaticCapacity> &vec);
  bool operator!=(const vl_vector<T,StaticCapacity> &vec);
};


/**
 * Default constructor
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 */
template<class T, size_t StaticCapacity>
vl_vector<T, StaticCapacity>::vl_vector (){
  this->my_capacity = StaticCapacity;
  const_cap = StaticCapacity;
  this->current = 0;
  alloc_array = nullptr;

}
/**
 * copy constructor
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param v array to copy from
 */
template<class T, size_t StaticCapacity>
vl_vector<T, StaticCapacity>::vl_vector(const vl_vector &v)

{
  current = v.current;
  const_cap =v.const_cap;
  my_capacity = v.my_capacity;
  if (v.current <= StaticCapacity)
    {
      std::copy(v.begin(), v.end(), begin ());
      return;
    }
  T *n_array = new T[v.my_capacity];
  {
    std::copy (v.begin(),  v.end(), n_array);
    this->alloc_array = n_array;
    return;
  }
}

/**
 * constructor array with T elements, length of count
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param count number of time to insert T
 * @param element element
 */
template<class T, size_t StaticCapacity>
vl_vector<T, StaticCapacity>::vl_vector (int count, const T &element)
{
  if ((size_t)count > const_cap){
      my_capacity = get_bigger (0,count);
      T *n_array = new T[my_capacity];
      for(int i =0; i<count; i++) {
          n_array[i] = element; }
      alloc_array = n_array;
      current = count;
    }

  else{
      this->my_capacity = const_cap;
      for (int i = 0; i<count; i++){
          array[i] = element;
        }
      alloc_array= nullptr;
      current = count;
    }
}

/**
 * constructor array with element from first input to last input
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @tparam InputIterator iterator
 * @param first first element to insert
 * @param last last element to insert
 */
template<class T, size_t StaticCapacity>
template<class InputIterator>
vl_vector<T, StaticCapacity>::vl_vector
    (InputIterator first, InputIterator last)
{
  current = 0;
  my_capacity = StaticCapacity;
  size_t dist = std::distance (first,last); // todo???
  if(dist > const_cap){
      my_capacity = get_bigger (0,dist);
      T *n_array = new T[my_capacity];
      std::copy (first,last,alloc_array);
      alloc_array = n_array;
      current = dist;
      const_cap = StaticCapacity;
    }

  else{
      std::copy(first,last,array);
      this->current = dist;
      this->alloc_array = nullptr;
      this->my_capacity = const_cap;
    }
}

/**
 * distructor
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 */
template<class T, size_t StaticCapacity>
vl_vector<T, StaticCapacity>::~vl_vector (){
  if (my_capacity > StaticCapacity){
      delete[] alloc_array;
    }
}
/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @return number of current elements in the array
 */
template<class T, size_t StaticCapacity>
size_t vl_vector<T, StaticCapacity>::size ()
{
  return current;
}
/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @return the capacity of the array
 */
template<class T, size_t StaticCapacity>
size_t vl_vector<T, StaticCapacity>::capacity ()
{
  return this->my_capacity;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @return if the array is empty
 */
template<class T, size_t StaticCapacity>
bool vl_vector<T, StaticCapacity>::empty ()
{
  return size () == 0;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param inx index
 * @return the element in the index
 */
template<class T, size_t StaticCapacity>
T vl_vector<T, StaticCapacity>::at (int inx)
{
  if ((size_t)inx >= current || (size_t)inx < 0) {
      throw std::out_of_range ("index out of range");
    }
  if (this->current <= StaticCapacity){
      return this->array[inx];
    }
  return this->alloc_array[inx];
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @return the array itself
 */
template<class T, size_t StaticCapacity>
T *vl_vector<T, StaticCapacity>::data ()
{
  if (current <= StaticCapacity)
    {
      return array;
    }
  return alloc_array;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @return the array itself
 */
template<class T, size_t StaticCapacity>
const T *vl_vector<T, StaticCapacity>::data () const
{
  if (current <= StaticCapacity)
    {
      return array;
    }
  return &alloc_array[0];
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param element specific element
 * @return if the element is in the array
 */
template<class T, size_t StaticCapacity>
bool vl_vector<T, StaticCapacity>::contains (T element)
{
  if (current <= StaticCapacity){
      for (size_t i =0; i<current; i++){
          if (array[i] == element){ return true;}
        }
      return false;
    }
  for (size_t i =0; i<current; i++){
      if (alloc_array[i] == element){ return true;}
    }
  return false;
}

/**
 * the array insert element to the last place
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param element element to push
 */
template<class T, size_t StaticCapacity>
void vl_vector<T, StaticCapacity>::push_back (T element)
{
  insert (end(),element);
}

 /**
  * size bigger the capacity
  * @tparam T element type for array
  * @tparam StaticCapacity const capacity
  * @param size current element in the array
  * @param k number of element to insert
  * @return new capacity
  */
template<class T, size_t StaticCapacity>
size_t vl_vector<T, StaticCapacity>::get_bigger (size_t size, size_t k)
{ return (3 *(size+k))/2;}



/**
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param ind index
 * @return the element in the index
 */
template<class T, size_t StaticCapacity>
T &
vl_vector<T, StaticCapacity>::operator[] (const int &ind){
  if (my_capacity <= StaticCapacity){
      return  array[ind];
    }
  else{
      return alloc_array[ind];
    }
}

/**
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param ind index
 * @return the element in the index
 */
template<class T, size_t StaticCapacity>
const T &
vl_vector<T, StaticCapacity>::operator[] (const int &ind) const{
  if (my_capacity <= StaticCapacity){
      return  array[ind];
    }
  else{
      return alloc_array[ind];
    }
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param vec another array
 * @return if given array is equal to current array
 */
template<class T, size_t StaticCapacity>
bool
vl_vector<T, StaticCapacity>::operator==
    (const vl_vector<T, StaticCapacity> &vec)
{
  if (current == 0 && vec.current == 0){return true;}
  if(my_capacity == vec.my_capacity && current == vec.current){
      for (size_t i =0; i<current; i++){
          if (data()[i]==vec.data()[i]){continue;}
          else {return false;}
        }
      if (current != 0 ) {return true;}
    }
  return false;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param vec another array
 * @return if given array is different to current array
 */
template<class T, size_t StaticCapacity>
bool
vl_vector<T, StaticCapacity>::operator!=
    (const vl_vector<T, StaticCapacity> &vec)
{
  if(my_capacity != vec.my_capacity || current != vec.current){
      for (size_t i =0; i<current; i++){
          if (data()[i]==vec.data()[i]){continue;}
          else {return true;}
        }
      return false;
    }
  return true;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param position place to insert the element
 * @param element element to insert
 * @return  iterator before we put the new element
 */
template<class T, size_t StaticCapacity>
typename vl_vector<T,StaticCapacity>::iterator
vl_vector<T, StaticCapacity>::insert
    (vl_vector::iterator position, const T &element)
{
  int indx = std::distance (begin(),position);
  if (current +1 <= const_cap){
      T *insert = current + array;
      while (insert != position){
          *(insert) = *(insert-1);
          insert--;
        }
      array[indx] = element;
      current++;
      return position;
    }

  if(current +1 > const_cap && current == const_cap){
      my_capacity = get_bigger (current,1);
      T *n_array = new T[my_capacity];
      this->alloc_array = n_array;
      std::copy (begin(),position,alloc_array);
      alloc_array[indx] = element;
      std::copy (position,end(),alloc_array+(1+indx));
      current++;


      return position;
    }

  if (current == my_capacity && current > const_cap){
      my_capacity = get_bigger (current,1);
      T *n_array = new T[my_capacity];
      std::copy (begin(),position,n_array);
      n_array[indx] = element;
      std::copy (position,end(),n_array+(1+indx));
      delete[] alloc_array;
      this->alloc_array = n_array;
      current++;

      return position;
    }
  else{
      T *n_array = new T[my_capacity];
      std::copy (begin(),position,n_array);
      n_array[indx] = element;
      std::copy (position,end(),n_array+(1+indx));
      delete[] alloc_array;
      this->alloc_array = n_array;
      current++;

      return position;
    }
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @tparam InputIterator iterator
 * @param position from where to put the elements
 * @param first first element to put
 * @param last last element to put
 * @return iterator before we put the new element
 */
template<class T, size_t StaticCapacity>
template<class InputIterator>
typename vl_vector<T, StaticCapacity>::iterator
vl_vector<T, StaticCapacity>::insert
    (vl_vector::iterator position, InputIterator first, InputIterator last)
{
  size_t dist = std::distance (begin(),position);
  size_t add = std::distance (first, last);
  size_t new_my_capacity = get_bigger (current,add);
  size_t new_current = add + current;

  if (new_current > const_cap && const_cap >= current){
      T *n_array = new T[new_my_capacity];
      this->alloc_array = n_array;
      std::copy (begin(),position,alloc_array);
      std::copy (first,last,alloc_array+dist);
      std::copy(begin()+dist, end(), alloc_array +dist+add);
      this->current = new_current;
      this->my_capacity = new_my_capacity;
      return alloc_array+dist;
    }


  if (current > const_cap && new_current > const_cap){
      T *n_array = new T[new_my_capacity];
      std::copy (begin(),position,n_array);
      std::copy (first,last, n_array+dist);
      std::copy(begin()+dist,end(),dist+n_array+add);
      delete[] alloc_array;
      this->alloc_array = n_array;
      this->current = new_current;

      if (my_capacity < new_current){
          this->my_capacity = new_my_capacity;
        }
      return alloc_array+dist;
    }

  if(const_cap >= new_current){
      std::copy (first,last,position);
      std::copy (position,end(),add+position);
      this->my_capacity = new_my_capacity;
      this->current = new_current;
      return position;
    }

  return position;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @tparam InputIterator iterator
 * @param first first element to erase
 * @param last last element to erase
 * @return iterator
 */
template<class T, size_t StaticCapacity>
template<class InputIterator>
typename vl_vector<T, StaticCapacity>::iterator
vl_vector<T, StaticCapacity>::erase (InputIterator first, InputIterator last)
{

  size_t subtract = std::distance (first,last);
  size_t after_sub = std::distance (begin(),first);
  size_t new_cap = subtract + const_cap;
  if (end() != last){
      std::copy(begin(), first, array);
      std::copy(last , end(), array + after_sub);
      this->current -= subtract;
      this->my_capacity = const_cap;
      delete[] alloc_array;
      this->alloc_array = nullptr;
      return array + after_sub;
    }

  if (current> new_cap || new_cap>= current){
      std::copy (last,end(),first);
      this->current -= subtract;
      return first;
    }

  std::copy (begin(),first,array);
  this->current -= subtract;
  this->my_capacity = const_cap;
  delete[] alloc_array;
  this->alloc_array = nullptr;
  return array+after_sub;
}



/**
 * erase element
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param position where to erase
 * @return iterator
 */
template<class T, size_t StaticCapacity>
typename vl_vector<T,StaticCapacity>::iterator
vl_vector<T, StaticCapacity>::erase(vl_vector::iterator position)
{
  int indx = std::distance (begin(),position);
  if(current > 0){
      if(current <= const_cap || current -1 > const_cap){
          if (position+1 != end()){
              std::copy (1+position,end(),position);
            }
          current--;
          return position;
        }

      if(position +1 != end()){
          std::copy (begin(), position, array);
          std::copy (position+1, end(), indx + array);
          delete[] alloc_array;
          this->alloc_array = nullptr;
          this->my_capacity = const_cap;
          current--;
          return indx + array;
        }

      else{
          std::copy (begin(),position,array);
          delete[] alloc_array;
          this->alloc_array = nullptr;
          this->my_capacity = const_cap;
          current--;
          return current + array;
        }
    }
  return nullptr;
}

/**
 * take out last element
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 */
template<class T, size_t StaticCapacity>
void vl_vector<T, StaticCapacity>::pop_back()
{
  if (current != 0){
      erase (end()-1);
    }
}
/**
 * clear array
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 */
template<class T, size_t StaticCapacity>
void vl_vector<T, StaticCapacity>::clear()
{
  size_t tem_curr = current;
  for(size_t i = 0; i<tem_curr; i++){
      pop_back();
    }
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param vec another array
 * @return the current array after assigment
 */
template<class T, size_t StaticCapacity>
vl_vector<T, StaticCapacity> &
vl_vector<T, StaticCapacity>::operator=
    (const vl_vector<T, StaticCapacity> &vec)
{
  if (this == &vec){
      return *this;
    }
  size_t new_current = vec.current;
  size_t new_cons_cap = vec.const_cap;
  this->clear();

  if (new_current>new_cons_cap){
      T *n_array = new T[vec.my_capacity];
      for (size_t i =0; i<new_current; i++){
          n_array[i] = vec.alloc_array[i];
        }
      this->alloc_array = n_array;
      this->current = vec.current;
      this->my_capacity = vec.my_capacity;
    }
  else{
      for (size_t i =0; i<new_current; i++){
          array[i] = vec.array[i];
        }
      this->alloc_array = nullptr;
      this->current = vec.current;
      this->my_capacity = vec.my_capacity;

    }
  return *this;
}

/**
 *
 * @tparam T element type for array
 * @tparam StaticCapacity const capacity
 * @param inx index
 * @return the element in the index
 */
template<class T, size_t StaticCapacity>
T vl_vector<T, StaticCapacity>::at (int inx) const
{
  if ((size_t)inx >= current || (size_t)inx < 0) {
      throw std::out_of_range ("index out of range");
    }
  if (this->current <= StaticCapacity){
      return this->array[inx];
    }
  return this->alloc_array[inx];
}

