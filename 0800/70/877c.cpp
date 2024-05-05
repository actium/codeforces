#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> q;

    const auto enqueue = [&](unsigned s) {
        for (unsigned x = s; x <= n; x += 2)
            q.push_back(x);
    };

    enqueue(2);
    enqueue(1);
    enqueue(2);

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
