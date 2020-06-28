#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, std::pair<size_t, int>> d;
    size_t invalid_x_count = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = a[i];

        const auto it = d.find(x);
        if (it == d.end()) {
            d.emplace(x, std::make_pair(i, 0));
        } else {
            const size_t last_p = it->second.second;
            if (last_p == -1)
                continue;

            const size_t last_i = it->second.first;
            it->second.first = i;

            if (last_p == 0) {
                it->second.second = i - last_i;
            } else if (i - last_i != last_p) {
                it->second.second = -1;
                ++invalid_x_count;
            }
        }
    }

    std::cout << d.size() - invalid_x_count << '\n';
    for (const auto& entry : d) {
        const int p = entry.second.second;
        if (p != -1)
            answer(entry.first, p);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

