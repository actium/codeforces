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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& r)
{
    const unsigned x = *std::max_element(r.cbegin(), r.cend());
    answer(x > 25 ? x - 25 : 0);
}

int main()
{
    size_t k;
    std::cin >> k;

    std::vector<unsigned> r(k);
    std::cin >> r;

    solve(r);

    return 0;
}

