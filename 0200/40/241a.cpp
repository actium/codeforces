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

void solve(const std::vector<unsigned>& d, const std::vector<unsigned>& s, unsigned k)
{
    const size_t m = d.size();

    unsigned t = 0, f = 0, r = 0;
    for (size_t i = 0; i < m; ++i) {
        f += s[i];

        r = std::max(r, s[i]);
        if (f < d[i]) {
            const unsigned q = (d[i] - f + r - 1) / r;
            f += q * r;
            t += q * k;
        }

        f -= d[i];
        t += d[i];
    }

    answer(t);
}

int main()
{
    size_t m;
    std::cin >> m;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> d(m);
    std::cin >> d;

    std::vector<unsigned> s(m);
    std::cin >> s;

    solve(d, s, k);

    return 0;
}

