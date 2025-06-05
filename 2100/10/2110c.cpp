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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<int>& d, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = d.size();

    std::vector<size_t> p;
    {
        unsigned lb = 0, h = 0;
        for (size_t i = 0; i < n; ++i) {
            lb = std::max(lb, r[i].first);

            if (d[i] == -1)
                p.push_back(i);
            else
                h += d[i];

            while (h < lb && !p.empty()) {
                d[p.back()] = 1;
                p.pop_back();
                ++h;
            }
        }

        for (const size_t i : p)
            d[i] = 0;
    }

    for (size_t i = 0, h = 0; i < n; ++i) {
        h += d[i];

        if (h < r[i].first || h > r[i].second)
            return no_answer();
    }

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> d(n);
    std::cin >> d;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    solve(d, r);
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
