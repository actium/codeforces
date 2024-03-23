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

template <typename Iterator>
unsigned count(Iterator begin, Iterator end, int x)
{
    unsigned k = 0;
    {
        long long s = 0;

        std::multiset<int> q;
        for (auto it = begin; it != end; ++it) {
            q.insert(*it * x);

            for (s += *it * x; s < 0; ++k) {
                const int v = *q.begin();
                q.erase(q.begin());
                s -= 2 * v;
            }
        }
    }
    return k;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a, size_t m)
{
    answer(count(a.rbegin() + (a.size() - m), a.rend() - 1, -1) + count(a.begin() + m, a.end(), 1));
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, m);
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
