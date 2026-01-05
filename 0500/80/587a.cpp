#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& w)
{
    unsigned f[1000022] = {};
    for (const unsigned x : w)
        ++f[x];

    unsigned k = 0;
    for (size_t i = 0; i < 1000021; ++i) {
        k += f[i] % 2;
        f[i+1] += f[i] / 2;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w);

    return 0;
}
