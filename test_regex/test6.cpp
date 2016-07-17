/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test6.cpp
*   author       :qinlibin
*   create date  :2016/07/17
*   mail         :qin_libin@foxmail.com
*
================================================================*/

#include<iostream>
#include<regex>
using namespace std;

bool valid(const smatch &m)
{
    if(m[1].matched)
        return m[3].matched && (m[4].matched == false || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();

}



int main()
{
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";

    regex r(phone);
    string s;
    while(getline(cin,s))
    {
        for(sregex_iterator it(s.begin(),s.end(),r),end_it; it != end_it; it++)
        {
            if(valid(*it))
                cout<<"valid:"<<it->str()<<endl;
            else
                cout<<"invalid:"<<it->str()<<endl;
        }
    }

    return 0;
}
