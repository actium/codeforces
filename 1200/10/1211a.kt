fun answer(a:Int, b:Int, c:Int)
{
    println("${a} ${b} ${c}")
}

fun solve(r:List<Int>)
{
    val n = r.size
    for (b in 0..n-1) {
        var a = 0
        while (a < n && r[a] >= r[b])
            ++a

        var c = 0
        while (c < n && r[c] <= r[b])
            ++c

        if (a < n && c < n) {
            answer(1+a, 1+b, 1+c)
            return
        }
    }

    answer(-1, -1, -1)
}

fun main()
{
    val n = readLine()!!.toInt()
    val r = readLine()!!.split(" ").map(String::toInt)
    solve(r)
}

