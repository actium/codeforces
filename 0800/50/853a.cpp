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

void answer(integer u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t k, const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    std::priority_queue<std::pair<unsigned, size_t>> q;
    for (size_t i = 0; i < k; ++i)
        q.emplace(c[i], i);

    std::vector<unsigned> t(n);
    for (size_t i = 0; i < n; ++i) {
        if (k + i < n)
            q.emplace(c[k+i], k+i);

        t[q.top().second] = k + i + 1;
        q.pop();
    }

    integer d = 0;
    for (size_t i = 0; i < n; ++i)
        d += (t[i] - i - 1ull) * c[i];

    answer(d, t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(k, c);

    return 0;
}
