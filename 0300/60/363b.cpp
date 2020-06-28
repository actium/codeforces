#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& h, size_t k, size_t sum)
{
    const size_t n = h.size();

    size_t best_sum = sum, best_i = 1;
    for (size_t i = k; i < n; ++i) {
        sum -= h[i - k];
        sum += h[i];
        if (sum < best_sum) {
            best_sum = sum;
            best_i = i - k + 2;
        }
    }

    answer(best_i);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> h(n);
    size_t sum = 0;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> h[i];
        if (i < k)
            sum += h[i];
    }

    solve(h, k, sum);

    return 0;
}

