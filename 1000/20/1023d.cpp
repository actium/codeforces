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
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<unsigned>& a, size_t q)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> p(1+q);
    for (size_t i = 0; i < n; ++i)
        p[a[i]].push_back(i);

    if (p[q].empty()) {
        if (p[0].empty())
            return no_answer();

        a[p[0].back()] = q;
        p[q].push_back(p[0].back());
    }

    std::vector<size_t> s(n);
    for (size_t i = 0; i < n; ++i)
        s[i] = i+1;

    for (size_t i = q; i > 0; --i) {
        if (p[i].size() < 2)
            continue;

        for (size_t j = p[i].front(); j < p[i].back(); j = s[j]) {
            if (a[j] == 0)
                a[j] = i;

            if (a[j] < i)
                return no_answer();
        }
        s[p[i].front()] = p[i].back() + 1;
    }

    for (size_t i = n-1; i > 0; --i) {
        if (a[i-1] == 0)
            a[i-1] = a[i];
    }
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == 0)
            a[i] = a[i-1];
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, q);

    return 0;
}
