#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::unordered_map<size_t, size_t> xa, xb;
    for (size_t i = 0; i < n; ++i) {
        xa[a[i]] = i;
        xb[b[i]] = i;
    }

    std::unordered_map<size_t, size_t> c;
    for (size_t i = 1; i <= n; ++i) {
        if (xb[i] >= xa[i]) {
            const size_t d = xb[i] - xa[i];
            ++c[d];
        } else {
            const size_t d = xb[i] + n - xa[i];
            ++c[d];
        }
    }

    size_t x = 0;
    for (const auto& e : c) {
        x = std::max(x, e.second);
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);
}

int main()
{
    test_case();

    return 0;
}

