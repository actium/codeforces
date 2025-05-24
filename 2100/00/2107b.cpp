#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    unsigned min = a[0], max = a[0], c = 0, p = 0;
    for (const unsigned x : a) {
        min = std::min(min, x);
        if (x > max) {
            max = x;
            c = 0;
        }
        c += (x == max);
        p += x % 2;
    }

    answer(max - min > k + 1 || max - min > k && c > 1 || p % 2 == 0 ? "Jerry" : "Tom");
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
