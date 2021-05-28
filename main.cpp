#include <iostream>
#include <vector.h>
using namespace std;
using namespace kstl;
int main(int, char **)
{
    // Vector<int> v;
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // // 2 3 4
    // cout << v[0] << " " << v[1] << " " << v[2] << endl;
    // Vector<int>::Iterator it = v.begin();
    // Vector<int>::Iterator e_it = v.end();
    // cout << *it << endl; //2
    // cout << (it != e_it) << endl;
    // cout << *(it + 1) << endl; //3
    // cout << *(it + 2) << endl; //4

    // ++it;
    // it++; // 4
    // cout << (it == e_it) << endl; // 거짓 0 
    // cout << (it != e_it) << endl; // 참 1
    // it++; //end
    // cout << (it == e_it) << endl; //참 1
    // cout << (it != e_it) << endl; //거짓

    int num_1=111;
    int *p=&num_1;
    int &ref1=*p;
    int *(&ref2)=p;
    int q=*p;
    printf("%d\n",&num_1);//1794783004
    printf("%d\n",p);//1794783004
    printf("%d\n",&ref1);//1794783004
    printf("%d\n",ref2);///1794783004
    
    printf("%d\n",&q);//1794782972
    printf("%d\n",&ref2);//1794782992
    cout << "=========="<<endl;
    printf("%d\n",num_1); //111
    printf("%d\n",*p);//111
    printf("%d\n",ref1);//111
    printf("%d\n",*ref2);//111
    printf("%d\n",q);//111
}
