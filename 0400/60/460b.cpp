#include <iostream>
#include <vector>

using integer = long long;

integer raise(unsigned b, unsigned p)
{
    integer v = 1;
    while (p-- != 0)
        v *= b;

    return v;
}

unsigned digit_sum(unsigned x)
{
    return x > 9 ? x % 10 + digit_sum(x / 10) : x;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(int a, int b, int c)
{
    std::vector<unsigned> xs;
    for (unsigned s = 1; s <= 81; ++s) {
        const integer x = raise(s, a) * b + c;
        if (0 < x && x < 1000000000 && digit_sum(x) == s)
            xs.push_back(x);
    }

    answer(xs);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}
