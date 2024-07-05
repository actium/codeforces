fun answer(v:Long)
{
    println("${v}")
}

fun solve(a:List<Int>, k:Int, x:Int, y:Int)
{
    var s:Long = 0
    for (v in a)
        s += v

    var p:Int = 0
    while (s > k.toLong() * a.size)
        s -= a[p++]

    var q:Int = p
    while (q < a.size && a[q] > k)
        ++q

    answer(minOf(p.toLong() * x + y, q.toLong() * x))
}

fun test_case()
{
    val (n, k, x, y) = readLine()!!.split(" ").map(String::toInt)
    val a = readLine()!!.split(" ").map(String::toInt).sortedDescending()
    solve(a, k, x, y)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
