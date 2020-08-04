#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> b = a;
    std::sort(b.begin(), b.end(), std::greater<unsigned>());

    const unsigned min = b[k-1];
    std::cout << min << '\n';

    const char* separator = "";
    for (size_t i = 0; i < n && k > 0; ++i) {
        if (a[i] < min)
            continue;

        std::cout << separator << 1+i;
        separator = " ";
        --k;
    }
    std::cout << '\n';
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

