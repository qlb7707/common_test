/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test4.cpp
*   author       :qinlibin
*   create date  :2016/07/13
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "test4.h"
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
    for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it; it != end_it; it++)
    {
        auto pos = it->prefix().length();
        pos = pos > 40? pos - 40 : 0;
        cout<<it->prefix().str().substr(pos)
            <<"\n\t\t>>> "<< it->str()<<" <<<\n"
            <<it->suffix().str().substr(0,40)
            <<endl;
    }
}
