#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

unsigned v(const std::vector<unsigned>& a, unsigned t)
{
    unsigned k = 0;
    for (const unsigned x : a) {
        if (x < t)
            k += (t - 1) - x;

        if (x > t)
            k += x - (t + 1);
    }
    return k;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned t = 1;
    for (unsigned i = 2; i < 100; ++i) {
        if (v(a, i) < v(a, t))
            t = i;
    }

    answer(t, v(a, t));
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

