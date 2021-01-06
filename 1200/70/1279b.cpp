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

void solve(const std::vector<unsigned>& a, unsigned s)
{
    const size_t n = a.size();

    size_t x = 0;
    for (size_t i = 1; i < n && std::min(a[i], a[x]) <= s; ++i) {
        s -= a[i];

        if (a[i] > a[x]) {
            s -= a[x];
            x = i;
            s += a[x];
        }
    }

    answer(a[x] > s ? 1+x : 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

