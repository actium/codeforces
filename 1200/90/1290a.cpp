#include <deque>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned m, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> s(m);
    for (size_t i = 0; i < m; ++i)
        s[i] = std::max(a[i], a[n-m+i]);

    k = std::min(k, m - 1);

    unsigned x = 0;
    {
        std::deque<unsigned> q;
        for (unsigned i = 0, j = 0; i <= k; ++i) {
            while (!q.empty() && q.front() < i)
                q.pop_front();

            while (j + k < i + m) {
                while (!q.empty() && s[q.back()] >= s[j])
                    q.pop_back();

                q.push_back(j++);
            }

            x = std::max(x, s[q.front()]);
        }
    }
    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);
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
