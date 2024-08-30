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

void solve(const std::vector<unsigned>& p, const std::vector<std::pair<unsigned, unsigned>>& b)
{
    const size_t n = b.size();

    unsigned k = 0;
    {
        std::vector<unsigned long long> s(n);
        for (size_t i = n-1; ~i != 0; --i) {
            if (s[i] < b[i].first) {
                s[p[i]-1] += b[i].second;
                ++k;
            } else {
                s[p[i]-1] += std::min(s[i], 0ull + b[i].second);
            }
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    p.insert(p.begin(), 1);

    std::vector<std::pair<unsigned, unsigned>> b(n);
    std::cin >> b;

    solve(p, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
