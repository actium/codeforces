#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned b)
{
    const size_t n = a.size();

    unsigned s = 0, v = 0;
    for (const unsigned x : a) {
        s += x;
        v = std::max(v, x);
    }

    const double r = double(b + s) / n;
    if (r < v)
        return no_answer();

    for (const unsigned x : a)
        answer(r - x);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned b;
    std::cin >> b;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, b);

    return 0;
}

