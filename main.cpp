#include "MemoryPool.h"

using namespace std;


int main(int argc, char** argv) 
{
    
    MemoryPool a(3);
    
    for (auto i = a.pool_list.begin() ; i != a.pool_list.end() ; ++i)
    {
        cout<<*i<<endl;
    }
    
    return 0;
}

