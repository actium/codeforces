#include <algorithm>
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

void solve(std::vector<unsigned>& p, unsigned d)
{
    std::sort(p.begin(), p.end(), std::greater<unsigned>());

    unsigned k = 0;
    for (size_t i = 0, n = p.size(); i < n; ++i) {
        const unsigned q = d / p[i] + 1;
        if (q <= n - i) {
            n -= q - 1;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, d);

    return 0;
}
