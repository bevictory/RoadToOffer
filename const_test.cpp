#include "iostream"
using namespace std;
int main()
{
    //常量指针 p
    const int *p;
    const int pp=5;
    *p=1;
    const int a ;
    int b=1;
    p=&b;
    //指针常量 aa，
    int *const aa ;
    int *const bb =&b ;
    bb=&a;


}
