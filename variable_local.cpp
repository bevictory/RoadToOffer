#include "iostream"
using namespace std;
int returnLocal1()
{
    //ֵ����
    int local =1;
    return local;
}
int *returnLocal2()
{
    //����
    static int local =2;
    return &local;
}
char *returnLocal3(){
    //��һ���ַ���������������ֻ�����ݶ�
    char *str ="hello world";
    return str;
}
char *returnLocal4(){
    //����
    char str[] ="hello world";
    return str;
}

char * returnLocal5()
{
    //����static ���Է��ص�ַ
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
