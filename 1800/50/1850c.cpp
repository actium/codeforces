#include <array>
#include <iostream>
#include <string>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::array<std::string, 8>& a)
{
    std::string s;
    for (const std::string& x : a) {
        for (const char c : x) {
            if (c != '.')
                s.push_back(c);
        }
    }

    answer(s);
}

void test_case()
{
    std::array<std::string, 8> a;
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
