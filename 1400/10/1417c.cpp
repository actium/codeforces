#include <iostream>
#include <set>
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
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

bool check(const std::vector<size_t>& p, size_t k, size_t n)
{
    if (p.size() < n / k)
        return false;

    size_t l = -1;
    for (const size_t r : p) {
        if (r - l > k)
            return false;

        l = r;
    }

    return l + k >= n;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::set<unsigned> c(a.cbegin(), a.cend());
    if (c.size() == 1)
        return answer(std::vector<int>(n, a[0]));

    std::vector<std::vector<size_t>> p(n);
    for (size_t i = 0; i < n; ++i)
        p[a[i]-1].push_back(i);

    std::vector<int> w(n, -1);
    for (size_t k = n - 1; !c.empty() && k > 0; --k) {
        auto it = c.begin();
        w[k] = *it;
        while (it != c.end() && !check(p[*it-1], k, n))
            it = c.erase(it);
    }

    answer(w);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t = 1;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

