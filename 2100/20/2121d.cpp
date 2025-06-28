#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> c;

    const auto sort = [&](std::vector<unsigned>& v, unsigned t) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i; j > 0 && v[j] < v[j-1]; --j) {
                c.emplace_back(t, j);
                std::swap(v[j-1], v[j]);
            }
        }
    };

    sort(a, 1);
    sort(b, 2);

    for (size_t i = 0; i < n; ++i) {
        if (a[i] > b[i])
            c.emplace_back(3, i+1);
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
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
