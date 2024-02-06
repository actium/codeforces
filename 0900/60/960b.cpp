#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<int>& a, const std::vector<int>& b, unsigned k)
{
    const size_t n = a.size();

    std::priority_queue<int> q;
    for (size_t i = 0; i < n; ++i)
        q.push(abs(a[i] - b[i]));

    for (unsigned i = 0; i < k; ++i) {
        const int x = q.top();
        q.pop();
        q.push(x > 0 ? x - 1 : x + 1);
    }

    integer s = 0;
    while (!q.empty()) {
        s += 1ULL * q.top() * q.top();
        q.pop();
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k1, k2;
    std::cin >> n >> k1 >> k2;

    std::vector<int> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, k1 + k2);

    return 0;
}
