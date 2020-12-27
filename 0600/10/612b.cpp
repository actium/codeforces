#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& f)
{
    const size_t n = f.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[f[i]-1] = i;

    unsigned long long t = 0;
    for (size_t i = 1; i < n; ++i)
        t += abs(p[i] - p[i-1]);

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> f(n);
    std::cin >> f;

    solve(f);

    return 0;
}

