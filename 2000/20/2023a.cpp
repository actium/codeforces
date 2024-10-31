#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

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

void solve(std::vector<std::array<unsigned, 2>>& a)
{
    std::sort(a.begin(), a.end(), [](const std::array<unsigned, 2>& lhs, const std::array<unsigned, 2>& rhs) {
        return std::minmax(lhs[0], lhs[1]) < std::minmax(rhs[0], rhs[1]);
    });

    std::vector<unsigned> v;
    for (const std::array<unsigned, 2>& p : a) {
        v.push_back(p[0]);
        v.push_back(p[1]);
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::array<unsigned, 2>> a(n);
    std::cin >> a;

    solve(a);
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
