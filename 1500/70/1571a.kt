fun answer(v:String)
{
    println(v)
}

fun solve(s:String)
{
    when {
        s.all { it == '=' } -> answer("=")
        s.none { it == '<' } -> answer(">")
        s.none { it == '>' } -> answer("<")
        else -> answer("?")
    }
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
        test_case();
    }
}
