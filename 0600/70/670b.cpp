#include <iostream>
#include <vector>

#include <cmath>

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

void solve(const std::vector<unsigned>& id, size_t k)
{
    const unsigned m = (sqrt(8ull * k - 7) - 1) / 2;
    const unsigned a = k - m * (m + 1) / 2;

    answer(id[a-1]);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> id(n);
    std::cin >> id;

    solve(id, k);

    return 0;
}

