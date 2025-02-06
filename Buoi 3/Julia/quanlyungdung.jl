mutable struct TextEditor
    text::String
    undo_stack::Array{String,1}
    redo_stack::Array{String,1}
end

function TextEditor()
    return TextEditor("", String[], String[])
end

function type_text(editor::TextEditor, new_text::String)
    push!(editor.undo_stack, editor.text)
    editor.text *= new_text
    empty!(editor.redo_stack)
    println("Da go: $new_text")
    display(editor)
end

function undo(editor::TextEditor)
    if !isempty(editor.undo_stack)
        push!(editor.redo_stack, editor.text)
        editor.text = pop!(editor.undo_stack)
        println("Da hoan tac hanh dong.")
        display(editor)
    else
        println("Khong co hanh dong nao de hoan tac.")
    end
end

function redo(editor::TextEditor)
    if !isempty(editor.redo_stack)
        push!(editor.undo_stack, editor.text)
        editor.text = pop!(editor.redo_stack)
        println("Da lam lai hanh dong.")
        display(editor)
    else
        println("Khong co hanh dong nao de lam lai.")
    end
end

function display(editor::TextEditor)
    println("Noi dung hien tai: $(editor.text)")
end

# Minh họa
editor = TextEditor()
type_text(editor, "Hello")
type_text(editor, " World")
undo(editor)
undo(editor)
redo(editor)
