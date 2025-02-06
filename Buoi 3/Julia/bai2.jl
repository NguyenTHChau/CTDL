using Random
using Threads
using Printf

mutable struct Sensor
    id::Int
    print_queue::Any
end

function send_data(sensor::Sensor)
    while true
        data = "Dữ liệu từ cảm biến $(sensor.id): $(rand(1:100))"
        enqueue(sensor.print_queue, data)
        sleep(rand(0.5:2))  # Gửi dữ liệu ngẫu nhiên
    end
end

mutable struct PrintQueue
    queue::Vector{String}
    lock::ReentrantLock
end

function enqueue(queue::PrintQueue, data::String)
    lock(queue.lock) do
        push!(queue.queue, data)
        println("Đã thêm vào hàng đợi: ", data)
    end
end

function process_queue(queue::PrintQueue)
    while true
        lock(queue.lock) do
            if !isempty(queue.queue)
                data = popfirst!(queue.queue)
                println("Đang xử lý: ", data)
            end
        end
        sleep(1)  # Giả lập thời gian xử lý
    end
end

function main()
    print_queue = PrintQueue([], ReentrantLock())

    # Khởi động thread xử lý hàng đợi
    @async process_queue(print_queue)

    # Tạo và khởi động các cảm biến
    for i in 1:3
        sensor = Sensor(i, print_queue)
        @async send_data(sensor)
    end

    # Giữ chương trình chạy
    while true
        sleep(10)
    end
end

main()
