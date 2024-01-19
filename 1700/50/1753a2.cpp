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

    std::vector<std::pair<size_t, size_t>> v(1);

    int s = a[0], f = -1;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == 0) {
            ++v.back().second;
            f = -f;
            continue;
        }

        if (s == 0) {
            v.emplace_back(i, i);
            s = a[i];
            f = -1;
            continue;
        }

        if (s + f * a[i] == 0) {
            ++v.back().second;
            s = 0;
            continue;
        }

        if (s + a[i] == 0) {
            v.emplace_back(i, i);
        } else {
            --v.back().second;
            v.emplace_back(i-1, i);
        }
        s = 0;
    }

    s == 0 ? answer(v) : no_answer();
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
