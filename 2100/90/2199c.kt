fun answer(r:String)
{
    println("YES")

    val k = r.length
    println("${k}")
    println(r)
    println(".".repeat(k))
}

fun no_answer()
{
    println("NO")
}

fun solve(k:Int)
{
    val sb = StringBuilder()
    when (k % 5) {
        0 -> {
            sb.append(".*.".repeat(k / 5))
            answer(sb.toString())
        }
        1 -> {
            sb.append("*")
            sb.append("..*".repeat(k / 5))
            answer(sb.toString())
        }
        3 -> {
            sb.append(".*")
            sb.append("..*".repeat(k / 5))
            answer(sb.toString())
        }
        else -> {
            no_answer()
        }
    }
}

fun test_case()
{
    val k = readLine()!!.toInt()

    solve(k)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
