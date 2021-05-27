#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
using namespace std;
namespace kvector
{
    template <typename T = int>
    class Vector
    {
        T *base;          //요소를 보관할 저장소
        size_t bSize;     // 보관된 요소 개수
        size_t bCapacity; //저장소의 용량
    public:
        class Iterator
        {           //Nested Class
            T *pos; //요소가 보관된 위치
        public:
            Iterator(T *pos = 0) //생성자
            {
                this->pos = pos;
            }
            T operator*(void) //전위 연산자는 매개변수가 void가 들어가야함 
            { //해당 위치에 대한 저장값 반환 연산자
                return *pos;
            };
            int operator-(const Iterator &iter)
            {
                return (pos - iter.pos); //위치 차이 리턴, a-b => b가 매개변수가 됨
            }
            Iterator &operator++(void)
            { //다음 위치로 이동 (전위연산자)
                cout << "전위 연산자 ++" << endl;
                pos++;
                return (*this);
            }
            const Iterator operator++(int)
            { //다음 위치로 이동(후위 연산자)
                cout << "후위 연산자 ++" << endl;
                Iterator tmp(*this);
                pos++;
                return tmp;
            }
            bool operator!=(const Iterator &iter)
            {
                return pos != iter.pos; //틀리면 True
            }
            bool operator==(const Iterator &iter)
            {
                return pos == iter.pos; //같으면 True
            }
            Iterator &operator+(int n)
            {
                Iterator tmp(this->pos);
                tmp.pos+=n;
                return tmp;
              
            }
       
        };
        Vector(size_t init_cnt = 0, T t = 0)
        {
            base = 0;
            bSize = 0;
            bCapacity = 0;
            reserve(init_cnt);      //저장소 용량을 초기화
            push_back(init_cnt, t); //차례대로 t를 삽입
        }
        ~Vector()
        {
            if (base)
            { //할당 되어있는 상태면
                delete[] base;
            }
        }
        void push_back(size_t cnt, T t)
        { //반복 삽입
            for (size_t i = 0; i < cnt; i++)
            {
                push_back(t);
            }
        }
        void push_back(T t)
        { // 끝에 삽입
            insert(end(), t);
        }
        void reserve(size_t ncapacity)
        {                               //용량 늘리기
            T *temp = new T[ncapacity]; //새로운 저장소 할당
            if (base)                   //할당된 요소가 있다면
            {
                for (size_t i = 0; i < bSize; i++)
                {
                    temp[i] = base[i]; //기존 저장소에 보관된 요소를 새로운 저장소에 복사
                }
                delete[] base; //기존 저장소 소멸
            }
            base = temp;           //base에  새로운 저장소를 대입
            bCapacity = ncapacity; //새로운 저장소 용량 대입
        }
        void resize(size_t nsize)
        {                          //사이즈 늘리기
            if (nsize > bCapacity) //입력된 새로운 요소의 개수가 저장소보다 크다면
            {
                reserve(nsize); //저장된 용량을 늘려줌
            }
            //새롭게 늘어난 요소 개수만큼 기본값 0을 보관
            for (size_t i = bSize; i < nsize; i++)
            {
                insert(end(), 0);
            }
        }
        void insert(Iterator at, T t)
        {
            size_t index = at - base; //넣고 싶은 위치 at을, base를 기준으로 상대 위치를 구함 ,여가소 Iterator의 operator - 쓰임
            if (bSize == bCapacity)   //용량이 꽉찼다면
            {
                reserve(bCapacity + 10); //용량 10 늘려줌
            }
            //보관할 위치 뒤에 있는 요소들 뒤로 한칸씩 이동
            for (size_t i = bSize; i > index; i++)
            {
                base[i] = base[i-1]; //뒤로 이동, 2->3, 3->4 ...
            }
            base[index] = t; //해당 위치에 해당 값 넣음
            bSize++;         //사이즈 1 증가
        }
        void erase(Iterator at)
        {
            int index = at - base; //넣고 싶은 위치 at을, base를 기준으로 상대 위치를 구함 ,여가소 Iterator의 operator - 쓰임

            //삭제할 위치 뒤에 요소들 한칸씩 앞으로 이동
            for (size_t i = index + 1; i < bSize; i++)
            {
                base[i] = base[i];
            }
            bSize--; //사이즈 감소
        }
        T &operator[](size_t index)
        {
            if (index < bSize)
            {
                return base[index];
            }
            throw "잘못된 인덱스를 참조했습니다.";
        }
        Iterator begin()
        {
            return base;
        }
        Iterator end()
        {
            //주위!!! 마지막 보관된 요소 위치가 아니라 그 다음 위치
            return base+bSize;
        }
        size_t size(){
            return bSize;
        }
        size_t capacity(){
            return bCapacity;
        }
    };
};

#endif