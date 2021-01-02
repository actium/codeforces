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

void solve(std::vector<unsigned>& t)
{
    std::sort(t.begin(), t.end());

    unsigned k = 0, d = 0;
    for (const unsigned q : t) {
        if (d <= q) {
            d += q;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

