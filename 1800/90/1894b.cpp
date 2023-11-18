#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned f[101] = {};
    for (const unsigned x : a)
        ++f[x];

    std::vector<unsigned> s, t;
    for (unsigned i = 1; i <= 100; ++i) {
        if (f[i] == 1)
            t.push_back(i);

        if (f[i] > 1)
            s.push_back(i);
    }

    if (s.size() < 2)
        return no_answer();

    std::vector<unsigned> b(n, 1);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != s[0] && a[i] != s[1])
            continue;

        if (a[i] == s[0] && f[a[i]]-- == 1)
            b[i] = 2;

        if (a[i] == s[1] && f[a[i]]-- == 1)
            b[i] = 3;
    }

    answer(b);
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
