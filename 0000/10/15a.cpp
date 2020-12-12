#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<int, unsigned>>& h, unsigned t)
{
    const size_t n = h.size();

    std::sort(h.begin(), h.end());

    unsigned k = 2;
    for (size_t i = 1; i < n; ++i) {
        const unsigned d = 2 * abs(h[i].first - h[i-1].first) - (h[i-1].second + h[i].second);
        if (d == 2 * t)
            ++k;

        if (d > 2 * t)
            k += 2;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned t;
    std::cin >> t;

    std::vector<std::pair<int, unsigned>> h(n);
    std::cin >> h;

    solve(h, t);

    return 0;
}

