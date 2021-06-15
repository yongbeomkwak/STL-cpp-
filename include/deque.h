#ifndef __DEQUE_H__
#define __DEQUE_H__
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
namespace kstl
{

    typedef struct _Node
    {

        int data;
        struct _Node *next; //구조체 자기자신을 가르킴
        struct _Node *prev; //구조체 자기자신을 가르킴

    } Node, *Pnode;
    //name convention을 맞춰주면 좋습니다.
    //보통 struct는 대문자, 변수들은 소문자, 함수도 소문자로 합니다.
    //꼭 이 convention을 맞출 필요는 없지만 본인만의 naming convention을 지키면 좋습니다.
    typedef struct _Deque
    {
        Pnode front;
        Pnode back;
        int size;

    } Deque, *Pdeque;

    //name convention을 맞춰주면 좋습니다.
    //보통 struct는 대문자, 변수들은 소문자, 함수도 소문자로 합니다.
    //꼭 이 convention을 맞출 필요는 없지만 본인만의 naming convention을 지키면 좋습니다.
    Pdeque createDeque()
    {
        return (Pdeque)calloc(1, sizeof(Deque));
        //안에 원소들이 전부 0이면 calloc을 호출하는 편이 좋습니다.
        //OS가 메모리블록을 전부 0으로 초기화할 수 있어서 malloc호출 후 0으로 대입하는 것보다
        //빠르거나 동일한 속도(0으로 초기화된 메모리가 없는 경우)가 나옵니다.
    }
    void push_front(Pdeque deque, int newInt)
    {
        Pnode newNode = (Pnode)malloc(sizeof(Node)); //C언어에서는 형변환 명시 안해주셔도 됩니다.
        newNode->data = newInt;
        if (deque->size == 0) // size 0 일 때
        {
            newNode->next = newNode; // 자신의 다음 자기 자신 
            newNode->prev = newNode; // 자신의 이전 자기 자신 
            deque->front = newNode;  // 덱의 가장 앞 자기 자신
            deque->back = newNode; // 덱의 가장 뒤 자기 자신
        }
        else // 이미 존재시  앞에서 삽입이므로 front와 prev 건드림 
        { 
            newNode->prev = deque->front; //새 노드가 가장 앞으로 위치 대므로, 새 노드의 이전 노드는 현재 가장 앞이 되고
            deque->front->next = newNode; // 현재 가장 앞의 다음 노드는 새 노드가 됨
            deque->front = newNode; //현재 가장 앞을 새 노드로 초기화
        }
        deque->size++;
        //이렇게 쓴다면 케이스를 나누지 않고 구현 가능합니다.
    }

    void push_back(Pdeque deque, int newInt)
    {
        Pnode newNode = (Pnode)malloc(sizeof(Node)); //C언어에서는 형변환 명시 안해주셔도 됩니다.
        newNode->data = newInt;
        if (deque->size == 0) // push_front와 같음 
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            deque->front = newNode;
            deque->back = newNode;
        }
        else //push_back이므로 back 과 next 건드림 ,새 노드가 덱 맨 뒤로 가야함
        { 
            newNode->next = deque->back;  // 새 노드의 다음 노드가, 현재 가장 뒤에있는 노드가 됨 
            deque->back->prev = newNode; // 현재 가장 뒤에있는 노드의 이전 노드가 , 이번에 들어오는 새 노드가 됨 
            deque->back = newNode; //가장 뒷노드 변경 
        }
        deque->size++;
        //이렇게 쓴다면 케이스를 나누지 않고 구현 가능합니다.
    }

    int pop_front(Pdeque deque)
    {
        if (deque->size == 0)
            return -1;
        int data;
        Pnode tempNode;
        data = deque->front->data;
        tempNode = deque->front; //현재 가장 앞 노드 가르킴 
        deque->front = deque->front->prev; // 가장 앞을  현재 front 노드 이전 노드로 교체 
        deque->size--;
        free(tempNode); //free 안해주시면 메모리 누수가 발생합니다.
        return data;
    }
    int pop_back(Pdeque deque)
    {
        if (deque->size == 0)
            return -1;
        int data;
        Pnode tempNode;
        data = deque->back->data;
        tempNode = deque->back; //현재 가장 뒷 노드 가르킴 
        deque->back = deque->back->next; // 가장 뒷 노드 앞에있는 걸로 변경 
        deque->size--;
        free(tempNode); //free 안해주시면 메모리 누수가 발생합니다.
        return data;
    }
    int empty(Pdeque deque)
    {
        return deque->size == 0 ? 1 : 0;
    }
    int front(Pdeque deque)
    {
        return deque->size == 0 ? -1 : deque->front->data;
    }
    int back(Pdeque deque)
    {
        return deque->size == 0 ? -1 : deque->back->data;
    }
    int size(Pdeque deque)
    {
        return deque->size;
    }

};

#endif