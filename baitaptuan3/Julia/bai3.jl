mutable struct Robot
    position::Vector{Int}  # [x, y]
    direction::String      # N, E, S, W
    history::Vector{String} # Lịch sử các lệnh

    Robot() = new([0, 0], "N", String[])
end

function move_forward(robot::Robot)
    if robot.direction == "N"
        robot.position[2] += 1
    elseif robot.direction == "E"
        robot.position[1] += 1
    elseif robot.direction == "S"
        robot.position[2] -= 1
    elseif robot.direction == "W"
        robot.position[1] -= 1
    end
    push!(robot.history, "forward")
    display_status(robot, "Đang tiến lên")
end

function move_backward(robot::Robot)
    if robot.direction == "N"
        robot.position[2] -= 1
    elseif robot.direction == "E"
        robot.position[1] -= 1
    elseif robot.direction == "S"
        robot.position[2] += 1
    elseif robot.direction == "W"
        robot.position[1] += 1
    end
    push!(robot.history, "backward")
    display_status(robot, "Đang lùi lại")
end

function turn_left(robot::Robot)
    dirs = ["N", "W", "S", "E"]
    idx = findfirst(==(robot.direction), dirs)
    robot.direction = dirs[mod(idx, 4) + 1]
    push!(robot.history, "left")
    display_status(robot, "Đang quay trái")
end

function turn_right(robot::Robot)
    dirs = ["N", "E", "S", "W"]
    idx = findfirst(==(robot.direction), dirs)
    robot.direction = dirs[mod(idx, 4) + 1]
    push!(robot.history, "right")
    display_status(robot, "Đang quay phải")
end

function undo(robot::Robot)
    if isempty(robot.history)
        println("Không có lệnh nào để hoàn tác.")
        return
    end

    last_command = pop!(robot.history)
    println("Hoàn tác lệnh: ", last_command)

    if last_command == "forward"
        move_backward(robot)
    elseif last_command == "backward"
        move_forward(robot)
    elseif last_command ==
