/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test7.cpp
*   author       :qinlibin
*   create date  :2016/07/18
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<fstream>
#include<regex>
using namespace std;
using namespace std::regex_constants;
int main()
{
    ifstream ifs;
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
    string fmt = "$2.$5.$7";
    regex r(phone);
    ifs.open("test7.txt");
    if(!ifs)
    {
        cout<<"test7.txt open error"<<endl;
        return -1;
    }
    string line;
    while(getline(ifs,line))
    {
        cout<<regex_replace(line,r,fmt,format_first_only)<<endl;
    }
    return 0;

}
