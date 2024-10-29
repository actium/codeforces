#include <algorithm>
#include <iostream>
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

void solve(const std::vector<unsigned>& a, unsigned d)
{
    const size_t n = a.size();

    std::vector<std::vector<unsigned>> q(1+n);
    for (const unsigned x : a) {
        if (x <= n)
            q[x%d].push_back(x);
    }

    for (size_t i = 0; i <= n; ++i)
        std::sort(q[i].begin(), q[i].end(), std::greater<unsigned>());

    unsigned x = 0;
    while (!q[x%d].empty() && q[x%d].back() <= x) {
        q[x%d].pop_back();
        ++x;
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
