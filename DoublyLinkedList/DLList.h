#ifndef DEF_DLLIST
#define DEF_DLLIST

#include <iostream>

template <typename T>
class DLList {

	public:

		DLList();
		void appendNode(T value);
		void prependNode(T value);
		void deleteNodeByValue(T value);
		void displayDLList ();

	private:

		struct Node {
			T m_value;
			struct Node *m_prevAddress;
			struct Node *m_nextAddress;
		};

		size_t m_length;
		Node *m_headAddress;
		Node *m_tailAddress;
		Node *searchNodeByValue(T value);

};

template <typename T>
DLList<T>::DLList() : m_length(0), m_headAddress(NULL), m_tailAddress(NULL) {

}

template <typename T>
void DLList<T>::appendNode(T value) {
	Node *newNode(0);
	newNode = new Node;
	newNode->m_value = value;
	newNode->m_nextAddress = NULL;

	if (m_tailAddress == NULL) {
		newNode->m_prevAddress = NULL;
		m_tailAddress = newNode;
		m_headAddress = newNode;

	} else {
		newNode->m_prevAddress = m_tailAddress;
		m_tailAddress->m_nextAddress = newNode;
		m_tailAddress = newNode;
	}

	m_length++;
}

template <typename T>
void DLList<T>::displayDLList () {

	Node *tmp(0);
	tmp = m_headAddress;

	if (tmp == NULL) {
		std::cout << "### Empty List ###" << std::endl;
		return;
	}

	std::cout << " ### NULL > ";
	while (tmp != NULL) {
		std::cout << tmp->m_value << " > ";
		tmp = tmp->m_nextAddress;
	}
	std::cout << "NULL ###"<< std::endl;
}

template <typename T>
void DLList<T>::prependNode (T value) {

	Node *newNode(0);
	newNode = new Node;

	newNode->m_value = value;
	newNode->m_prevAddress = NULL;

	if (m_headAddress == NULL) {
		newNode->m_nextAddress = NULL;
		m_tailAddress = newNode;
		m_headAddress = newNode;
	} else {
		newNode->m_nextAddress = m_headAddress;
		m_headAddress->m_prevAddress = newNode;
		m_headAddress = newNode;
	}
	m_length++;
}

template <typename T>
typename DLList<T>::Node *DLList<T>::searchNodeByValue(T value) {

	Node *tmp(0);
	tmp = m_headAddress;

	while (tmp != NULL && tmp->m_value != value) {
		tmp = tmp->m_nextAddress;
	}

	return tmp;
}

template <typename T>
void DLList<T>::deleteNodeByValue(T value) {

	Node *tmp(0);
	tmp = searchNodeByValue(value);

	if (tmp == NULL)
		return;

	if(tmp->m_prevAddress)
		tmp->m_prevAddress->m_nextAddress = tmp->m_nextAddress;

	if(tmp->m_nextAddress)
		tmp->m_nextAddress->m_prevAddress = tmp->m_prevAddress;

	if (tmp == m_headAddress)
		m_headAddress = tmp->m_nextAddress;

	if (tmp == m_tailAddress)
		m_tailAddress = tmp->m_prevAddress;

	delete tmp;
	tmp = 0;
}


#endif
