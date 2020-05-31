# Dynamic array class template

This is my implementation of dynamic array template in C++.

It is supposed to work exactly as \<vector\> template.

It is not finished. Still have to add const iterators, and few more fetures.

## Use and features

Template contains two private fields, defining size of an array, and a pointer to dynamicly allocated array of objects.

### Template has defined:

* constructor,
* copy constructor,
* copy assignment operator,
* move constructor,
* move assignment operator,
* destructor

### Methods and overloaded operators:

* output operator,
* operator[],
* getElem(),
* setElem(),
* size(),
* push_back(),
* pop_back(),
* begin(),
* end().