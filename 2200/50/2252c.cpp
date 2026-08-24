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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& v, const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = v.size(), m = a[0].size();

    unsigned k = m;

    std::vector<unsigned> t;
    for (size_t i = n-1; ~i != 0; --i) {
        t.insert(t.end(), a[i].begin(), a[i].end());
        std::sort(t.begin(), t.end(), std::greater<unsigned>());
        t.resize(k);

        unsigned q = 0, u = 0;
        while (q < k && u < v[i])
            u += t[q++];
        
        if (u >= v[i])
            k = q;
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> v(n);
    std::cin >> v;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(v, a);
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
