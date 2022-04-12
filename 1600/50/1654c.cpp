#include <algorithm>
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

void solve(std::vector<unsigned>& a)
{
    using integer = unsigned long long;

    std::sort(a.begin(), a.end());

    integer w = 0;
    for (const unsigned x : a)
        w += x;

    std::priority_queue<integer> q;
    for (q.push(w); !q.empty() && !a.empty() && q.top() >= a.back(); ) {
        if (q.top() > a.back()) {
            const integer x = q.top();
            q.pop();
            q.push(x / 2);
            q.push((x + 1) / 2);
        } else {
            q.pop();
            a.pop_back();
        }
    }

    answer(a.empty());
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

