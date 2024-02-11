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

void answer(const std::vector<size_t>& v)
{
    const size_t k = v.size();

    std::cout << k - 1 << '\n';
    for (size_t i = 1; i < k; ++i)
        std::cout << 1 + v[i-1] << ' ' << v[i] << '\n';;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> s = { 0 };

    std::set<unsigned> v;
    for (size_t i = 0; i < n; ++i) {
        if (!v.insert(a[i]).second) {
            s.push_back(i + 1);
            v.clear();
        }
    }

    if (s.back() == 0)
        return no_answer();

    s.back() = n;

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
