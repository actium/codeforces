n := File standardInput readLine asBuffer
if (n slice(0, 1) == "-", n removePrefix("-" print))
n strip("0") reverse println
