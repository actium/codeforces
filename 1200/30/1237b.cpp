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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[b[i]-1] = i;

    size_t q = n, k = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t j = x[a[i]-1];
        if (q == n || j > q)
            q = j;
        else
            ++k;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

