#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& b, unsigned s)
{
    unsigned z = 0;

    bool v[100] = {};
    for (const unsigned x : b) {
        v[x] = true;
        z = std::max(z, x);
    }

    unsigned t = 0;
    for (unsigned i = 1; i < z || t < s; ++i) {
        if (!v[i])
            t += i;
    }

    answer(t == s);
}

void test_case()
{
    size_t m;
    std::cin >> m;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(b, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
