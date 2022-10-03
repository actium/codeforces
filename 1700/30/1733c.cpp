#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();
    if (n == 1)
        return answer({});

    std::vector<std::pair<size_t, size_t>> p;
    p.emplace_back(0, n-1);

    const unsigned x = (a[0] % 2 == a[n-1] % 2 ? a[n-1] : a[0]) % 2;

    for (size_t i = 1; i < n-1; ++i) {
        if (a[i] % 2 == x) {
            p.emplace_back(i, n-1);
        } else {
            p.emplace_back(0, i);
        }
    }

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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
