#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::array<int, 3>& s, const std::array<int, 3>& t, const std::array<unsigned, 6>& a)
{
    const bool f[] = {
        s[1] < 0, s[1] > t[1], s[2] < 0, s[2] > t[2], s[0] < 0, s[0] > t[0]
    };

    unsigned v = 0;
    for (size_t i = 0; i < 6; ++i)
        v += f[i] * a[i];

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<int, 3> s, t;
    std::cin >> s >> t;

    std::array<unsigned, 6> a;
    std::cin >> a;

    solve(s, t, a);

    return 0;
}
