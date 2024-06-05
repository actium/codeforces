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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<char, std::string>>& r)
{
    const size_t n = r.size() - 1;

    unsigned x = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (r[i].first == '!') {
            k += (__builtin_popcount(x & 0x3FFFFFF) == 25);

            unsigned y = 0;
            for (const char c : r[i].second)
                y |= 1 << c - 'a';

            x |= ~y;
        }

        if (r[i].first == '.') {
            for (const char c : r[i].second)
                x |= 1 << c - 'a';
        }

        if (r[i].first == '?') {
            k += (__builtin_popcount(x & 0x3FFFFFF) == 25);
            x |= 1 << r[i].second[0] - 'a';
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<char, std::string>> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
