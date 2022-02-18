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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& t)
{
    const size_t n = t.size();

    unsigned x = t[0].first, k = std::min<unsigned>(n, 2);
    for (size_t i = 1; i + 1 < n; ++i) {
        if (x + t[i].second < t[i].first) {
            x = t[i].first;
            ++k;
            continue;
        }
        if (t[i].first + t[i].second < t[i+1].first) {
            x = t[i].first + t[i].second;
            ++k;
            continue;
        }
        x = t[i].first;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}
