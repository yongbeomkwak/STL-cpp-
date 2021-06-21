#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 0;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(3);
    pq.push(2);
    pq.push(4);
    int answer = 0;
    for (size_t i = 0; i < N; i++)
    {
        cout << pq.top();
    }
}
