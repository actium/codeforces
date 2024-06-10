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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    while (!a.empty() && !b.empty() && b.back() >= a.back()) {
        a.pop_back();
        b.pop_back();
    }

    answer(!a.empty());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
