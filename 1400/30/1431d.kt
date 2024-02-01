fun answer(v:ArrayList<Int>) {
    println(v.joinToString(" "))
}

fun solve(a:List<Int>)
{
    val n = a.size

    var p = ArrayList<Int>()
    for (i in 0 until n)
        p.add(i)

    p.sortWith(compareBy({ a[it] }))

    var q = ArrayList<Int>()

    var i = 0
    var j = n
    while (i < j) {
        var k = a[p[i]] - (if (i != 0) 1 else 0)
        while (k-- != 0 && --j > i)
            q.add(1 + p[j])

        q.add(1 + p[i++])
    }

    answer(q)
}

fun test_case()
{
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map(String::toInt)
    solve(a)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
