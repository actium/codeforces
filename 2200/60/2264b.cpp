#include <iostream>
#include <queue>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<int>& a, size_t m)
{
    const size_t n = a.size();

    std::pair<std::priority_queue<int>, integer> q = {};
    for (size_t i = 0; i + 1 < m; ++i) {
        q.first.push(a[i]);
        q.second += a[i];
    }

    integer v = a[m-1] * integer(m) - q.second;
    for (size_t i = m; i < n; ++i) {
        q.first.push(a[i-1]);
        q.second += a[i-1];

        q.second -= q.first.top();
        q.first.pop();

        v = std::max(v, a[i] * integer(m) - q.second);
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, m);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
