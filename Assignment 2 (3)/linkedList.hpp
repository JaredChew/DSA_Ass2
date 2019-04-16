#pragma once

template<typename Custom>
class LinkedList {

private:
	int index;

public:
	LinkedList* next;

	Custom data;

public:

	LinkedList() : next(nullptr) {

		index = 0;

	}

	~LinkedList() { }

	LinkedList<Custom>* getLinkedList(const int& index) {

		LinkedList<Custom>* temp = next;

		while (temp->next != nullptr) {

			if (temp->getIndex() == index) {
				return temp;
			}

			temp = next->next;

		}

		return nullptr;

	}

	void push(const Custom &data, const int& index) {

		if (next == nullptr) {

			next = new LinkedList();

			next->setIndex(index);
			next->data = data;

			return;

		}

		LinkedList<Custom>* temp = next;

		while (temp->next != nullptr) {
			temp = next->next;
		}

		temp = new LinkedList();

		temp->setIndex(index);
		temp->data = data;

	}

	void pushAt(Custom data, const int& index) {

		LinkedList<Custom>* temp = next;

		while (temp != nullptr || temp->next != nullptr) {

			if (temp->next->getIndex() == index) {

				LinkedList* nodePointer = temp->next;

				temp->next = new LinkedList();

				temp->next->setIndex(index);
				temp->data = data;

				temp->next->next = nodePointer;

				return;

			}

			temp = next->next;

		}

	}

	void pop() {

		LinkedList<Custom>* temp = next;

		while (temp->next->next != nullptr && temp->next != nullptr) {

			temp = next->next;
		}

		delete temp->next;
		temp->next = nullptr;

	}

	void popAt(const int& index) {

		LinkedList<Custom>* temp = next;

		while (temp->next != nullptr) {

			if (temp->next->getIndex() == index) {

				LinkedList* nodePointer = temp->next->next;

				temp->next->next = nullptr;

				delete temp->next;
				temp->next = nodePointer;

				return;
			}

		}

	}

	void setIndex(const int& index) {

		this->index = index;

	}

	int getIndex() {

		return index;

	}

};