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

void solve(const std::vector<std::pair<unsigned, unsigned>>& r)
{
    std::vector<unsigned> s;

    unsigned lb = 0, ub = ~0u;
    for (const std::pair<unsigned, unsigned>& c : r) {
        switch (c.first) {
            case 1: lb = std::max(lb, c.second); break;
            case 2: ub = std::min(ub, c.second); break;
            case 3: s.push_back(c.second); break;
        }
    }

    if (ub < lb)
        return answer(0);

    unsigned k = ub - lb + 1;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= lb && s[i] <= ub)
            --k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    solve(r);
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
