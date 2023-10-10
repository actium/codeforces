#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    int x = 0;
    for (size_t i = 0; i < n && s[i] == x; ++i)
        ++x;

    while (x >= 0) {
        std::cout << x << std::endl;
        std::cin >> x;
    }
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
    std::ios::sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
