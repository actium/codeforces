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
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    long long s = 0;
    for (const int x : a)
        s += x;

    std::pair<long long, size_t> b = { s, 0 }, c = b;
    for (size_t i = 1; i < n; ++i) {
        c.first -= 2 * a[i];
        if (a[i] > 0) {
            c.second = i;
            b = std::max(b, c);
            c.first += 2 * a[i];
        }
    }

    std::vector<size_t> q;
    if (b.second != 0) {
        for (size_t i = b.second - 1; i != 0; --i) {
            if ((a[i] > 0) == (q.size() % 2 == 0))
                q.push_back(i);
        }
        q.push_back(b.second);
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    a.insert(a.begin(), 0);
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
