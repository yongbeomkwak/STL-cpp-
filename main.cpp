#include <iostream>
#include <vector.h>
using namespace std;
using namespace kvector;
int main(int, char**) {
    Vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // 2 3 4
    cout << v[0] << " " <<v[1] <<" " <<v[2] <<endl;
    Vector<int>::Iterator it=v.begin();
    cout << *it <<endl; //2 
    cout << *(it+1)<<endl;   //3
    cout << *(it+2)<<endl;   //4 
    ++it;
    it++;// 4
    cout << *it <<endl; 




}
