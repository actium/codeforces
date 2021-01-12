#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t n = s.length(), m = t.length();

    std::vector<unsigned> b(1+n);
    for (size_t i = 0; i = s.find(t, i), i != std::string::npos; ++i)
        b[1+i] = 1;

    for (size_t i = 1; i <= n; ++i)
        b[i] += b[i-1];

    for (const auto [l, r] : q)
        answer(l + m - 1 <= r ? b[r-m+1] - b[l-1] : 0);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::string s, t;
    std::cin >> s >> t;

    std::vector<std::pair<unsigned, unsigned>> q(k);
    std::cin >> q;

    solve(s, t, q);

    return 0;
}

