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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, const std::vector<unsigned>& c)
{
    unsigned d = 0, h = 0;
    {
        std::priority_queue<unsigned> q;
        q.push(0);
        for (const unsigned v : c) {
            if (d < v && q.top() > v) {
                d += q.top();
                q.pop();
                --h;
            }
            if (d >= v) {
                d -= v;
                q.push(v);
                ++h;
            }
            d += x;
        }
    }
    answer(h);
}

void test_case()
{
    size_t m;
    std::cin >> m;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> c(m);
    std::cin >> c;

    solve(x, c);
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
