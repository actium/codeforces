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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t n = a.size();

    std::vector<integer> p(1 + n);
    for (size_t i = 1; i < n; ++i) {
        p[i+1] = p[i] + std::max<int>(a[i-1] - a[i], 0);
    }

    std::vector<integer> s(1 + n);
    for (size_t i = 1; i < n; ++i) {
        s[n-i] = s[n-i+1] + std::max<int>(a[n-i] - a[n-i-1], 0);
    }

    for (const std::pair<unsigned, unsigned>& r : q) {
        if (r.first < r.second)
            answer(p[r.second] - p[r.first]);
        else
            answer(s[r.second] - s[r.first]);
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}
