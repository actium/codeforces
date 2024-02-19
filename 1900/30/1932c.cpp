#include <iostream>
#include <string>
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

void solve(const std::vector<unsigned>& a, const std::string& s, unsigned m)
{
    const size_t n = a.size();

    std::vector<unsigned> t;
    for (size_t i = 0, lb = 0, ub = n - 1; i < n; ++i)
        t.push_back(s[i] == 'L' ? a[lb++] : a[ub--]);

    std::vector<unsigned> v(n);
    for (size_t i = n - 1; ~i != 0; --i)
        v[i] = (i == n - 1 ? t[i] : 1ull * v[i+1] * t[i]) % m;

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s, m);
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
