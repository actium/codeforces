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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1 + n);
    for (const unsigned x : a)
        ++f[x];

    const auto select = [&]() -> size_t {
        const size_t k = a.size();
        if (k < 3)
            return 0;

        for (unsigned x = 1; x <= n; ++x) {
            if (f[x] < 2)
                continue;

            for (size_t i = 0; i < k; ++i) {
                if (a[i] == x && a[(i + 1) % k] != a[(k + i - 1) % k])
                    return i;
            }
        }

        for (size_t i = 0; i < k; ++i) {
            if (f[i] > 1)
                return i;
        }

        return 0;
    };

    const auto erase = [&](size_t x) {
        --f[a[x]];
        a.erase(a.begin() + x);
    };

    unsigned k = 0;
    while (!a.empty()) {
        const size_t x = select();
        erase(x);
        ++k;

        for (size_t q = a.size(); q > 1 && a[x % q] == a[(q + x - 1) % q]; --q)
            erase(x % q);
    }

    answer(k);
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
