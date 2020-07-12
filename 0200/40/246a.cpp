#include <iostream>
#include <vector>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n)
{
    if (n < 3)
        return answer(-1);

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        a[i] = 100 - i;

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

