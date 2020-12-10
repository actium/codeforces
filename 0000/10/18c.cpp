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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<int> p = a;
    for (size_t i = 1; i < n; ++i)
        p[i] += p[i-1];

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (2 * p[i-1] == p[n-1])
            ++k;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

