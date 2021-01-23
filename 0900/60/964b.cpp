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

void solve(std::vector<unsigned>& t, unsigned a, unsigned b, unsigned c, unsigned d)
{
    unsigned s = 0;
    for (const unsigned q : t) {
        s += a;

        if (b < c)
            s += (d - q) * (c - b);
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t, a, b, c, d);

    return 0;
}

