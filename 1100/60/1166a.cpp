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

unsigned nC2(unsigned n)
{
    return n * (n - 1) / 2;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::string>& s)
{
    size_t f[26] = {};
    for (const std::string& v : s)
        ++f[v.front() - 'a'];

    unsigned x = 0;
    for (size_t i = 0; i < 26; ++i) {
        const size_t k1 = f[i] / 2;
        const size_t k2 = f[i] - k1;

        x += nC2(k1) + nC2(k2);
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

