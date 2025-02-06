mutable struct Queue
    elements::Vector{Any}  # Vector chứa các phần tử

    # Constructor khởi tạo hàng đợi rỗng sử dụng `new`
    Queue() = new(Vector{Any}())
end

# Hàm thêm phần tử vào hàng đợi
function enqueue!(q::Queue, item)
    push!(q.elements, item)
    println("Da them '$item' vao hang doi.")
end

# Hàm loại bỏ phần tử khỏi hàng đợi
function dequeue!(q::Queue)
    if !isempty(q.elements)
        item = popfirst!(q.elements)
        println("Da lay '$item' ra khoi hang doi.")
        return item
    else
        println("Hang doi trong!")
        return nothing
    end
end

# Hàm xem phần tử ở đầu hàng đợi
function front(q::Queue)
    if !isempty(q.elements)
        return q.elements[1]
    else
        println("Hang doi trong!")
        return nothing
    end
end

# Hàm kiểm tra hàng đợi rỗng
function is_empty(q::Queue)
    return isempty(q.elements)
end

# Hàm in nội dung hàng đợi
function display(q::Queue)
    println("Hang doi (dau den cuoi): ", q.elements)
end

# Minh họa sử dụng hàng đợi
function main()
    queue = Queue()
    enqueue!(queue, "Tai Lieu 1")
    enqueue!(queue, "Tai Lieu 2")
    enqueue!(queue, "Tai Lieu 3")
    display(queue)  # Output: Hang doi (dau den cuoi): ["Tai Lieu 1", "Tai Lieu 2", "Tai Lieu 3"]

    front_item = front(queue)
    println("Phan tu o dau hang doi: ", front_item)  # Output: Tai Lieu 1

    # dequeue phan tu khoi hang doi
    dequeue!(queue)
    display(queue)  # Output: Hang doi (dau den cuoi): ["Tai Lieu 2", "Tai Lieu 3"]

    # Kiem tra hang doi co trong khong
    println("Hang doi co trong khong? ", is_empty(queue) ? "Co" : "Khong")  # Output: Khong
end

main()  # Gọi hàm main để chạy chương trình
