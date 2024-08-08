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

unsigned count(const std::vector<unsigned>& a, size_t lb, size_t ub)
{
    unsigned k = 0;
    {
        size_t x = lb;
        while (x <= ub && a[x] != 0) {
            while (x <= ub && a[x] != 0)
                ++x;

            ++x;
            ++k;
        }
        while (x <= ub) {
            if (a[x++] == 0)
                ++k;
        }
    }
    return k;
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    if (a.front() == 2)
        a.front() = 1;
    if (a.back() == 2)
        a.back() = 1;

    unsigned k = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        if (a[j] == 2 || j+1 == n) {
            k += count(a, i, j) - (j+1 != n);
            i = j;
        }
    }

    answer(k);
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
