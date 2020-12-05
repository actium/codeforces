#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.size();

    unsigned f[4] = {};
    for (size_t i = 0; i < n; ++i) {
        const size_t x = (a[i] - '0') << 1 | (b[i] - '0');
        ++f[x];
    }

    answer(f[0] * f[2] + f[0] * f[3] + f[1] * f[2]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

