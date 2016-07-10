#C++正则表达式regex

##basic 
**头文件**---regex

###组件
|组件|作用|
|:---:|:----:|
|regex|表示有一个正则表达式的类|
|regex\_match|将一个字符序列与一个正则表达式匹配|
|regex\_search|寻找第一个与正则表达式匹配的子序列|
|regex\_replcace|使用给定的格式匹配一个正则表达式|
|sregex\_iterator|迭代器适配器，调用regex\_search遍历string中所有匹配的子串|
|smatch|容器类，保存在string中搜索的结果|
|ssub\_match|string中匹配的子表达式结果|

**regex\_search & regex\_match 参数**

- seq,m,r,mft（字符序列，match对象---必须与seq兼容，regex对象，flag）
- seq,r,mft（同上）

###使用正则表达式库
####test1---查找违法拼写规则“i除非在c后否则必须在e前”的单词

```
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
```

####指定regex对象的选项

**用法: regex r(re),regex r(re,f), r1 = re, r1.assign(re,f)**

|flag|function|
|:---:|:---:|
|icase|忽略大小写|
|nosubs|不保存匹配的子表达式|
|optimize|执行速度优先于构造速度|
|ECMAScript|使用ECMA-262指定语法|
|basic|使用posix基本的正则表达式语法|
|extended|使用posix扩展的正则表达式语法|
|awk|使用posix版本的awk语言的语法|
|grep|使用posix版本的grep语法|
|egrep|使用posix版本的egrep语法|

####test2---匹配指定后缀的文件名字

```
#include<iostream>
#include<regex>
using namespace std;

int main()
{
    //注意下面到反斜杠
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$",regex::icase);
    smatch results;
    string filename;
    while(cin>>filename)
    {
        if(regex_search(filename,results,r))
            cout<<results.str()<<endl;

    }
}
```



