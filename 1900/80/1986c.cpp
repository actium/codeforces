#include <algorithm>
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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, const std::vector<unsigned>& p, std::string& c)
{
    const size_t n = s.length();

    std::sort(c.begin(), c.end());

    std::vector<unsigned> f(1+n);
    for (const unsigned x : p) {
        if (++f[x] > 1)
            c.pop_back();
    }

    for (size_t i = n; i > 0; --i) {
        if (f[i] != 0) {
            s[i-1] = c.back();
            c.pop_back();
        }
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> p(m);
    std::cin >> p;

    std::string c;
    std::cin >> c;

    solve(s, p, c);
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
