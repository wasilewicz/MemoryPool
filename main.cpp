#include "MemoryPool.h"
#include "Stats.h"

using namespace std;


int main(int argc, char** argv) 
{
    Stats a;
    
    a.push("asdsaf");
    a.push("safdsaf");
    a.push("asdsaf");
    a.push("asdsafdskflkdsf");
    a.push("asdsaf");
    
    a.printStats();
    
    return 0;
}

