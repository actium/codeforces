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

void solve(const std::vector<unsigned>& s)
{
    unsigned y = 0;
    for (const unsigned x : s) {
        if (x <= 2048)
            y += x;
    }

    answer(y >= 2048);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

