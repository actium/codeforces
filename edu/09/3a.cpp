#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(unsigned v, integer k)
{
    std::cout << v << ' ' << k << '\n';
}

void solve(const std::vector<unsigned>& a, integer p)
{
    const size_t n = a.size();

    integer s = 0;
    for (const unsigned x : a)
        s += x;

    const integer c = p / s, r = p % s;
    if (r == 0)
        return answer(1, c * n);

    s = 0;

    size_t x = 0, k = n;
    for (size_t i = 0, j = 0; i < n; ++j) {
        for (s += a[j % n]; s >= r; s -= a[i++ % n]) {
            if (j - i + 1 < k)
                x = i, k = j - i + 1;
        }
    }

    answer(1 + x, c * n + k);
}

int main()
{
    size_t n;
    std::cin >> n;

    integer b;
    std::cin >> b;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, b);

    return 0;
}

