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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& h, unsigned k)
{
    const size_t n = h.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&h](size_t a, size_t b) { return h[a] > h[b]; });

    std::vector<unsigned> b(n);
    for (const size_t i : x) {
        b[i] = h[i];

        if (i > 0 && b[i-1] != 0 && b[i]+k-1 < b[i-1])
            b[i] = b[i-1] + 1 - k;

        if (i+1 < n && b[i+1] != 0 && b[i]+k-1 < b[i+1])
            b[i] = b[i+1] + 1 - k;

        if (b[i] > h[i] + k - 1)
            return answer(false);
    }

    answer(b.front() == h.front() && b.back() == h.back());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

