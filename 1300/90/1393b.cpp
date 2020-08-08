#include <iostream>

unsigned f[100001];
unsigned kp = 0;
unsigned kq = 0;

void add(unsigned x)
{
    const unsigned k = ++f[x];

    if (k % 2 == 0)
        ++kp;

    if (k % 4 == 0)
        ++kq;
}

void remove(unsigned x)
{
    const unsigned k = f[x]--;

    if (k % 2 == 0)
        --kp;

    if (k % 4 == 0)
        --kq;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(char t, unsigned x)
{
    if (t == '+') {
        add(x);
    } else {
        remove(x);
    }

    answer(kp >= 4 && kq >= 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        unsigned x;
        std::cin >> x;

        add(x);
    }

    size_t q;
    std::cin >> q;

    while (q-- > 0) {
        char t;
        std::cin >> t;

        unsigned x;
        std::cin >> x;

        solve(t, x);
    }

    return 0;
}

