fun answer(u:Int, v:Int)
{
    println("${u} ${v}")
}

fun no_answer()
{
    println("-1")
}

fun check(s:String):Boolean
{
    var b:Int = 0
    for (c in s) {
        b += if (c == '-') -1 else 1
        if (b < 0)
            return false
    }
    return true
}

fun solve(s:String)
{
    if (s.count { it == '-' } > s.count { it == '+' })
        return no_answer()

    if (check(s))
        return answer(1, 1)

    var t = StringBuilder(s)

    val u = s.indexOf('-')
    t[u] = '+'

    val v = s.lastIndexOf('+')
    t[v] = '-'

    if (check(t.toString()))
        return answer(u+1, v+1)

    no_answer()
}

fun test_case()
{
    val s = readLine()!!
    solve(s)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
