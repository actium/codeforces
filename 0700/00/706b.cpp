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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& x, unsigned m)
{
    answer(std::upper_bound(x.cbegin(), x.cend(), m) - x.cbegin());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    std::sort(x.begin(), x.end());

    size_t q;
    std::cin >> q;

    while (q-- > 0) {
        unsigned m;
        std::cin >> m;

        solve(x, m);
    }

    return 0;
}

