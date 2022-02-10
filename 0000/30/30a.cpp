#include <iostream>

void answer(int x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "No solution" << '\n';
}

void solve(int a, int b, int n)
{
    const auto test = [=](int x) {
        int v = 1;
        for (int i = 0; i < n && v <= 1000; ++i)
            v *= x;

        return a * v == b;
    };

    for (int x = -1000; x <= 1000; ++x) {
        if (test(x))
            return answer(x);
    }

    no_answer();
}

int main()
{
    int a, b, n;
    std::cin >> a >> b >> n;

    solve(a, b, n);

    return 0;
}
