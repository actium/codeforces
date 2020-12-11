#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<unsigned, 3>& q, const std::array<unsigned, 3>& r)
{
    unsigned d = 0, e = 0;
    for (size_t i = 0; i < 3; ++i) {
        if (q[i] < r[i])
            d += r[i] - q[i];
        else
            e += (q[i] - r[i]) / 2;
    }

    answer(d <= e);
}

int main()
{
    std::array<unsigned, 3> q, r;
    std::cin >> q >> r;

    solve(q, r);

    return 0;
}

