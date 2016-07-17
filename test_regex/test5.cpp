/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test5.cpp
*   author       :qinlibin
*   create date  :2016/07/17
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "test5.h"
#include<iostream>
#include<regex>
using namespace std;

int main()
{
    regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$",regex::icase);
    smatch results;
    string filename;
    while(cin>>filename)
    {
        if(regex_search(filename,results,r))
            cout<<results.str(1)<<endl;

    }
}
