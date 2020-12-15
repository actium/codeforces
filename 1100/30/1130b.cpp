#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size() / 2;

    std::vector<std::vector<unsigned>> p(1+n);
    for (size_t i = 0; i < 2 * n; ++i)
        p[a[i]].push_back(1+i);

    unsigned long long d = 0;
    for (unsigned i = 1, x1 = 1, x2 = 1; i <= n; ++i) {
        d += abs(p[i][0] - x1);
        x1 = p[i][0];

        d += abs(p[i][1] - x2);
        x2 = p[i][1];
    }

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);

    return 0;
}

