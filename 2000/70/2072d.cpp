#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

struct Candidate {
    unsigned s;
    unsigned t;
    unsigned k;
};

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    Candidate best = { 1, 1, 0 };
    for (size_t i = 0; i < n; ++i) {
        unsigned c[2] = {};
        for (size_t j = i+1; j < n; ++j) {
            if (a[j] < a[i])
                ++c[0];
            if (a[j] > a[i])
                ++c[1];

            if (c[0] > best.k + c[1]) {
                best.s = 1 + i;
                best.t = 1 + j;
                best.k = c[0] - c[1];
            }
        }
    }

    answer(best.s, best.t);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
