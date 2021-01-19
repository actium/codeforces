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

void solve(const std::vector<unsigned>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> f(n);
    for (const unsigned x : t)
        ++f[x];

    unsigned k = 1;
    for (size_t i = 0; i < n; ++i) {
        if (f[i] > 1)
            k += f[i] - 1;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

