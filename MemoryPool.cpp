
#include "MemoryPool.h"

using namespace std;

void MemoryPool::write_stats()
{
    cout<<"filled: "<<filled<<endl;
    cout<<"free: "<<free<<endl;
    cout<<"list length: "<<list_length<<endl;
}

MemoryPool::MemoryPool(int size) 
{
    for(int i=0;i<size;i++)
    {
        pool_list.push_back(new string);
    }
    
    cout<<"####created memory pool###"<<endl;
    
    for(auto i = pool_list.begin(); i!=pool_list.end(); ++i)
       cout<<*i<<endl;
    list_length = pool_list.size();
    filled = 0;
    free=list_length;
    
    cout<<"##############"<<endl;
}

string* MemoryPool::allocate()
{
    if(deleted.size() > 0)
    {
        cout<<"added from deleted"<<endl;
        pool_list.push_back(deleted[deleted.size()-1]);
        filled++;
        list_length++;
        deleted.pop_back();
        return pool_list[pool_list.size()-1];
    }
     
    if(free>0)
    {
        int count = 0;
        for(auto i = pool_list.begin() ; i != pool_list.end() ; ++i)
        {
            if(count == filled)
            {
                filled++;
                free--;
                return *i;
            }
            count++;
        }
    }
    
    if(free <= 0)
    {
        cout<<"Too small pool, created new pointer"<<endl;
        pool_list.push_back(new string);
        list_length++;
        filled++;  
        int _count = 0;
        for(auto i = pool_list.begin() ; i != pool_list.end() ; ++i)
        {
            if(_count == filled)
            {
                
                return *i;
            }
            _count++;
        }
    }
}

bool MemoryPool::deallocate(string* ptr)
{
    int count = 0;
    for (auto i = pool_list.begin() ; i != pool_list.end() ; ++i)
    {
        if(ptr == *i)
        {
            list_length--;
            filled--;
            deleted.push_back(ptr);
            ptr = nullptr;
            pool_list.erase(pool_list.begin() + count);
            cout<<"deallocated"<<endl;
            return true;
        }
        count++;
    }
    cout<<"usuwanie sie nie udalo"<<endl;
    return false;
    
    
}


MemoryPool::~MemoryPool()
{
    for(auto i = pool_list.begin() ; i != pool_list.end() ; ++i)
    {
        delete *i;
        *i = nullptr;
    }
}


