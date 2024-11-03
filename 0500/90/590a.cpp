#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    a.push_back(a.back());

    unsigned k = 0;
    for (size_t i = 2; i < n; ++i) {
        if (a[i-2] == a[i-1] || a[i-1] == a[i])
            continue;

        size_t m = 1;
        while (a[i+m-1] != a[i+m] && a[i+m] != a[i+m+1])
            ++m;

        for (size_t j = 0; j <= m / 2; ++j) {
            a[i+m/2-j-1] = a[i];
            a[i+m/2+j] = a[i+m];
        }
        k = std::max<unsigned>(k, m / 2 + 1);
    }

    a.pop_back();

    answer(k, a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
