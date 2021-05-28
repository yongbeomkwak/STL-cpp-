#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>
using namespace std;
namespace kstl
{
    template <typename T>
    class List
    {
        struct node
        {
            node *prev;
            node *next;
            T data;
            node(T data = 0) : data(data)
            {
            
            }
        };
        node *head;
        node *tail;
        size_t bSize;

    public:
        class Iterator
        {
            node *now; 
            public : Iterator(node *now = 0)
            {

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