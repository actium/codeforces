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

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    unsigned k = 1;
    for (size_t i = 1; i < n; ++i) {
        const size_t a = p[i-1] - 1;
        if (c[i] != c[a])
            ++k;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(p, c);

    return 0;
}

