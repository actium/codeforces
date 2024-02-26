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

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a, size_t k)
{
    const size_t n = a.size();

    const auto check = [&](size_t b, size_t e) {
        std::vector<int> s;
        s.insert(s.end(), a.begin() + b, a.begin() + e);
        std::sort(s.begin(), s.end());

        std::vector<int> t;
        t.insert(t.end(), a.begin(), a.begin() + b);
        t.insert(t.end(), a.begin() + e, a.end());
        std::sort(t.begin(), t.end(), std::greater<int>());

        int v = 0;
        for (size_t i = 0; i < s.size(); ++i)
            v += i < k && i < t.size() ? std::max(s[i], t[i]) : s[i];

        return v;
    };

    int x = a[0];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j)
            x = std::max(x, check(i, j+1));
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
