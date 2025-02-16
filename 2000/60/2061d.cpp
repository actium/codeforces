#include <iostream>
#include <queue>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    std::priority_queue<unsigned> p(a.begin(), a.end()), q(b.begin(), b.end());
    while (!q.empty() && p.size() > q.size()) {
        const unsigned u = p.top(), v = q.top();
        if (u > v)
            return answer(false);

        q.pop();

        if (u == v) {
            p.pop();
        } else {
            q.push(v / 2);
            q.push((v + 1) / 2);
        }
    }

    while (!q.empty() && p.top() == q.top()) {
        p.pop();
        q.pop();
    }

    answer(p.empty());
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);
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
