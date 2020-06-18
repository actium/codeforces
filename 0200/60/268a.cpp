#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const size_t h_freq[101], const size_t a_freq[101])
{
    size_t count = 0;
    for (size_t i = 1; i < 101; ++i)
        count += h_freq[i] * a_freq[i];

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t h_freq[101] = {};
    size_t a_freq[101] = {};
    for (size_t i = 0; i < n; ++i) {
        unsigned h, a;
        std::cin >> h >> a;

        ++h_freq[h];
        ++a_freq[a];
    }

    solve(h_freq, a_freq);

    return 0;
}

