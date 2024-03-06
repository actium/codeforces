#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename Iterator>
void prepare(Iterator begin, Iterator end, std::vector<unsigned>& v)
{
    std::set<unsigned> s;
    unsigned x = 0;
    for (auto it = begin; it != end; ++it) {
        s.insert(*it);

        while (s.count(x) == 1)
            ++x;

        v.push_back(x);
    }
}

void answer(const std::pair<unsigned, unsigned>& x, const std::pair<unsigned, unsigned>& y)
{
    std::cout << 2 << '\n';
    std::cout << x.first << ' ' << x.second << '\n';
    std::cout << y.first << ' ' << y.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p;
    prepare(a.begin(), a.end(), p);

    std::vector<unsigned> s;
    prepare(a.rbegin(), a.rend(), s);

    for (size_t i = 1; i < n; ++i) {
        if (p[i-1] == s[n-i-1])
            return answer({1, i}, {i+1, n});
    }

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
