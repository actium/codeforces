#include <algorithm>
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

    std::vector<unsigned> b = a;
    std::sort(b.begin(), b.end());

    size_t l = 0;
    while (l < n && a[l] == b[l])
        ++l;

    size_t r = n-1;
    while (r > l && a[r] == b[r])
        --r;

    unsigned k = 0;
    if (l < r) {
        for (++k; l < r; ++l) {
            if (a[l] == b[l]) {
                ++k;
                break;
            }
        }
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

