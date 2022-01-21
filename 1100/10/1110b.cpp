#include <iostream>
#include <queue>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& b, size_t m, size_t k)
{
    const size_t n = b.size();

    std::priority_queue<unsigned> q;
    for (size_t i = 1; i < n; ++i)
        q.emplace(b[i] - b[i-1]);

    unsigned d = b.back() - b.front() + 1;
    while (--k != 0 && !q.empty()) {
        d -= q.top() - 1;
        q.pop();
    }

    answer(d);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b, m, k);

    return 0;
}
