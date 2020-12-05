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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<unsigned, std::string>>& d)
{
    constexpr unsigned oo = 1000000;

    unsigned s[8] = { 0, oo, oo, oo, oo, oo, oo, oo };
    for (const auto& q : d) {
        size_t x = 0;
        for (const char v : q.second)
            x |= 1 << (v - 'A');

        for (size_t i = 0; i < 8; ++i)
            s[i|x] = std::min(s[i|x], s[i] + q.first);
    }

    answer(s[7] < oo ? s[7] : -1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, std::string>> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}

