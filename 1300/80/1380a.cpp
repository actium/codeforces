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

void answer(size_t x, size_t y, size_t z)
{
    answer(true);

    std::cout << 1 + x << ' ' << 1 + y << ' ' << 1 + z << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    for (size_t i = 1; i < n-1; ++i) {
        if (p[i-1] < p[i] && p[i] > p[i+1])
            return answer(i-1, i, i+1);
    }

    answer(false);
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

