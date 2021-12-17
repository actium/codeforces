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

void solve(const std::vector<std::pair<unsigned, unsigned>>& ab, const std::vector<unsigned>& c)
{
    const size_t n = ab.size();

    unsigned t = ab[0].first + c[0];
    for (size_t i = 1; i < n; ++i) {
        const unsigned w = (ab[i-1].second - ab[i-1].first + 1) / 2;
        const unsigned d = std::max(t + w, ab[i-1].second);

        t = d + (ab[i].first - ab[i-1].second + c[i]);
    }

    answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> ab(n);
    std::cin >> ab;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(ab, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
