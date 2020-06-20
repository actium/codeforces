#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k)
{
    std::string p;
    for (size_t i = 0; i < n; ++i)
        p.push_back('a' + i % k);

    answer(p);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

