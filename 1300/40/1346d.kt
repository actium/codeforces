fun answer(v:IntArray)
{
    val s = v.joinToString(" ")

    println("YES")
    println("${s}")
}

fun no_answer()
{
    println("NO")
}

fun solve(n:Int, t:ArrayList<Triple<Int, Int, Int>>)
{
    var a = IntArray(n)
    for (x in t) {
        a[x.first-1] = maxOf(a[x.first-1], x.third)
        a[x.second-1] = maxOf(a[x.second-1], x.third)
    }

    for (x in t) {
        if (minOf(a[x.first-1], a[x.second-1]) != x.third)
            return no_answer()
    }

    answer(a)
}

fun test_case()
{
    val (n, m) = readLine()!!.split(" ").map(String::toInt)

    var t = ArrayList<Triple<Int, Int, Int>>(m)
    for (i in 0 until m) {
        val (u, v, w) = readLine()!!.split(" ").map(String::toInt)
        t.add(Triple(u, v, w))
    }

    solve(n, t)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
