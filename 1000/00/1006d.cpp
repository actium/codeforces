#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& a, std::string& b)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 0, j = n-1; i < j; ++i, --j) {
        if (a[i] == b[i] && a[j] == b[j] || a[i] == a[j] && b[i] == b[j] || a[i] == b[j] && a[j] == b[i])
            continue;

        k += 1 + (a[i] != b[i] && a[i] != b[j] && a[j] != b[i] && a[j] != b[j] && b[i] != b[j]);
    }

    if (n % 2 == 1)
        k += (a[n/2] != b[n/2]);

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
