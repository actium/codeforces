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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    const auto check = [&](size_t x) {
        unsigned c = 0;
        {
            std::swap(a[k-1], a[x]);

            for (size_t w = 0, i = 1; i < n; ++i) {
                if (a[i] > a[w])
                    w = i;

                c += (w == x);
            }

            std::swap(a[k-1], a[x]);
        }
        return c;
    };

    size_t x = 0;
    while (a[x] < a[k-1])
        ++x;

    answer(std::max(check(1), check(x)));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
