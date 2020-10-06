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

void solve(const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    size_t l = 0;
    while (l < n-1 && c[l] == c.back())
        ++l;

    size_t r = n-1;
    while (r > 0 && c[r] == c.front())
        --r;

    answer(std::max(n-1 - l, r));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}

