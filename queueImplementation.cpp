#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element: " << q.back() << std::endl;

    q.pop();

    std::cout << "Front element after pop: " << q.front() << std::endl;

    return 0;
}
