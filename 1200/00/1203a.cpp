#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

bool check_cw(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    for (size_t i = 1; i < n; ++i) {
        if (p[i-1] % n + 1 != p[i])
            return false;
    }
    return true;
}

bool check_ccw(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    for (size_t i = 1; i < n; ++i) {
        if (p[i] % n + 1 != p[i-1])
            return false;
    }
    return true;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    answer(check_cw(p) || check_ccw(p));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
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

