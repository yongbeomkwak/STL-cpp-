#include <iostream>
#include <vector.h>
#include <list.h>
#include <stack.h>
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
    // List<char> li;
    // li.push_back('A');
    // li.push_back('B');
    // li.push_back('C');
    // li.push_back('E');
    // li.push_back('F');
    // printf("%d\n", li.size()); //5 
    // List<char>::Iterator it = li.begin();
    // for (size_t i = 0; i < li.size(); i++)
    // {
    //     cout << *it << endl;
    //     if (i == 3) // it가 E를 가르킬 때 D 넣음 , E 앞에 D를 넣음
    //     {
    //         li.insert(it, 'D');
    //     }
    //     it++;
    // }
    // // A B C E F
    // cout << "##########" << endl;
    // printf("%d\n", li.size()); //6
    // List<char>::Iterator itt = li.begin();
    // for (size_t i = 0; i < li.size(); i++)
    // {
    //     cout << *itt << endl;
    //     itt++;
    // }
    // // A B C D E F
    Pstack Stack=createStack();
    push(Stack,0);
    push(Stack,1);
    push(Stack,2);
    push(Stack,3);
    for(int i=size(Stack);i>0;i--)
    {
        cout << pop(Stack) <<endl;
    }

}
