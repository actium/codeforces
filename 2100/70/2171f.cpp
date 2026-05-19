#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "YES" << '\n';
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<unsigned> q = { p[0] };
    std::vector<std::pair<unsigned, unsigned>> t;
    for (size_t i = 1; i < n; ++i) {
        if (p[i] < q.back())
            q.emplace_back(p[i]);
        else
            t.emplace_back(q.back(), p[i]);

        for (size_t k = q.size(); k > 1 && p[i] > q[k-2]; --k) {
            t.emplace_back(q[k-2], p[i]);
            q[k-2] = q[k-1];
            q.pop_back();
        }
    }

    q.size() == 1 ? answer(t) : no_answer();
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
