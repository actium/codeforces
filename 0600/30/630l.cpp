#include <iostream>
#include <string>

void answer(unsigned x)
{
    printf("%05u", x);
}

void solve(const std::string& a)
{
    const auto d = [&a](size_t i, unsigned f) {
        return (a[i] - '0') * f;
    };

    const unsigned x = d(0, 10000) + d(2, 1000) + d(4, 100) + d(3, 10) + d(1, 1);

    unsigned long long v = 1;
    for (unsigned i = 0; i < 5; ++i)
        v = v * x % 100000;

    answer(v);
}

int main()
{
    std::string a;
    std::cin >> a;

    solve(a);

    return 0;
}
