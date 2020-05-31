#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <cstdint>

template <typename T>
class DynamicArray
{
    std::size_t size_;
    T* t_;

public:
    class iterator{
                
        T* it;


        public:
        explicit iterator(T*);

        bool operator==(const iterator&);
        bool operator!=(const iterator&);
        iterator& operator++();
        const iterator operator++(int);
        T& operator*();
        T* operator->();
    };

    class const_iterator{
               
       const T* it;


       public:
       explicit const_iterator(const T*);

       bool operator==(const const_iterator&);
       bool operator!=(const const_iterator&);
       const const_iterator& operator++();
       const const_iterator operator++(int);
       const T& operator*();
       const T* operator->();
    };

public:
    explicit DynamicArray();                            //Constructor
    explicit DynamicArray(std::size_t n);               //Constructor
    DynamicArray(const DynamicArray&);			        //Copy assignment constructor       	
	DynamicArray& operator=(const DynamicArray&);       //Copy assignment operator
	DynamicArray(DynamicArray&&);				        //Move constructor
	DynamicArray& operator=(DynamicArray&&);	        //Move assignment operator  
    ~DynamicArray();                                    //Destructor

    template <typename T2>friend std::ostream& operator<<(std::ostream& output, const DynamicArray<T2>&);

    T& operator[](std::size_t i);

    void setElem(std::size_t i, T value);
    T getElem(std::size_t i) const;
    std::size_t size() const;
    
    void push_back(T);
    void pop_back();
    
    
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};


//Constructors
template <typename T>
DynamicArray<T>::DynamicArray(): size_(0u), t_(nullptr) {
    //std::cout << "Constructor" << std::endl;
}
template <typename T>
DynamicArray<T>::DynamicArray(std::size_t n): size_(n), t_(new T[n]) {
    //std::cout << "Constructor" << std::endl;    
}

//Copy constructor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& source): size_(source.size_), t_(new T(source.size_)) {
    size_ = source.size_;
    for(std::size_t i = 0; i < size_; ++i){
        t_[i] = source.t_[i];
    }
}

//Copy assignment operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& source){
    if(this != &source){
        delete[] t_;
        size_ = source.size_;
        t_ = new T(size_);
        for(std::size_t i = 0; i < size_; ++i){
            t_[i] = source.t_[i];
        }
    }
    return *this;
}

//Move constructor
template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& source): size_(source.size_), t_(source.t_){
    source.size_ = 0;
    source.t_ = nullptr;
}

//Move assignment operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& source){
    if(this != &source){
        delete[] t_;
        size_ = source.size_;
        t_ = new T(size_);
        for(std::size_t i = 0; i < size_; ++i){
            t_[i] = source.t_[i];
        }
    }
    source.size_ = 0;
    source.t_ = nullptr;
    return *this;
}

//Destructor
template <typename T>
DynamicArray<T>::~DynamicArray(){
    //std::cout << "Destructor" << std::endl; 
    delete [] t_;
}


/* ITERATOR */

template <typename T>
DynamicArray<T>::iterator::iterator(T *da): it(da){}

template <typename T>
bool DynamicArray<T>::iterator::operator==(const iterator& iter) {
    return it == iter.it;
}

template <typename T>
bool DynamicArray<T>::iterator::operator!=(const iterator& iter) {
    return it != iter.it;
}

template <typename T>
typename DynamicArray<T>::iterator& DynamicArray<T>::iterator::operator++(){
    it += 1;
    return *this;    
}

template <typename T>
const typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator++(int){
    DynamicArray::iterator tmp = *this;
    ++*this;
    return tmp;    
}

template <typename T>
T& DynamicArray<T>::iterator::operator*(){
    return *it;
}

template <typename T>
T* DynamicArray<T>::iterator::operator->(){
    return it;
}

template <typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin(){
    return iterator(t_);
}
template <typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::end(){
    return iterator(t_ + size_);
}


template <typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::begin(){
    return iterator(t_);
}
template <typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::end(){
    return iterator(t_ + size_);
}


/* CONST ITERATOR */


template <typename T>
DynamicArray<T>::const_iterator::const_iterator(const T *da): it(da){}

template <typename T>
bool DynamicArray<T>::const_iterator::operator==(const const_iterator& iter) {
    return it == iter.it;
}

template <typename T>
bool DynamicArray<T>::const_iterator::operator!=(const const_iterator& iter) {
    return it != iter.it;
}

template <typename T>
const typename DynamicArray<T>::const_iterator& DynamicArray<T>::const_iterator::operator++(){
    it += 1;
    return *this;    
}

template <typename T>
const typename DynamicArray<T>::const_iterator DynamicArray<T>::const_iterator::operator++(int){
    DynamicArray::const_iterator tmp = *this;
    ++*this;
    return tmp;    
}

template <typename T>
const T& DynamicArray<T>::const_iterator::operator*(){
    return *it;
}

template <typename T>
const T* DynamicArray<T>::const_iterator::operator->(){
    return it;
}
// 
template <typename T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::begin() const{
    return const_iterator(t_);
}
template <typename T>
typename DynamicArray<T>::const_iterator DynamicArray<T>::end() const{
    return const_iterator(t_ + size_);
}


//Przeładowany operator wyjścia

template <typename T>
std::ostream& operator<<(std::ostream& output, const DynamicArray<T>& source){
    for(std::size_t i = 0; i < source.size_; ++i){
        if(i != (source.size_ - 1)){
            std::cout << source.t_[i] << ", ";
        }
        else {
            std::cout << source.t_[i];
        }
    }
    return output;
}


/* Funkcje składowe */

//Przeładowany operator []

template <typename T>
T& DynamicArray<T>::operator[](std::size_t i){
    return t_[i];
}

template <typename T>
void DynamicArray<T>::setElem(std::size_t i, T value){
    t_[i] = value;
}

template <typename T>
T DynamicArray<T>::getElem(std::size_t i) const{
    std::cout << t_[i] << " ";
    return t_[i];
}

template <typename T>
std::size_t DynamicArray<T>::size() const{
    // std::cout << size_ << std::endl;
    return size_;
}

template <typename T>
void DynamicArray<T>::push_back(T x){
    std::size_t i;
    DynamicArray new_da(size_+1);
    for(i = 0u; i < size_; ++i){
        new_da.t_[i] = t_[i];
    }
    new_da.t_[size_] = x;
    *this = new_da;
}

template <typename T>
void DynamicArray<T>::pop_back(){
    std::size_t i;
    DynamicArray new_da(size_ - 1);
    for(i = 0u; i < size_ - 1; ++i){
        new_da.t_[i] = t_[i];
    }
    *this = new_da;
}

#endif // DYNAMICARRAY_H