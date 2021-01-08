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

    std::vector<size_t> x;
    for (size_t i = 1; i < n-1; ++i) {
        if (a[i-1] < a[i] && a[i] > a[i+1])
            x.push_back(i);

        if (a[i-1] > a[i] && a[i] < a[i+1])
            x.push_back(i);
    }

    const auto check = [&](size_t i, unsigned v) {
        unsigned c[2] = {};

        if (i > 1) {
            c[0] += (a[i-2] < a[i-1] && a[i-1] > a[i]);
            c[0] += (a[i-2] > a[i-1] && a[i-1] < a[i]);

            c[1] += (a[i-2] < a[i-1] && a[i-1] > v);
            c[1] += (a[i-2] > a[i-1] && a[i-1] < v);
        }

        c[0] += (a[i-1] < a[i] && a[i] > a[i+1]);
        c[0] += (a[i-1] > a[i] && a[i] < a[i+1]);

        c[1] += (a[i-1] < v && v > a[i+1]);
        c[1] += (a[i-1] > v && v < a[i+1]);

        if (i+2 < n) {
            c[0] += (a[i] < a[i+1] && a[i+1] > a[i+2]);
            c[0] += (a[i] > a[i+1] && a[i+1] < a[i+2]);

            c[1] += (v < a[i+1] && a[i+1] > a[i+2]);
            c[1] += (v > a[i+1] && a[i+1] < a[i+2]);
        }

        return c[0] > c[1] ? c[0] - c[1] : 0;
    };

    unsigned d = 0;
    for (const size_t i : x) {
        d = std::max(d, check(i, a[i-1]));
        d = std::max(d, check(i, a[i+1]));
    }

    answer(x.size() - d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

