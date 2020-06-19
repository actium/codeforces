#include <iostream>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(size_t s, size_t v1, size_t v2, size_t t1, size_t t2)
{
    const size_t r1 = t1 + s * v1 + t1;
    const size_t r2 = t2 + s * v2 + t2;

    if (r1 < r2)
        return answer("First");

    if (r2 < r1)
        return answer("Second");

    answer("Friendship");
}

int main()
{
    size_t s, v1, v2, t1, t2;
    std::cin >> s >> v1 >> v2 >> t1 >> t2;

    solve(s, v1, v2, t1, t2);

    return 0;
}

