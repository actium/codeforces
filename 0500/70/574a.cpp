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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned b = a[0];

    std::priority_queue<unsigned> q(a.cbegin() + 1, a.cend());
    for (unsigned x = q.top(); x >= b; x = q.top()) {
        q.pop();
        ++b;
        q.push(x-1);
    }

    answer(b - a[0]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

