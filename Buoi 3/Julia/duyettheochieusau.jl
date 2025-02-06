function dfs(graph, start)
    stack = [start]
    visited = Set()

    while !isempty(stack)
        vertex = pop!(stack)
        if vertex ∉ visited
            print(vertex, " ")
            push!(visited, vertex)
            # Thêm các nút kề vào ngăn xếp (đảo ngược để duyệt theo thứ tự)
            neighbors = reverse(graph[vertex])
            append!(stack, neighbors)
            println("Da them cac nut ke cua '$vertex' vao ngan xep: ", neighbors)
        end
    end
    println()
end

# Minh họa
graph = Dict(
    "A" => ["B", "C"],
    "B" => ["D", "E"],
    "C" => ["F"],
    "D" => [],
    "E" => ["F"],
    "F" => []
)

println("DFS tu nut A:")
dfs(graph, "A")  # Output: A C F B E D
