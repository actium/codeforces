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

void solve(const std::string& s, const std::vector<unsigned>& p)
{
    const size_t n = s.length();

    std::vector<unsigned> k(26);
    for (size_t i = 0; i < 26; ++i) {
        std::vector<unsigned> f(1+n);
        for (size_t j = 0; j < n; ++j)
            f[j+1] = f[j] + (s[j] - 'a' == i);

        for (const unsigned x : p)
            k[i] += f[x];

        k[i] += f.back();
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> p(m);
    std::cin >> p;

    solve(s, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

