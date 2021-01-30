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

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> f(100001);

    integer c = 0, t = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        if (f[a[j]]++ == 0)
            ++c;

        while (c > k) {
            if (--f[a[i++]] == 0)
                --c;
        }

        t += j - i + 1;
    }

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

