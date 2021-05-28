#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
using namespace std;
namespace kstl{
    template<typename T=int>
    class Vector{
        T * base; //요소를 보관할 저장소
        size_t bSize; // 보관된 요소 개수 
        size_t bCapacity; //저장소의 용량 
        public:
        class Iterator{ //Nested Class
            T *pos; //요소가 보관된 위치 
            public:
                Iterator(T *pos);
                T operator *(void){
                    return *pos;
                } //해당 위치에 대한 저장값 반환 연산자
                int operator -(const Iterator &iter){
                }
                Iterator &operator ++(void){//forward operator
    
                }
                const Iterator operator ++(int);
                bool operator !=(const Iterator &iter);
                bool operator ==(const Iterator &iter);
        };
        Vecotr();
        Vecotr(size_t init_cnt,T t);
        ~Vecotr();
        void push_back(size_t cnt,T t);
        void push_back(T t);
        void reserve(size_t ncapacity);
        void resize(size_t nsize);
        void insert(Iterator at,T t);
        void erase(Iterator at);
        T &operator[](size_t index);
        Iterator begin();
        Iterator end();
        size_t size();
        size_t capacity();
   
    };
};




#endif