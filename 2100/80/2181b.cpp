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
    constexpr const char* s[2] = { "Alice", "Bob" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    std::priority_queue<unsigned> q[2] = { { a.begin(), a.end() }, { b.begin(), b.end() } };
    for (unsigned t = 0; !q[0].empty() && !q[1].empty(); t ^= 1) {
        const unsigned x = q[t].top(), y = q[t^1].top();
        q[t^1].pop();
        if (y > x)
            q[t^1].push(y - x);
    }

    answer(q[0].empty());
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
