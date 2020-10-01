#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned t, size_t c)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t l = 0, r = 0; r < n; ++r) {
        if (a[r] > t)
            l = r + 1;

        if (r - l + 1 == c) {
            ++k;
            ++l;
        }
    }

    answer(k);
}

int main()
{
    size_t n, c;
    std::cin >> n;

    unsigned t;
    std::cin >> t >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, t, c);

    return 0;
}

