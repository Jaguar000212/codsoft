#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct TodoItem {
	string description;
	bool completed;
};

void showTodoList(const vector<TodoItem>& todoList) {
	cout << "\n\n"
		 << "--------Tasks--------\n\n";
	cout << "Description - Status\n";
	cout << "---------------------\n";
	for (int i = 0; i < todoList.size(); i++) {
		const TodoItem& item = todoList[i];
		cout << i << ". " << item.description << " - " << (item.completed ? "Complete" : "Incomplete") << endl;
	}
}

void addTodoItem(vector<TodoItem>& todoList, const string& description) {
	TodoItem newItem;
	newItem.description = description;
	newItem.completed = false;
	todoList.push_back(newItem);
}

void deleteTodoItem(vector<TodoItem>& todoList, int index) {
	if (index >= 0 && index < todoList.size()) {
		todoList.erase(todoList.begin() + index);
	}
}

void markAsComplete(vector<TodoItem>& todoList, int index) {
	if (index >= 0 && index < todoList.size()) {
		todoList[index].completed = true;
	}
}

void saveTodoList(const vector<TodoItem>& todoList, const string& filename) {
	ofstream file(filename);
	if (file.is_open()) {
		for (const auto& item : todoList) {
			file << item.description << "," << item.completed << endl;
		}
		file.close();
		cout << "Todo list saved successfully." << endl;
	}
	else {
		cout << "Unable to open file for saving." << endl;
	}
}

void loadTodoList(vector<TodoItem>& todoList, const string& filename) {
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			size_t commaIndex = line.find(',');
			string description = line.substr(0, commaIndex);
			bool completed = line.substr(commaIndex + 1) == "1";
			TodoItem newItem;
			newItem.description = description;
			newItem.completed = completed;
			todoList.push_back(newItem);
		}
		file.close();
		cout << "Todo list loaded successfully." << endl;
	}
	else {
		cout << "Unable to open file for loading." << endl;
	}

}

int main() {
	vector<TodoItem> todoList;

	while (true) {
		cout << "\n\nTodo List" << endl;
		cout << "---------" << endl;
		cout << "Commands:\n0. Show List\n1. Add Item\n2. Delete Item\n3. Mark as Complete\n4. Load List\n5. Save List\n6. Quit\n";
		cout << "Select a command: ";
		int command;
		cin >> command;

		if (command == 0) {
			showTodoList(todoList);
		}
		else if (command == 1) {
			cout << "Enter a description: ";
			string description;
			cin.ignore();
			getline(cin, description);
			addTodoItem(todoList, description);
			cout << "Item successfully added." << endl;
		}
		else if (command == 2) {
			showTodoList(todoList);
			cout << "\nEnter an index to delete: ";
			int index;
			cin >> index;
			deleteTodoItem(todoList, index);
			cout << "Item successfully deleted." << endl;
		}
		else if (command == 3) {
			showTodoList(todoList);
			cout << "\nEnter an index to mark as complete: ";
			int index;
			cin >> index;
			markAsComplete(todoList, index);
			cout << "Item marked as complete." << endl;
		}
		else if (command == 4) {
			cout << "Enter a filename to load: ";
			string filename;
			cin.ignore();
			getline(cin, filename);
			loadTodoList(todoList, filename);
		}
		else if (command == 5) {
			cout << "Enter a filename to save: ";
			string filename;
			cin.ignore();
			getline(cin, filename);
			saveTodoList(todoList, filename);
		}
		else if (command == 6) {
			cout << "Goodbye!" << endl;
			break;
		}
		else {
			cout << "Invalid command." << endl;
		}
	}

	return 0;
}