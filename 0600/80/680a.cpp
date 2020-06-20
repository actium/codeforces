#include <array>
#include <iostream>
#include <unordered_map>

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

void solve(const std::array<unsigned, 5>& t)
{
    unsigned sum = 0;
    std::unordered_map<unsigned, size_t> f;
    for (const unsigned x : t) {
        sum += x;
        ++f[x];
    }

    unsigned d = 0;
    for (const auto& x : f) {
        if (x.second >= 3)
            d = std::max(d, 3 * x.first);

        if (x.second == 2)
            d = std::max(d, 2 * x.first);
    }

    answer(sum - d);
}

int main()
{
    std::array<unsigned, 5> t;
    std::cin >> t;

    solve(t);

    return 0;
}

