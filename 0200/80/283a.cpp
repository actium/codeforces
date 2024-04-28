#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    union {
        struct {
            int a;
            int x;
        };
        int k;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    if (q.t == 1)
        input >> q.a >> q.x;
    if (q.t == 2)
        input >> q.k;

    return input;
}

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const std::vector<Query>& r)
{
    std::vector<int> s(1), d(1);
    double t = 0;
    for (const Query& q : r) {
        switch (q.t) {
            case 1:
                d[q.a-1] += q.x;
                t += q.a * q.x;
                break;

            case 2:
                s.push_back(q.k);
                d.push_back(0);
                t += q.k;
                break;

            case 3:
                t -= s.back() + d.back();
                d.end()[-2] += d.end()[-1];
                s.pop_back();
                d.pop_back();
                break;
        }

        answer(t / s.size());
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Query> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
