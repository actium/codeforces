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

void solve(const std::vector<unsigned>& x, unsigned c)
{
    const size_t n = x.size();

    unsigned k = 0;
    for (size_t i = 0; i < n-1; ++i) {
        if (c + x[i+1] < x[i])
            k = std::max(k, x[i] - x[i+1] - c);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, c);

    return 0;
}

