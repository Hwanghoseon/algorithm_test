#include<iostream>
#include<string>
#define MAX 10001

using namespace std;

class Queue {
private:
	int list[MAX];
	int front = 0;
	int rear = -1;
public:
	void push(int data) {
		rear++;
		list[rear] = data;
	}

	void pop() {
		if (!empty()) {
			cout << list[front] << endl;
			front++;
		}
		else
			cout << "-1" << endl;
	}

	int size() {
		return (rear + 1 - front);
	}

	int empty() {
		if (front == rear + 1)
			return 1;
		else return 0;
	}

	void Front() {
		if (empty())
			cout << "-1" << endl;
		else
			cout << list[front] << endl;
	}

	void back() {
		if (empty())
			cout << "-1" << endl;
		else
			cout << list[rear] << endl;
	}
};

int main() {
	int T;
	cin >> T;

	Queue queue;

	while (T) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;

			if (queue.size() == MAX) {
				cout << "queue is full"<<endl;
			}
			else
				queue.push(num);
		}
		else if (str == "pop")
			queue.pop();
		else if (str == "size")
			cout << queue.size() << endl;
		else if (str == "empty")
			cout << queue.empty() << endl;
		else if (str == "front")
			queue.Front();
		else if (str == "back")
			queue.back();

		T--;
	}

	return 0;
}
