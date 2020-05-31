# Dynamic array class template

This is my implementation of dynamic array template in C++.

It is supposed to work exactly as \<vector\> template, but was made on my C++ classes, so please don't be too certain about it.

It is not finished. Still have to add few more fetures.

## Use and features

Template contains two private fields, defining size of an array, and a pointer to dynamicly allocated array of objects. It has iterator, as well as const iterator.

### Template has defined:

* constructor,
* copy constructor,
* copy assignment operator,
* move constructor,
* move assignment operator,
* destructor

### Methods and overloaded operators:

* output operator \<\<,
* operator[],
* getElem(),
* setElem(),
* size(),
* push_back(),
* pop_back(),
* begin(),
* end().
