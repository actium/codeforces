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

void solve(const std::vector<unsigned>& p, size_t k)
{
    const size_t n = p.size();

    std::vector<unsigned> x(256, 256), r(n);
    for (size_t i = 0; i < n; ++i) {
        if (x[p[i]] == 256) {
            unsigned lb = p[i];
            while (lb > 0 && (x[lb-1] == 256 || p[i] - x[lb-1] + 1 <= k) && p[i] - lb + 1 < k)
                --lb;

            for (size_t j = lb; j <= p[i]; ++j)
                x[j] = lb;
        }

        r[i] = x[p[i]];
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, k);

    return 0;
}
