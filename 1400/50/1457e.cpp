#include <algorithm>
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

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<int>& c, size_t k)
{
    std::sort(c.begin(), c.end(), std::greater<int>());

    std::priority_queue<long long> q;
    for (size_t i = 0; i < k; ++i)
        q.push(0);

    long long b = 0, v = 0;
    for (const int x : c) {
        v += b;

        q.push(b + x);
        b = q.top();
        q.pop();
    }

    answer(v);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> c(n);
    std::cin >> c;

    solve(c, k);

    return 0;
}

