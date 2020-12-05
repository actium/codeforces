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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned p[2] = {}, s[2] = {};
    for (size_t i = 0; i < n; ++i)
        s[i % 2] += a[i];

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        s[i % 2] -= a[i];

        if (p[0] + s[1] == p[1] + s[0])
            ++k;

        p[i % 2] += a[i];
    }

    answer(k);
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

