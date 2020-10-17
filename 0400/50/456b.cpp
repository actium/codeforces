#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned raise(unsigned b, unsigned e)
{
    unsigned v = 1;
    for (e %= 4; e != 0; e /= 2) {
        if (e & 1)
            v *= b;

        b *= b;
    }
    return v;
}

void solve(const std::string& n)
{
    size_t k = n.length();

    unsigned e = n[--k] - '0';
    if (k > 0)
        e += (n[--k] - '0') * 10;

    const unsigned s = 1 + raise(2, e) + raise(3, e) + raise(4, e);
    answer(s % 5);
}

int main()
{
    std::string n;
    std::cin >> n;

    solve(n);

    return 0;
}

