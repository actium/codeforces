#include <algorithm>
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

void solve(const std::string& s, const std::array<unsigned, 26>& w, unsigned k)
{
    const size_t n = s.length();

    unsigned d = 0;
    for (size_t i = 0; i < n; ++i)
        d += w[s[i] - 'a'] * (i + 1);

    const unsigned x = *std::max_element(w.cbegin(), w.cend());
    for (size_t i = 0; i < k; ++i)
        d += x * (n + i + 1);

    answer(d);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned k;
    std::cin >> k;

    std::array<unsigned, 26> w;
    std::cin >> w;

    solve(s, w, k);

    return 0;
}

