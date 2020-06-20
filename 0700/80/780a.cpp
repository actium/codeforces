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

void solve(const std::vector<size_t>& x)
{
    size_t max_count = 0;

    std::vector<bool> y(x.size() / 2);
    size_t current_count = 0;
    for (const size_t a : x) {
        if (y[a-1]) {
            --current_count;
        } else {
            y[a-1] = true;
            ++current_count;
        }

        max_count = std::max(max_count, current_count);
    }

    answer(max_count);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> x(2 * n);
    std::cin >> x;

    solve(x);

    return 0;
}

