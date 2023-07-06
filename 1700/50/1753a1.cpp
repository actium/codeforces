#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& x)
{
    std::cout << x.size() << '\n';
    for (const std::pair<size_t, size_t>& p : x)
        std::cout << 1+p.first << ' ' << 1+p.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();
    if (n % 2 == 1)
        return no_answer();

    std::vector<std::pair<size_t, size_t>> v;
    for (size_t i = 1; i < n; i += 2) {
        if (a[i-1] == a[i]) {
            v.emplace_back(i-1, i);
        } else {
            v.emplace_back(i-1, i-1);
            v.emplace_back(i, i);
        }
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
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
