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

void answer(int x, const std::vector<std::vector<int>>& y)
{
    std::cout << x << '\n';

    for (const std::vector<int>& v : y) {
        const char* separator = "";
        for (const int x : v) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

bool test(const std::vector<std::vector<int>>& s, int t)
{
    const size_t n = s.size();

    int v[10] = {};
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            v[i] += s[i][j];
            v[n+j] += s[i][j];
        }
        v[2*n] += s[i][i];
        v[2*n+1] += s[i][n-1-i];
    }

    for (size_t i = 0; i < 2 * n + 2; ++i) {
        if (v[i] != t)
            return false;
    }
    return true;
}

bool search(size_t n, std::vector<int>& a, int t, std::vector<std::vector<int>>& s)
{
    if (s.size() == n && s.back().size() == n)
        return test(s, t);

    if (s.empty() || s.back().size() == n)
        s.emplace_back();

    const auto check = [&](size_t x) {
        const int v = a[x];
        a[x] = a.back();
        a.pop_back();

        s.back().push_back(v);
        if (search(n, a, t, s))
            return true;

        s.back().pop_back();
        a.push_back(v);
        return false;
    };

    if (s.back().size() == n - 1) {
        int v = 0;
        for (const int x : s.back())
            v += x;

        const size_t x = std::find(a.begin(), a.end(), t - v) - a.begin();
        if (x < a.size() && check(x))
            return true;
    } else {
        std::vector<int> v;
        for (size_t i = 0; i < a.size(); ++i) {
            if (std::find(v.begin(), v.end(), a[i]) != v.end())
                continue;

            v.push_back(a[i]);

            if (check(i))
                return true;
        }
    }

    if (s.back().empty())
        s.pop_back();

    return false;
}

void solve(size_t n, std::vector<int>& a)
{
    int t = 0;
    for (const int x : a)
        t += x;

    t /= int(n);

    std::vector<std::vector<int>> s;
    if (n < 4) {
        std::sort(a.begin(), a.end());

        s.resize(n, std::vector<int>(n));
        while (true) {
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < n; ++j)
                    s[i][j] = a[i * n + j];
            }

            if (test(s, t))
                break;

            std::next_permutation(a.begin(), a.end());
        }
    } else {
        search(n, a, t, s);
    }

    answer(t, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n * n);
    std::cin >> a;

    solve(n, a);

    return 0;
}
