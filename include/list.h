#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
using namespace std;
namespace kstl
{
    template <typename T>
    class List
    {
        struct node //자신을 기준으로 이전 및 다음 노드의 주소를 기억하고,실제 데이터를 갖고있음
        {
            node *prev;
            node *next;
            T data;
            node(T data = 0) : data(data)
            {
                prev=next=0;
            }
        };
        node *head; // 가장 앞 노드 
        node *tail; // 가장 끝 노드 
        size_t bSize; // 리스트 사이즈 

    public:
        class Iterator
        {
            node *now; 
            public : Iterator(node *now = 0)
            {
                this->now=now;
            }
            Iterator(const Iterator &iter)
            {
            }
            T operator*()
            {
            }
            operator node *()
            {
            }
            bool operaotr == (const Iterator &iter)
            {
            }
            bool operaotr != (const Iterator &iter)
            {
            }
            Iterator &operator++(void)
            {
            }
            const Iterator operator++(int)
            {
            }
        };
    List()
    {

    }
    ~List()
    {

    }
    void resize(size_t nsize)
    {

    }
    void push_back(T t)
    {

    }
    void insert(Iterator at,T t)
    {

    }
    void erase(Iterator at)
    {

    }
    Iterator begin()
    {

    }
    Iterator end()
    {

    }
    size_t size()
    {

    }
    private:
    void hang_node(node *now,node *pos)
    {

    }
    void dehang_node(node *pos)
    {

    }
    };
};
#endif