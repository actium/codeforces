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

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, double>>& e)
{
    unsigned x = a.size();
    while (x > 0 && a[x-1] == x)
        --x;

    if (x == 0)
        return answer(1.0);

    double p = 1;
    for (const auto& v : e) {
        if (v.first >= x)
            p *= 1 - v.second;
    }

    answer(1 - p);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, double>> e(m);
    std::cin >> e;

    solve(a, e);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

