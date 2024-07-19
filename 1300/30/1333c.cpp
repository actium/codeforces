#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<long long> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    integer k = 0;
    {
        std::set<long long> s = { 0 };
        for (size_t i = 0, j = 0; i < n; ++i) {
            while (j < n && s.count(p[j+1]) == 0)
                s.insert(p[++j]);

            k += j - i;
            s.erase(p[i]);
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
