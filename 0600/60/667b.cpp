#include <algorithm>
#include <iostream>
#include <numeric>
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

void solve(std::vector<unsigned>& l)
{
    const unsigned s = std::accumulate(l.cbegin(), l.cend(), 0);
    const unsigned x = *std::max_element(l.cbegin(), l.cend());

    answer(x - (s - x) + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> l(n);
    std::cin >> l;

    solve(l);

    return 0;
}

