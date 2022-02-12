#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& x, unsigned k)
{
    const size_t n = x.size();

    unsigned q = 1;
    for (size_t i = 0, j = 0; j < n; ++j) {
        if (x[j] - x[i] <= k)
            continue;

        if (j == i + 1)
            return no_answer();

        i = --j;
        ++q;
    }

    answer(q);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, k);

    return 0;
}
