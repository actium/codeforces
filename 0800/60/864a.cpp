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

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();
    const size_t m = n / 2;

    std::sort(a.begin(), a.end());

    if (a[0] != a[m-1] || a[m] != a[n-1] || a[0] == a[m])
        return no_answer();

    answer(a[0], a[m]);
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

