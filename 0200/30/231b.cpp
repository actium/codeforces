#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool solve(std::vector<unsigned>& a, size_t n, int d, int l)
{
    if (a.size() == n - 1) {
        if (d < 1 || d > l)
            return false;

        a.push_back(d);
        return true;
    }

    a.push_back(d <= 0 ? 1 : l);
    return solve(a, n, a.back() - d, l);
}

void solve(size_t n, int d, int l)
{
    std::vector<unsigned> a;
    if (!solve(a, n, d, l))
        return no_answer();

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    int d, l;
    std::cin >> d >> l;

    solve(n, d, l);

    return 0;
}
