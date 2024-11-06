#include <iostream>
#include <map>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    std::map<integer, std::vector<integer>> s;
    for (size_t i = 0; i < n; ++i)
        s[a[i]+i].push_back(a[i] + 2 * i);

    std::set<integer> q;
    q.insert(n);
    for (auto it = q.begin(); it != q.end(); ++it) {
        const auto jt = s.find(*it);
        if (jt != s.end())
            q.insert(jt->second.begin(), jt->second.end());
    }

    answer(*q.rbegin());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);
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
