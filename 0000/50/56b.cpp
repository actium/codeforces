#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x = 0;
    while (x < n && a[x] == 1+x)
        ++x;

    if (x == n)
        return answer(0, 0);

    size_t y = n-1;
    while (y > x && a[y] == 1+y)
        --y;

    for (size_t i = x; i <= y; ++i) {
        if (a[i] != 1+x+(y-i))
            return answer(0, 0);
    }

    answer(1+x, 1+y);
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

