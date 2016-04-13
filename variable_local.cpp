#include "iostream"
using namespace std;
int returnLocal1()
{
    //值拷贝
    int local =1;
    return local;
}
int *returnLocal2()
{
    //错误
    static int local =2;
    return &local;
}
char *returnLocal3(){
    //是一个字符串常量，储存在只读数据段
    char *str ="hello world";
    return str;
}
char *returnLocal4(){
    //错误
    char str[] ="hello world";
    return str;
}

char * returnLocal5()
{
    //加入static 可以返回地址
     static char str[] ="hello world";
    return str;

}
int main()
{
    int local1= returnLocal1();
    cout<<local1<<endl;

    int *local2= returnLocal2();
    cout<<*local2<<endl;

    char *str = returnLocal5();
    cout<<str<<endl;


}
