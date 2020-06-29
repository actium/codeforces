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
    for (size_t i = 0, n = v.size(); i < n; i += 2) {
        std::cout << v[i] << ' ' << v[i+1] << '\n';
    }
}

void solve(std::vector<unsigned>& a)
{
    const size_t k = a.size();
    const size_t n = k / 2;

    std::vector<size_t> b[2];
    for (size_t i = 0; i < k; ++i)
        b[a[i] % 2].push_back(i + 1);

    if (b[0].size() % 2 != 0) {
        b[0].pop_back();
        b[1].pop_back();
    } else if (!b[0].empty()) {
        b[0].pop_back();
        b[0].pop_back();
    } else {
        b[1].pop_back();
        b[1].pop_back();
    }

    answer(b[0]);
    answer(b[1]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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

