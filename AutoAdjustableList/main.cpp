//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include <iostream>
#include <cassert>
#include "TestList.h"

int main(int argc, const char * argv[]) {
    
    assert( test_InsertBegin() );
    assert( test_RemoveBegin() );
    
    assert( test_InsertEnd() );
    assert( test_RemoveEnd() );
    
    assert( test_Search() );
    
    assert( test_Insert() );
    assert( test_Remove() );
    
    assert( test_InsertOrdered() );
    
    assert( test_SearchCF() );
    assert( test_SearchMF() );
    
    std::cout << "Todos testes OK" << std::endl;
    
    return 0;
}
