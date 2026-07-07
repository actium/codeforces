#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& c)
{
    unsigned q = 0;
    for (const auto x : c) {
        if (x > 2)
            return answer(true);

        q += (x == 2);
    }

    answer(q > 1);
}

void test_case()
{
    size_t k;
    std::cin >> k;

    std::vector<unsigned> c(k);
    std::cin >> c;

    solve(c);
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
