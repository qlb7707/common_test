/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test.cpp
*   author       :qinlibin
*   create date  :2016/07/02
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "test.h"
#include<iostream>
#include<fstream>
#define ITER 100000
using namespace std;

//write ITER data to file 
//each time open a srteam
void test1()
{
    ofstream ofs;
    for(int i = 0; i < ITER; i++)
    {
        ofs.open("test1.txt",ios::app);
        ofs <<"hello"<<endl;
        ofs.close();
    }
}
//write ITER data to file
//stream only open once
void test2()
{
    ofstream ofs;
    ofs.open("test2.txt");
    for(int i = 0; i < ITER; i++)
    {
        ofs<<"hello"<<endl;
    }
    ofs.close();
}

int main()
{
    time_t st1,st2,ed1,ed2;
    st1 = clock();
    test1();
    ed1 = clock();
    st2 = clock();
    test2();
    ed2 = clock();
    cout<< 1.0*(ed1-st1)/CLOCKS_PER_SEC <<","<<1.0*(ed2 - st2)/CLOCKS_PER_SEC<<","<<CLOCKS_PER_SEC<<endl;
}
