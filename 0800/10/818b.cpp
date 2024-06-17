#include <iostream>
#include <vector>

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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, const std::vector<unsigned>& l)
{
    const size_t m = l.size();

    std::vector<unsigned> a(n);
    for (size_t i = 0; i + 1 < m; ++i) {
        const unsigned x = (l[i] < l[i+1] ? l[i+1] - l[i] : l[i+1] + n - l[i]);
        if (a[l[i]-1] != 0 && a[l[i]-1] != x)
            return no_answer();

        a[l[i]-1] = x;
    }

    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0)
            continue;

        if (v[a[i]-1])
            return no_answer();

        v[a[i]-1] = true;
    }

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (a[i] != 0)
            continue;

        while (v[j])
            ++j;

        a[i] = j + 1;
        v[j] = true;
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> l(m);
    std::cin >> l;

    solve(n, l);

    return 0;
}
