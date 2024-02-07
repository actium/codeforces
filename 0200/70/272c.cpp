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

void solve(std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& d)
{
    const size_t n = a.size();

    for (size_t i = 1; i < n; ++i)
        a[i] = std::max(a[i], a[i-1]);

    integer h = 0;
    for (const std::pair<unsigned, unsigned>& q : d) {
        h = std::max<integer>(h, a[q.first-1]);
        answer(h);
        h += q.second;
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> d(m);
    std::cin >> d;

    solve(a, d);

    return 0;
}
