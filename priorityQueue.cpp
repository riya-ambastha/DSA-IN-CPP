#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(20);

    std::cout << "Top element: " << pq.top() << std::endl;

    pq.pop();
    std::cout << "Top element after pop: " << pq.top() << std::endl;

    return 0;
}
