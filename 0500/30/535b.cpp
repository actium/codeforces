#include <iostream>
#include <queue>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned p = 0;

    std::queue<unsigned> q;
    for (q.push(0); q.front() != n; q.pop(), ++p) {
        const unsigned x = q.front();
        q.push(x * 10 + 4);
        q.push(x * 10 + 7);
    }

    answer(p);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

