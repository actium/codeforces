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

void solve(const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const auto check = [&](unsigned k) {
        int lb = 0, ub = 0;
        for (const std::pair<unsigned, unsigned>& r : s) {
            if (ub + k < r.first || r.second + k < lb)
                return false;

            lb = std::max<int>(lb - k, r.first);
            ub = std::min<int>(ub + k, r.second);
        }
        return true;
    };

    int lb = -1, ub = 1000000000;
    while (lb + 1 < ub) {
        const int mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);
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
