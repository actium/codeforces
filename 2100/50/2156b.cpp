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

unsigned simulate(const std::string& s, unsigned x)
{
    const size_t n = s.length();

    unsigned t = 0;
    while (x != 0) {
        s[t%n] == 'A' ? x -= 1 : x /= 2;
        ++t;
    }
    return t;
}

void solve(const std::string& s, std::vector<unsigned>& a)
{
    const size_t m = a.size();

    if (s.find('B') != std::string::npos) {
        for (size_t i = 0; i < m; ++i)
            a[i] = simulate(s, a[i]);
    }

    answer(a);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> a(q);
    std::cin >> a;

    solve(s, a);
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
