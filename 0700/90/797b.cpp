#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a)
{
    int s = 0, n = -10000, p = 10000;
    for (const int x : a) {
        if (x > 0)
            s += x;

        if (x < 0 && -x % 2 == 1)
            n = std::max(n, x);

        if (x > 0 && x % 2 == 1)
            p = std::min(p, x);
    }

    if (s % 2 == 0)
        s = std::max(s + n, s - p);

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
