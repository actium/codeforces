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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p, unsigned k)
{
    unsigned lb = k - 1, ub = k + 1;
    for (const auto& q : p) {
        if (q.first == k)
            lb = k;

        if (q.second == k)
            ub = k;
    }

    answer(lb == ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
