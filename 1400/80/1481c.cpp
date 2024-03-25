#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c)
{
    const size_t n = a.size(), m = c.size();

    std::map<unsigned, std::vector<size_t>> q;
    for (size_t i = 0; i < n; ++i) {
        if (b[i] != a[i])
            q[b[i]].push_back(i);
    }

    size_t x = n;
    for (size_t i = 0; i < n; ++i) {
        if (b[i] == c.back())
            x = i;

        if (b[i] == c.back() && a[i] != c.back())
            break;
    }
    if (x == n)
        return no_answer();

    std::vector<unsigned> s(m);
    for (size_t i = 0; i < m; ++i) {
        const auto it = q.find(c[i]);
        if (it != q.end()) {
            s[i] = it->second.back() + 1;
            it->second.pop_back();
            if (it->second.empty())
                q.erase(it);
        } else {
            s[i] = x + 1;
        }
    }

    if (!q.empty())
        return no_answer();

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(n), c(m);
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
