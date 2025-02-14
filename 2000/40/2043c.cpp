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

void answer(const std::vector<int>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

template <typename Iterator>
std::pair<int, int> scan(Iterator begin, Iterator end)
{
    std::pair<int, int> r = { 0, 0 };
    for (int s = 0; begin != end; ++begin) {
        s += *begin;
        r.first = std::min(r.first, s);
        r.second = std::max(r.second, s);
    }
    return r;
}

std::pair<int, int> search(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::pair<int, int> min = { 0, 0 }, max = { 0, 0 };
    for (size_t i = 0; i < n; ++i) {
        if (abs(a[i]) != 1) {
            min.second = 0;
            max.second = 0;
        } else {
            min.second = std::min(min.second + a[i], a[i]);
            min.first = std::min(min.first, min.second);
            max.second = std::max(max.second + a[i], a[i]);
            max.first = std::max(max.first, max.second);
        }
    }
    return { min.first, max.first };
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    size_t x = 0;
    while (x < n && abs(a[x]) == 1)
        ++x;

    x %= n;

    const std::pair<int, int> r1 = scan(a.begin(), a.begin() + x);
    const std::pair<int, int> r2 = scan(a.rend() - x, a.rend());
    const std::pair<int, int> r3 = scan(a.begin() + x + 1, a.end());
    const std::pair<int, int> r4 = scan(a.rbegin(), a.rend() - x - 1);
    const std::pair<int, int> r5 = search(a);

    std::vector<int> v;

    const auto insert = [&](int lb, int ub) {
        for (int i = lb; i <= ub; ++i)
            v.push_back(i);
    };

    insert(r1.first, r1.second);
    insert(r2.first, r2.second);
    insert(r3.first, r3.second);
    insert(r4.first, r4.second);

    insert(a[x] + r2.first + r3.first, a[x] + r2.second + r3.second);

    insert(r5.first, 0);
    insert(0, r5.second);

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

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
