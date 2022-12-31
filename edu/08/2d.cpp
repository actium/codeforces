#include <algorithm>
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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    std::vector<unsigned> d(n);
    for (const std::pair<unsigned, unsigned>& q : e) {
        ++d[q.first - 1];
        ++d[q.second - 1];
    }

    std::sort(d.begin(), d.end());

    unsigned k = 0;
    while (!d.empty()) {
        d.resize(d.size() - d.back() - 1);
        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(n, e);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
