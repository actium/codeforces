#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a)
{
    constexpr unsigned t[6] = { 4, 8, 15, 16, 23, 42 };

    const unsigned n = a.size();

    unsigned f[7] = { n };
    for (const unsigned x : a) {
        for (size_t i = 0; i < 6; ++i) {
            if (t[i] == x && f[i] > 0) {
                --f[i];
                ++f[i+1];
            }
        }
    }

    answer(n - 6 * f[6]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

