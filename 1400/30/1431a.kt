fun answer(v:Long)
{
    println("${v}")
}

fun solve(a:List<Long>)
{
    val n = a.size

    var r:Long = 0
    for (i in 0..n-1) {
        var k = 0
        for (j in 0..n-1) {
            if (a[j] >= a[i]) {
                ++k
            }
        }
        r = maxOf(r, k * a[i])
    }

    answer(r)
}

fun test_case()
{
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toLong)
    solve(a)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}

