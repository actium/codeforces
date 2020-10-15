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

void solve(const std::vector<unsigned>& p, const std::vector<size_t>& s, const std::vector<size_t>& c, size_t m)
{
    const size_t n = p.size();

    std::vector<size_t> b(m);
    for (size_t i = 0; i < n; ++i) {
        const size_t si = s[i] - 1;
        if (b[si] == 0 || p[b[si]-1] < p[i])
            b[si] = i + 1;
    }

    unsigned k = 0;
    for (const size_t x : c) {
        const size_t si = s[x-1] - 1;
        k += (x != b[si]);
    }

    answer(k);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<size_t> s(n);
    std::cin >> s;

    std::vector<size_t> c(k);
    std::cin >> c;

    solve(p, s, c, m);

    return 0;
}

