#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
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

void solve(const std::vector<unsigned>& p, const std::vector<std::array<unsigned, 3>>& q)
{
    for (const auto& r : q) {
        unsigned k = 0;
        for (size_t i = r[0] - 1; i < r[1]; ++i) {
            if (p[i] < p[r[2]-1])
                ++k;
        }

        answer(r[0] + k == r[2]);
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<std::array<unsigned, 3>> q(m);
    std::cin >> q;

    solve(p, q);

    return 0;
}

