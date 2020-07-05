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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    sort(a.begin(), a.end());

    unsigned long long x = 0, y = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i < n/2)
            y += a[i];
        else
            x += a[i];
    }

    answer(x * x + y * y);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

