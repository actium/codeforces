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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    unsigned lb = x, ub = x;
    for (const auto& q : s) {
        if (q.first <= ub && q.second >= lb) {
            lb = std::min(lb, q.first);
            ub = std::max(ub, q.second);
        }
    }

    answer(ub - lb + 1);
}

void test_case()
{
    unsigned n, x, m;
    std::cin >> n >> x >> m;

    std::vector<std::pair<unsigned, unsigned>> s(m);
    std::cin >> s;

    solve(x, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

