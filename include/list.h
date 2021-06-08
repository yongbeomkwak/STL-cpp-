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
                prev = next = 0;
            }
        };
        node *head;   // 가장 앞 노드
        node *tail;   // 가장 끝 노드
        size_t bSize; // 리스트 사이즈

    public:
        class Iterator
        {
            node *now; //현재노드의 위치 정보
        public:
            Iterator(node *now = 0)
            {
                this->now = now;
            }
            Iterator(const Iterator &iter) //매개변수 있는 생성자
            {
                now = iter.now;
            }
            T operator*(void) //데이터 출력
            {
                return now->data;
            }
            //즉 Iterator가 node * 타입으로 자연스럽게 형변환 되게함
            //문법:
            //operator 원하는 타입
            operator node *(void) ////list 내에서 node *와 반복자(Iterator) 간의 묵시적 형변환 가능하게 함
            {
                return now; //해당 타입에 대한 리턴 값
            }
            bool operator==(const Iterator &iter)
            {
                return now == iter.now;
            }
            bool operator!=(const Iterator &iter)
            {
                return now != iter.now;
            }
            Iterator &operator++(void)
            {
                now = now->next; //now를 다음 노드의 위치 정보로 변경
                return (*this);  //변경된 자기 자신을 반환
            }
            const Iterator operator++(int)
            {
                Iterator tmp(*this); //변경되기 전 자신을 복사
                now = now->next;     //now를 다음 노드의 위치 정보로 변경
                return tmp;          //변경되기 전 자신을 복사한 반복자 반환
            }
        };
        List()
        {
            head = new node(); //더미 노드를 생성하여 head 에 대입
            tail = new node(); //더미 노드를 생성하여 tail 에 대입
            head->next = tail; //head의 다음 노드를 tail로 가르킴
            tail->prev = head; //tail 의 이전 노드를 head를 가르킴
            bSize = 0;
        }
        ~List()
        {
            while (head != tail) //맨 처음 노드와 맨 마지막 노드가 다르면

            {

                head = head->next; //head를 head가 가리키는 노드의 다음 노드로 변경

                //변경되기 전의 head를 삭제

                delete head->prev; //head가 가리키는 노드의 이전 노드 소멸(이전 head임)
            }

            delete head; //마지막 남은 노드 소멸
        }
        void resize(size_t nsize)
        {
            //nsize-bSize 번 반복 함
            for (size_t n = bSize; n < nsize; n++)
            {
                insert(end(), 0);
            }
        }
        void push_back(T t)
        {
            insert(end(), t);
        }
        void insert(Iterator at, T t)
        {
            node *pos = at; //at에 있는 노드를 pos에 대입(반복자에 묵시적 형변환 연산자)

            node *now = new node(t); //t를 보관한 노드를 생성하여 now에 대입

            hang_node(now, pos); //생성한 now 노드를 pos 앞에 연결

            bSize++; //보관된 요소 개수 1 증가
        }
        void erase(Iterator at)
        {
            if (bSize == 0)
            {
                throw "지울 노드가 없습니다!";
            }
            dehang_node(at); //at에 있는 노드를 리스트에서 연결을 끊는다.
            node *pos = at;
            delete pos; //at에 있는 노드를 소멸
            bSize--;    //보관한 요소 개수 1 감소
        }
        Iterator begin()
        {
            //head는 더미 노드이므로 head의 다음 노드가 첫 번째 보관된 요소가 있는 노드임
            return head->next; //head의 다음 노드를 반환(iterator와 node *는 묵시적 형변환)
        }
        Iterator end()
        {
            return tail;
        }
        size_t size()
        {
            return bSize;
        }

    private:
        void hang_node(node *now, node *pos)
        {
            //기존 위치 pos
            //새로 들어온 now 를 매단다

            //now가 가리키는 노드의 prev를 pos가 가리키는 prev로 변경
            now->prev = pos->prev;
            //now가 가리키는 노드의 next를 pos로 변경
            now->next = pos;
            //pos의 이전 노드의 next를 now로 변경
            pos->prev->next = now;
            //pos가 가리키는 노드의 prev를 now로 변경
            pos->prev = now;
            /*
            A-B-C-E-F 에서
            현재 pos:C-E-F
            현재 now:0-D-0(now)

            1.now의 왼쪽 연결
            새로생긴 now의 이전을 변경
            현재 pos:C-E-F
            현재 now:0-D-0 ->  C-D-0

            A<->B<->C<->   <->E<->F 
                    (<-)D 
            2.now의 오른쪽 연결
            새로 생긴 now의 다음을 기존 노드 위치 가르킴
            현재 pos:C-E-F
            현재 now:C-D-0 -> C-D-E

            A<->B<->C<->   <->E<->F 
                    <-D(->)

            3.pos의 prev의  오른쪽 연결 
            pos의 prev: B-C-E -> B-C-D

            현재 pos:C-E-F
            현재 now:C-D-E
            
            A<->B<->C   <->E<->F 
                    (<->)D->

            4.pos의 왼쪽 연결 

            현재 pos:C-E-F ->D-E-F
            현재 now:C-D-E    
            
            A<->B<->C   E<->F 
                    <->D(<->)
            촤종:A<->B<->C<->D<->E<->F
            */
        }
        void dehang_node(node *pos)
        {
            //연결 끊기
            pos->prev->next = pos->next;
            //현재 위치의 이전 노드의 오른쪽 연결을 다음 위치 껄로 교체
			pos->next->prev = pos->prev;
            //현재위치의 다음 노드의 왼쪽 연결을  이전 노드 껄로 교체
        }
    };
};
#endif