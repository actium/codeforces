#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::string& a)
{
    const size_t m = a.length();

    unsigned k = 0;
    for (size_t i = n; i < m; i += n)
        k += (a[i-3] == a[i-2] && a[i-2] == a[i-1]);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    solve(n, a);

    return 0;
}

