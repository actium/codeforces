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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t k = a.size(), n = b.size();

    std::vector<std::vector<unsigned>> d(1+k);
    for (size_t i = 0; i < n; ++i)
        d[b[i]-1].push_back(i + 1);

    a.push_back(n);     // sentinel

    std::vector<unsigned> q;
    while (d[k].size() < n) {
        for (size_t i = k; i > 0; --i) {
            while (!d[i-1].empty() && d[i].size() < a[i]) {
                q.push_back(d[i-1].back());
                d[i].push_back(d[i-1].back());
                d[i-1].pop_back();
            }
        }
    }

    answer(q);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(k), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
