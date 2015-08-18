#ifndef STATS_H
#define	STATS_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Stats 
{
public:
    void push(const string &p);
    void printStats();
    vector<string>string_list;
    vector<int>amount_list;
};

#endif	/* STATS_H */

