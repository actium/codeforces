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

void solve(std::vector<unsigned>& c, unsigned x, unsigned y)
{
    size_t n = c.size();

    for (size_t i = 1; i < n; ++i)
        c[i] += c[i-1];

    for (size_t i = 0; i < n && c[i] <= y; ++i) {
        if (c[i] < x)
            continue;

        const unsigned m = c.back() - c[i];
        if (m >= x && m <= y)
            return answer(i+2);
    }

    answer(0);
}

int main()
{
    size_t m;
    std::cin >> m;

    std::vector<unsigned> c(m);
    std::cin >> c;

    unsigned x, y;
    std::cin >> x >> y;

    solve(c, x, y);

    return 0;
}

