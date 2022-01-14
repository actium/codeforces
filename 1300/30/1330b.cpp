#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1+n);
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n && !v[a[i]]; ++i) {
            p[i+1] = std::max(p[i], a[i]);
            v[a[i]] = true;
        }
    }

    std::vector<unsigned> s(1+n);
    {
        std::vector<bool> v(n);
        for (size_t i = n; i-- > 0 && !v[a[i]]; ) {
            s[i] = std::max(s[i+1], a[i]);
            v[a[i]] = true;
        }
    }

    std::vector<std::pair<unsigned, unsigned>> x;
    for (size_t i = 0; i <= n; ++i) {
        if (p[i] + s[i] == n)
            x.emplace_back(p[i], s[i]);
    }

    answer(x);
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
