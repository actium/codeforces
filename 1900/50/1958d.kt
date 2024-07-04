fun answer(v:Long)
{
    println("${v}")
}

fun solve(a:List<Int>)
{
    var c:Long = 0

    var b = ArrayList<Long>()
    for (i in 0 until a.size) {
        if (a[i] != 0)
            b.add(a[i].toLong())

        if (a[i] == 0 || i == a.size-1) {
            c += 2 * b.sum()

            if (b.size % 2 == 1)
                c -= b.slice(b.indices step 2).maxOrNull()!!

            b.clear()
        }
    }

    answer(c)
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
