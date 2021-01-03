#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        ++k;

        if (i + 1 < n && a[i] != a[i+1] && b[i] != b[i+1])
            ++i;
    }

    answer(k);
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

