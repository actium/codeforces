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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p, q;
    for (size_t i = 0, x = 0; i < n; ++i) {
        while (!p.empty() && a[i] < p.back()) {
            q.push_back(p.back() + 1);
            p.pop_back();

            if (q.back() < q[x])
                x = q.size() - 1;
        }

        if (!q.empty() && q[x] < a[i])
            q.push_back(a[i] + 1);
        else
            p.push_back(a[i]);
    }

    std::sort(q.begin(), q.end());
    p.insert(p.end(), q.begin(), q.end());

    answer(p);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
