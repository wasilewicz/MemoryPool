#include "Stats.h"

void Stats::push(const string& p)
{
    if (string_list.size() == 0)
    {
        string_list.push_back(p);
        amount_list.push_back(1);
        return;
    }
    
    int count = 0;
    
    for(auto i = string_list.begin() ; i != string_list.end() ; ++i)
    {
        if(*i == p)
        {
            amount_list[count]++;
            return ;
        }
        
     count++;   
    }
    
    string_list.push_back(p);
    amount_list.push_back(1);
    
    return;
    
}

void Stats::printStats()
{
    int count = 0;
    for(auto i = string_list.begin() ; i != string_list.end() ; ++i)
    {
        cout<<*i<<" : ";
        
        cout<<amount_list[count]<<endl;
        count ++;
    }
}
