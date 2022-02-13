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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0) {
            q[i] = std::min(i, k) + std::min(n - i, 1 + k);
        } else {
            const size_t p = a[i] - 1;
            q[i] = q[p];

            if (p + k < i) {
                q[i] += std::min(i - (p + 1 + k), k) + std::min(n - i, 1 + k);
            } else {
                const size_t x = std::min(i + 1 + k, n);
                q[i] += x - std::min(p + 1 + k, n);
            }
        }
    }

    answer(q);
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
