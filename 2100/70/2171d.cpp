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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<unsigned> q = { p[0] };
    for (size_t i = 1; i < n; ++i) {
        if (p[i] < q.back())
            q.emplace_back(p[i]);

        for (size_t k = q.size(); k > 1 && p[i] > q[k-2]; --k) {
            q[k-2] = q[k-1];
            q.pop_back();
        }
    }

    answer(q.size() == 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
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
