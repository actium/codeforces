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

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second  << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::priority_queue<std::pair<unsigned, size_t>> q;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != 0)
            q.emplace(a[i], i);
    }

    std::vector<std::pair<size_t, size_t>> p;
    while (q.size() > 1) {
        auto x = q.top(); q.pop();
        auto y = q.top(); q.pop();

        p.emplace_back(x.second, y.second);

        if (--x.first != 0)
            q.push(x);

        if (--y.first != 0)
            q.push(y);
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
