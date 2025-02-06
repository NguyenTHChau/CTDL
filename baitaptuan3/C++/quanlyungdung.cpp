#include <iostream>
#include <string>
#include <stack>
using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undo_stack;
    stack<string> redo_stack;

public:
    void type_text(const string& new_text) {
        undo_stack.push(text);
        text += new_text;
        while (!redo_stack.empty()) redo_stack.pop();  // Clear redo stack
        cout << "Da go: " << new_text << endl;
        display();
    }

    void undo() {
        if (!undo_stack.empty()) {
            redo_stack.push(text);
            text = undo_stack.top();
            undo_stack.pop();
            cout << "Da hoan tac hanh dong." << endl;
            display();
        } else {
            cout << "Khong co hanh dong nao de hoan tac." << endl;
        }
    }

    void redo() {
        if (!redo_stack.empty()) {
            undo_stack.push(text);
            text = redo_stack.top();
            redo_stack.pop();
            cout << "Da lam lai hanh dong." << endl;
            display();
        } else {
            cout << "Khong co hanh dong nao de lam lai." << endl;
        }
    }

    void display() const {
        cout << "Noi dung hien tai: " << text << endl;
    }
};

// Minh họa
int main() {
    TextEditor editor;
    editor.type_text("Hello");
    editor.type_text(" World");
    editor.undo();
    editor.undo();
    editor.redo();
    return 0;
}
