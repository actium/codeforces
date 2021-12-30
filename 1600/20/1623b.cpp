#include <iostream>
#include <vector>

using range_t = std::pair<unsigned, unsigned>;

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

void solve(const std::vector<range_t>& r)
{
    const size_t n = r.size();

    std::vector<std::vector<bool>> v(1+n, std::vector<bool>(1+n));
    for (const auto& q : r)
        v[q.first][q.second] = true;

    for (const auto& q : r) {
        for (unsigned d = q.first; d <= q.second; ++d) {
            if ((d == q.first || v[q.first][d-1]) && (d == q.second || v[d+1][q.second])) {
                std::cout << q.first << ' ' << q.second << ' ' << d << '\n';
                break;
            }
        }
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<range_t> r(n);
    std::cin >> r;

    solve(r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
