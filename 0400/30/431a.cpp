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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::array<unsigned, 4>& a, const std::string& s)
{
    unsigned sum = 0;
    for (const char c : s)
        sum += a[c - '1'];

    answer(sum);
}

int main()
{
    std::array<unsigned, 4> a;
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s);

    return 0;
}

