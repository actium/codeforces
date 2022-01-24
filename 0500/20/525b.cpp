#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, const std::vector<unsigned>& a)
{
    const size_t n = s.length(), k = n / 2;

    std::vector<int> d(k);
    for (const unsigned x : a)
        ++d[x-1];

    for (size_t i = 1; i < k; ++i)
        d[i] += d[i-1];

    for (size_t i = 0; i < k; ++i) {
        if (d[i] % 2 == 1)
            std::swap(s[i], s[n-1-i]);
    }

    answer(s);
}

int main()
{
    std::string s;
    std::cin >> s;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(s, a);

    return 0;
}
