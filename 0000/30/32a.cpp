#include <iostream>
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

void solve(const std::vector<int>& h, size_t d)
{
    const size_t n = h.size();

    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (j != i && abs(h[j] - h[i]) <= d)
                ++k;
        }
    }

    answer(k);
}

int main()
{
    size_t n, d;
    std::cin >> n >> d;

    std::vector<int> h(n);
    std::cin >> h;

    solve(h, d);

    return 0;
}

