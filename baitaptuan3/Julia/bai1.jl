# Hàm lấy các vị trí lân cận (trên, dưới, trái, phải)
function get_neighbors(grid, position)
    x, y = position
    neighbors = []
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Trên, Dưới, Trái, Phải

    for (dx, dy) in directions
        nx, ny = x + dx, y + dy
        if nx >= 1 && nx <= size(grid, 1) && ny >= 1 && ny <= size(grid, 2)
            if grid[nx, ny] != 1  # 1 là chướng ngại vật
                push!(neighbors, (nx, ny))
            end
        end
    end
    return neighbors
end

# Hàm DFS tìm đường đi từ start đến goal
function dfs(grid, start, goal)
    stack = [start]
    visited = Set()
    parent = Dict{Tuple{Int, Int}, Tuple{Int, Int}}()

    while !isempty(stack)
        current = pop!(stack)

        if current == goal
            break
        end

        if current in visited
            continue
        end

        push!(visited, current)

        # Lấy các vị trí lân cận
        neighbors = get_neighbors(grid, current)
        for neighbor in neighbors
            if !(neighbor in visited)
                push!(stack, neighbor)
                parent[neighbor] = current
            end
        end
    end

    # Kiểm tra đường đi
    path = []
    if !(haskey(parent, goal)) && start != goal
        println("Không tìm thấy đường đi.")
        return path
    end

    # Xây dựng đường đi từ goal về start
    current = goal
    while current != start
        push!(path, current)
        current = get(parent, current, start)
    end
    push!(path, start)

    return reverse(path)
end

# Minh họa
grid = [
    [0 0 0 0 0],
    [1 1 0 1 0],
    [0 0 0 1 0],
    [0 1 1 1 0],
    [0 0 0 0 0]
]

start = (1, 1)
goal = (5, 5)
path = dfs(grid, start, goal)

if !isempty(path)
    println("Đường đi tìm được:")
    for p in path
        println(p)
    end
end
