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

void answer(const std::vector<std::pair<double, unsigned>>& v)
{
    for (const auto [s, i] : v)
        printf("%u %.2f\n", i, s);
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s, unsigned t1, unsigned t2, unsigned k)
{
    const size_t n = s.size();

    const auto c = [=](unsigned v1, unsigned v2) {
        double h = v1 * t1;
        h *= (100.0 - k) / 100;
        return h + v2 * t2;
    };

    std::vector<std::pair<double, unsigned>> v(n);
    for (size_t i = 0; i < n; ++i) {
        v[i].first = std::max(c(s[i].first, s[i].second), c(s[i].second, s[i].first));
        v[i].second = 1+i;
    }

    const auto compare = [](const std::pair<double, unsigned>& a, const std::pair<double, unsigned>& b) {
        if (a.first == b.first)
            return a.second < b.second;

        return a.first > b.first;
    };
    std::sort(v.begin(), v.end(), compare);

    answer(v);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned t1, t2, k;
    std::cin >> t1 >> t2 >> k;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, t1, t2, k);

    return 0;
}

