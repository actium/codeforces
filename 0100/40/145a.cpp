#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length();

    unsigned f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i])
            ++f[a[i] == '7'];
    }

    answer(std::max(f[0], f[1]));
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

