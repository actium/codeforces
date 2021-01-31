#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& w, const std::vector<unsigned>& c, unsigned b)
{
    const size_t n = w.size();

    integer s = 0, t = 0, v = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (s += w[j], t += c[j]; s > b; ++i)
            s -= w[i], t -= c[i];

        v = std::max(v, t);
    }

    answer(v);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned b;
    std::cin >> b;

    std::vector<unsigned> w(n), c(n);
    std::cin >> w >> c;

    solve(w, c, b);

    return 0;
}

