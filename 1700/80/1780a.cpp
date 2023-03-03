#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y, size_t z)
{
    std::cout << "YES" << '\n';
    std::cout << 1 + x << ' ' << 1 + y << ' ' << 1 + z << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[2];
    for (size_t i = 0; i < n; ++i)
        p[a[i] % 2].push_back(i);

    if (p[1].size() > 2)
        return answer(p[1][0], p[1][1], p[1][2]);

    if (p[1].size() != 0 && p[0].size() > 1)
        return answer(p[1][0], p[0][0], p[0][1]);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
