fun answer(s:List<Pair<String, Int>>)
{
    for (p in s) {
        println(p.first)
    }
}

fun solve(s:ArrayList<Pair<String, Int>>)
{
    answer(s.sortedWith(compareBy { it.second }))
}

fun main()
{
    val n = readLine()!!.toInt()

    var s = ArrayList<Pair<String, Int>>(n)
    for (i in 0 until n) {
        val (name, x) = readLine()!!.split(" ")
        s.add(Pair(name, x.toInt()))
    }

    solve(s)
}
