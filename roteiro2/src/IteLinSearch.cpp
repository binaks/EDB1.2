//
//  IteLinSearch.cpp
//  Iterative Linear Search
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include "Search.hpp"

int search(int v[], int size, int key)
{
    int result = NOT_FOUND;

    for(int i = 0; i <= size; i++)
    {
        if( v[i] == key )
        {
            result = i;
            break;
        }
    }
    
    return result;
}
