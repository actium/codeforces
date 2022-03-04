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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& p)
{
    const size_t n = p[0].size();

    size_t r = 0, c = 0;
    while (c < n && (p[r][c] < '3' || p[r^1][c] > '2')) {
        if (p[r][c] > '2')
            r ^= 1;

        ++c;
    }

    answer(r == 1 && c == n);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> p(2);
    std::cin >> p;

    solve(p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
