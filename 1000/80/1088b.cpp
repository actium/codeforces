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

void solve(std::vector<unsigned>& a, size_t k)
{
    std::sort(a.begin(), a.end());

    const size_t n = std::unique(a.begin(), a.end()) - a.begin();
    for (size_t i = 0, j = 0; i < k; ++i) {
        const unsigned d = j > 0 ? a[j-1] : 0;
        std::cout << (j < n ? a[j++] - d : 0) << '\n';
    }
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

