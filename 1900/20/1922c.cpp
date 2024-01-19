#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    std::vector<integer> pc(1 + n);
    for (size_t i = 0; i < n; ++i) {
        pc[i+1] = pc[i];

        if (i == 0 || i + 1 < n && a[i+1] - a[i] < a[i] - a[i-1])
            pc[i+1] += 1;
        else if (i + 1 < n)
            pc[i+1] += a[i+1] - a[i];
    }

    std::vector<integer> sc(n + 1);
    for (size_t i = n; i > 0; --i) {
        sc[i-1] = sc[i];

        if (i == n || i > 1 && a[i-1] - a[i-2] < a[i] - a[i-1])
            sc[i-1] += 1;
        else if (i > 1)
            sc[i-1] += a[i-1] - a[i-2];
    }

    for (const std::pair<unsigned, unsigned>& q : r)
        answer(q.first < q.second ? pc[q.second-1] - pc[q.first-1] : sc[q.second] - sc[q.first]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(a, r);
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
