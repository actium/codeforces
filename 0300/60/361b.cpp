#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << - 1 << '\n';
}

void solve(size_t n, size_t k)
{
    if (k == n)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = 1+i;

    for (size_t i = k+1; i < n; i += 2)
        std::swap(p[i], p[(i + 1) % n]);

    answer(p);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

