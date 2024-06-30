#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

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

void answer(const std::vector<integer>& v)
{
    for (const integer x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& v, size_t k)
{
    const size_t n = v.size();

    std::priority_queue<integer, std::vector<integer>, std::greater<integer>> q;
    for (size_t i = 0; i < k; ++i)
        q.push(0);

    std::vector<integer> e(n);
    for (size_t i = 0; i < n; ++i) {
        const integer t = std::max<integer>(q.top(), v[i].first);
        q.pop();

        e[i] = t + v[i].second;
        q.push(e[i]);
    }

    answer(e);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> v(n);
    std::cin >> v;

    solve(v, k);

    return 0;
}
