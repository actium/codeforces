#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p(n + 2, ~0u), x;
    for (size_t i = 0; i < n; ++i) {
        const integer d = a[i] - (i > 0 ? a[i-1] : 0);
        if (d > n + 1) {
            x.push_back(i);
            continue;
        }

        if (p[d] != ~0u) {
            x.push_back(p[d]);
            x.push_back(i);
        }
        p[d] = i;
    }

    std::vector<unsigned> c;
    for (unsigned i = 1; i <= n + 1; ++i) {
        if (p[i] == ~0u)
            c.push_back(i);
    }

    if (c.size() == 1)
        return answer(x.empty());

    if (c.size() == 2) {
        for (const size_t i : x) {
            const integer d = a[i] - (i > 0 ? a[i-1] : 0);
            if (d == c[0] + c[1])
                return answer(true);
        }
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n - 1);
    std::cin >> a;

    solve(a);
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
