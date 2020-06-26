#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<size_t>& a, size_t n)
{
    size_t min = 0;
    std::vector<size_t> min_heap = a;
    std::sort(min_heap.rbegin(), min_heap.rend());
    for (size_t i = 0; i < n; ++i) {
        min += min_heap.back();

        if (min_heap.back() == 1) {
            min_heap.pop_back();
        } else {
            --min_heap.back();
            std::sort(min_heap.rbegin(), min_heap.rend());
        }
    }

    size_t max = 0;
    std::vector<size_t> max_heap = a;
    std::sort(max_heap.begin(), max_heap.end());
    for (size_t i = 0; i < n; ++i) {
        max += max_heap.back();

        if (max_heap.back() == 1) {
            max_heap.pop_back();
        } else {
            --max_heap.back();
            std::sort(max_heap.begin(), max_heap.end());
        }
    }

    answer(max, min);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> a(m);
    std::cin >> a;

    solve(a, n);

    return 0;
}

