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
####指定使用正则表达式时的错误


如果我们编写的正则表达式存在错误，则运行时会抛出一个类型为***regex_error***的异常，***regex_error***有一个**what**操作描述发生了什么错误，还有一个**code**成员返回某个错误类型对应的编码。

####正则表达式类和输入序列类型
#####regex类
regex类保存类型char的正则表达式，wregex类保存类型为**wchar_t**

#####匹配和迭代器类型

类型差异不仅在于字符类型，还在于序列是在string中还是在数组中
- smatch :表示string类型序列
- cmatch :表示字符数组序列
- wsmatch:表示宽字符串（string）序列
- wcmatch:表示宽字符数组

**note: RE库类型必须与输入序列类型匹配**

|序列类型|正则表达式类|
|:---:|:---:|
|string|regex、smatch、ssub\_match、sregex\_iterator|
|const char *|regex、cmatch、csub\_match、cregex\_iterator|
|wstring|wregex、wsmatch、wssub\_match、wsregex\_iterator|
|const wchar_t *|wregex、wcmatch、wcsub\_match、wcregex\_iterator|

###匹配与Regex迭代器类型
**sregex\_iterator 操作：**

|操作|作用|
|:---:|:---:|
|sregex\_iterator it(b,e,r)|一个sregex\_iterator迭代器，遍历b和e表示的string并将it定位到第一个匹配的位置|
|sregex\_iterator end|尾后迭代器|
|*it(it->)|根据最后一个调用regex\_search的结果，返回一个smatch的对象引用或指向smatch的指针|
|it++|从序列当前匹配位置开始调用regex\_search，返回递增后的迭代器|
|it++|从序列当前匹配位置开始调用regex\_search，返回递增前的迭代器|
|it1 == it2(it1 != it2)|如果两个都是尾后迭代器则相等，非尾后迭代器从相同到序列和regex构造则相等|


####使用sregex\_iterator

#####test3--查找所有违反test1中规则的单词



