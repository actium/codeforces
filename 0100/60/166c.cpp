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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned x)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    int k = 0;
    while (true) {
        const size_t m = (n + k - 1) / 2;
        if (m >= n || a[m] == x || a[m] < x && k < 0 || a[m] > x && k > 0)
            break;

        k += (a[m] < x ? 1 : -1);
    }

    answer(std::abs(k));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}
