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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& p, unsigned lb, unsigned ub)
{
    const size_t n = a.size();

    std::vector<size_t> s(n);
    for (size_t i = 0; i < n; ++i)
        s[i] = i;

    std::sort(s.begin(), s.end(), [&](size_t i, size_t j) { return p[i] < p[j]; });

    std::vector<int> b(n);
    b[s[0]] = lb;
    for (size_t i = 1; i < n; ++i)
        b[s[i]] = b[s[i-1]] - a[s[i-1]] + a[s[i]] + 1;

    const int d = *std::min_element(b.begin(), b.end());

    for (size_t i = 0; i < n; ++i) {
        b[i] += lb - d;

        if (b[i] > ub)
            return no_answer();
    }

    answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned lb, ub;
    std::cin >> lb >> ub;

    std::vector<unsigned> a(n), p(n);
    std::cin >> a >> p;

    solve(a, p, lb, ub);

    return 0;
}
