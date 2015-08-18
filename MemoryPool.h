#ifndef MEMORYPOOL_H
#define	MEMORYPOOL_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

class MemoryPool 
{
public:
    vector<string*>pool_list;
    int list_length;
    int filled;
    int free;
    
    vector<string*>deleted;
    
    
    MemoryPool(int size);
    string* allocate();
    bool deallocate(string *ptr);
    void write_stats();
    ~MemoryPool();
    


};

#endif	/* MEMORYPOOL_H */

