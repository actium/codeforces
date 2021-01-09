#include <algorithm>
#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::string& a, std::string& b)
{
    const size_t n = a.length();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    unsigned x = 0;
    for (size_t i = 0, j = 0; i < n; ++i, ++j) {
        while (j < n && b[j] < a[i])
            ++j;

        x += (j >= n);
    }

    unsigned y = 0;
    for (size_t i = 0, j = 0; i < n; ++i, ++j) {
        while (j < n && b[j] <= a[i])
            ++j;

        y += (j < n);
    }

    answer(x, y);
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

