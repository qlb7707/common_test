/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test1.cpp
*   author       :qinlibin
*   create date  :2016/07/10
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "test1.h"
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
    if(regex_search(test_str,result,r))
        cout<<result.str()<<endl;
}
