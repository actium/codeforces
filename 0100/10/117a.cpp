#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Person {
    unsigned s;
    unsigned f;
    unsigned t;
};

std::istream& operator >>(std::istream& input, Person& v)
{
    return input >> v.s >> v.f >> v.t;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<Person>& p, unsigned m)
{
    for (const Person& q : p) {
        if (q.s == q.f) {
            answer(q.t);
            continue;
        }

        unsigned x = 1 + q.t % (2 * m - 2);
        if (x <= m) {
            if (q.s < q.f) {
                answer(q.t + (x <= q.s ? q.f - x : m - x + m - 1 + q.f - 1));
            } else {
                answer(q.t + m - x + m - q.f);
            }
        } else {
            x = 2 * m - x;
            if (q.s < q.f) {
                answer(q.t + x - 1 + q.f - 1);
            } else {
                answer(q.t + (x < q.s ? x - 1 + m - 1 + m - q.f : x - q.f));
            }
        }
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<Person> p(n);
    std::cin >> p;

    solve(p, m);

    return 0;
}

