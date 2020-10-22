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

void solve(const std::vector<unsigned>& a, unsigned x, unsigned y)
{
    if (x > y)
        return answer(a.size());

    unsigned k = 0;
    for (const unsigned d : a)
        k += (d <= x);

    answer((k + 1) / 2);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x, y);

    return 0;
}

