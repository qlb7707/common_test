/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test3.cpp
*   author       :qinlibin
*   create date  :2016/07/10
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "test3.h"
#include<iostream>
#include<regex>
using namespace std;

int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch result;
    string test_str = "receipt freind theif receive";
   /* regex_search(test_str,result,r);
    for(smatch::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout<<it->str()<<endl;
    }*/
    for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it; it != end_it; it++)
    {
        cout<<it->str()<<endl;
    }
}
