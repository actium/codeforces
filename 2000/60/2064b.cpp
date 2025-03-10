#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << 0 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1+n);
    for (size_t i = 0; i < n; ++i)
        ++f[a[i]];

    std::pair<unsigned, unsigned> v = { 0, 0 };
    for (size_t i = 0, j = 0; i < n; i = j) {
        while (j < n && f[a[j]] == 1)
            ++j;

        if (j - i > v.second - v.first) {
            v.first = 1 + i;
            v.second = j;
        }

        while (j < n && f[a[j]] > 1)
            ++j;
    }

    if (v.second != 0)
        return answer(v.first, v.second);

    no_answer();
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
