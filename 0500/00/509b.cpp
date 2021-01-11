#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << "YES" << '\n';

    for (const auto& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> b(k, { ~0u, 0 });
    for (size_t i = 0; i < n; ++i) {
        for (size_t c = 0; c < k; ++c) {
            const unsigned f = a[i] / k + (c < a[i] % k);

            b[c].first = std::min(b[c].first, f);
            b[c].second = std::max(b[c].second, f);

            if (b[c].second - b[c].first > 1)
                return no_answer();
        }
    }

    std::vector<std::vector<unsigned>> p(n);
    for (size_t i = 0; i < n; ++i) {
        p[i].resize(a[i]);

        for (unsigned c = 0; c < a[i]; ++c)
            p[i][c] = 1 + c % k;
    }

    answer(p);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

