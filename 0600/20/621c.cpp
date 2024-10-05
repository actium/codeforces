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

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& b, unsigned p)
{
    using integer = unsigned long long;

    const size_t n = b.size() - 1;

    double v = 0;
    for (size_t i = 0, j = 1; i < n; i = j++) {
        const integer di = b[i].second / p - (b[i].first - 1) / p, ti = b[i].second - b[i].first + 1;
        const integer dj = b[j].second / p - (b[j].first - 1) / p, tj = b[j].second - b[j].first + 1;

        v += (ti * tj - (ti - di) * (tj - dj)) * 2000.0 / (ti * tj);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned p;
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> b(n);
    std::cin >> b;

    b.push_back(b[0]);  // sentinel

    solve(b, p);

    return 0;
}
