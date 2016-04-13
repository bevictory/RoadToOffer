#include "iostream"
using namespace std;
class exam{
private:
    int a;int b;
public:
    exam(){};
    exam(int a, int b):a(a),b(b){
    }
    int getA();
    void setA(int aa);
};
int exam::getA(){
    return a;
}
void exam::setA(int aa ){
    a=aa;
}
class CCopyTest
{
public:
	CCopyTest(int _size):size(_size){data=new int[size];}
	~CCopyTest(void){delete []data;}

	CCopyTest(const CCopyTest& _copy):size(_copy.size)
	{
	    data=new int[size];
	    memcpy(data,_copy.data,size);
    }//自定义拷贝构造函数

private:
	int size;
	int* data;
};
int main()
{
     exam aa;
     exam *a = new exam(2,3);
     a->setA(3);
     exam *b = a;
     cout<<b->getA();
}
