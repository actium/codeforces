#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> t[31];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 31; ++j) {
            if ((a[i] & 1 << j) != 0)
                t[j].push_back(i);
        }
    }

    std::vector<unsigned> b;

    unsigned s = 0;
    for (size_t i = 31; i-- > 0; ) {
        if (t[i].empty() || (s & 1 << i) != 0)
            continue;

        size_t x = 0;
        for (const size_t j : t[i]) {
            if (a[j] == oo)
                continue;

            if (a[x] == oo || (s | a[j]) > (s | a[x]))
                x = j;
        }

        if (a[x] != oo) {
            b.push_back(a[x]);
            s |= a[x];
            a[x] = oo;
        }
    }

    for (const unsigned x : a) {
        if (x != oo)
            b.push_back(x);
    }

    answer(b);
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
