#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << separator << 1 + *it;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& t, const std::vector<unsigned>& a)
{
    const size_t n = t.size();

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != 0)
            ++d[a[i]-1];
    }

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (t[i] == 0)
            continue;

        std::vector<size_t> q = { i };
        while (a[q.back()] != 0 && d[a[q.back()]-1] == 1)
            q.push_back(a[q.back()] - 1);

        if (q.size() > p.size())
            std::swap(p, q);
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n), a(n);
    std::cin >> t >> a;

    solve(t, a);

    return 0;
}
