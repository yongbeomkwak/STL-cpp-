# STL project

### 0.Template
- 통상 일반적인 코딩 방식에서는 .h파일에는 선언(declaration)코드만 입력, .cpp 파일에는 정의(definition)코드를 작성하지만, **템플릿이 사용된 함수를 구현부에 작성하면 에러가 생김**

- 이유:템플릿은 컴파일 단계에서  실제 코드에서 호출된 자료형에 해당하는 코드를 컴파일러가 추가로 만들어내는 개념이기 때문에 cpp 파일 구현코드가 기록되면안됨

-   정리:템플릿 정의코드는 행상 템플릿 선언 있는 **헤더파일**에만 작성할 것
-   또한 default argument 역시 **헤더파일**에서만 작성가능

### 1.Vector
-   연산자 재정의,insert,erase의 삽입 및 삭제 순선 유심히 보기
-   template 및 default argument 유심히 보기 

### 2.List
-   structure 생성자 확인하기 (node)
-   이중 리스트
    -   자신의 이전과 다음의 노드 위치를 알고 있음
    -   operator [] 사용불가, 연속적인 메모리 구조가 아니기 때문에
    -   reserve 함수 역시 사용불가
    -   resize 밒 size는 사용 가능 
-   원형 리스트
    -   이중 리스트에서 마지막 노드가 처음 시작 노드를 알 때 원형 리스트라 함

### 3.Stack
- struct안 자기 자신을 멤버변수로 하는 법
- calloc 과 malloc 그리고 free,
- calloc 과 malloc시 반드시 C++은 포인터 형으로 형변환 해줘야함 

### 4.queue
-   <queue> header file
-   템플릿 선언 부분을 보겠습니다.

    -   0. template 
    -   template < typename T,
           typename Container = vector<T>,
                typename Compare = less<typename Container::velue_type> >
            class priority_queue;

---

    -   1.  기본 생성자 형식 
    -   priority_queue < [Data Type] > [변수이름];
    -   ex) priority_queue<int> pq;

---
    -   2.  내부 컨테이너 변경 
    -   priority_queue < [Data Type], [Container Type] > [변수이름];
    -   ex) priority_queue<int, deque<int> > pq;

---
    -   3.  정렬 기준 변경 
    -   priority_queue < [Data Type], [Container Type], [정렬기준] > [변수이름];

    -   ex) priority_queue<int , vector<int>, greater<int> > pq;

    -  4.정렬 기준(함수가아닌 클래스 or 구조체)
    -  보통 greater<type> -> 오름 차순, less<type> ->내림차순
- 커스텀 정렬 기준 만들기 참고:[here](https://travelbeeee.tistory.com/126)
