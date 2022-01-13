#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& u, unsigned v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : u) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';

    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned s)
{
    if (2 * n > s)
        return no_answer();

    std::vector<unsigned> a(n, 2);
    a.back() += s - 2 * n;
    answer(a, 1);
}

int main()
{
    unsigned n, s;
    std::cin >> n >> s;

    solve(n, s);

    return 0;
}
