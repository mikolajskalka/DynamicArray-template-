#include <iostream>
#include <string>
#include "dynamicarray.hpp"

int main(){

    // DynamicArray<double> da(10);
    // DynamicArray<double> da1;
    // da.setElem(4, 12.123);
    // std::cout << da << std::endl;
    // std::cout << std::endl;
    // da.size();
    // std::cout << std::endl;
    // std::cout << da[3] << std::endl;
    // da[3] = 5.1;
    // std::cout << std::endl;
    // std::cout << da[3] << std::endl;
    // for(auto i = da.begin(); i != da.end(); ++i){
        // std::cout << *i << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;
    // da.push_back(6.);
    // std::cout << da << std::endl;
    // da.pop_back();
    // std::cout << da << std::endl;
    // DynamicArray<int>::iterator* iter;
    // std::cout <<  << std::endl;
    const DynamicArray<int> da(10);
    //da.setElem(4, 5);
    for(auto i = da.begin(); i != da.end(); ++i){
        std::cout << *i << ", ";
    }

    // da.begin() = 0;
    std::cout << std::endl;



    return 0;
}