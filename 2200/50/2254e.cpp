#include <iostream>
#include <set>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<int>& b)
{
    std::multiset<integer> q(b.begin(), b.end());

    std::vector<integer> a;
    for (integer x = 0; !q.empty(); ) {
        const auto it = q.upper_bound(-x);
        if (it == q.end())
            return no_answer();

        x += *it;
        a.push_back(x);
        q.erase(it);
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> b(n);
    std::cin >> b;

    solve(b);
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
