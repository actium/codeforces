#include <algorithm>
#include <iostream>
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

void solve(std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::sort(s.begin(), s.end());

    unsigned t = 0;
    for (const auto [a, b] : s)
        t = b < t ? a : b;

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

