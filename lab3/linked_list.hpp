#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
//#include <crtdbg.h>
//#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

template<typename T>
class linked_list
{
public:
	linked_list();
	linked_list(const linked_list & src);
	~linked_list();

	linked_list<T> &operator=(const linked_list & rhs);

	// adds elements to the back
	linked_list<T> &operator+=(const linked_list & rhs);

	// inserting elements
	void insert(T value, size_t pos);
	// in front
	void push_front(T value);
	// in back
	void push_back(T value);

	// accessing elements
	T front() const;
	T back() const;
	T at(size_t pos) const;

	// removing elements
	void remove(size_t pos);
	// remove and access
	T pop_front();
	T pop_back();

	// informational
	size_t size() const;
	bool is_empty() const;
	bool is_order() const;

	// output
	void print() const;
	void print_reverse() const;

	linked_list<T> &merge(linked_list &list1, linked_list &list2);

private:
	struct node_t {
		node_t(T value, node_t * next = 0, node_t * prev = 0)
		{
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
		T value;
		node_t * next;
		node_t * prev;
	};
	node_t * head;
	node_t * tail;
	size_t nrOfNodes;

	void copy(linked_list const &other) {
		this->nrOfNodes = 0;
		if (!other.is_empty())
		{
			node_t* walker = other.head->next;
			node_t* current = this->head = new node_t(other.head->value);
			this->nrOfNodes++;

			while (walker != nullptr)
			{
				node_t* next = new node_t(walker->value);

				current->next = next;
				next->prev = current;

				current = current->next;
				walker = walker->next;
				this->nrOfNodes++;
			}
			this->tail = current;
		}
	}
};

#endif // !LINKED_LIST_HPP

template<typename T>
inline linked_list<T>::linked_list()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->nrOfNodes = 0;
}

template<typename T>
inline linked_list<T>::linked_list(const linked_list & src)
{
	this->copy(src);
}

template<typename T>
inline linked_list<T>::~linked_list()
{
	while (!this->is_empty())
	{
		this->pop_back();
	}
	this->nrOfNodes = 0;
}

template<typename T>
inline linked_list<T>& linked_list<T>::operator=(const linked_list & rhs)
{
	if (this != &rhs)
	{
		while (!this->is_empty())
		{
			this->pop_back();
		}
		this->copy(rhs);
	}

	return *this;
}

template<typename T>
inline linked_list<T>& linked_list<T>::operator+=(const linked_list & rhs)
{
	node_t *walker = rhs.head;

	while (walker != nullptr)
	{
		this->push_back(walker->value);
		walker = walker->next;
	}
	return *this;
}

template<typename T>
inline void linked_list<T>::insert(T value, size_t pos)
{
	node_t *walker = head;
	walker = this->head;

	if (pos == 0)
	{
		this->push_front(value);
	}
	else if (pos == this->size())
	{
		this->push_back(value);
	}
	else
	{
		for (size_t i = 0; i <= pos && walker != nullptr; i++)
		{
			if (i == pos)
			{
				node_t *newNode = new node_t(value, walker, walker->prev);

				node_t *ptrPrev = walker->prev;
				ptrPrev->next = newNode;
				walker->prev = newNode;
				this->nrOfNodes++;

			}
			walker = walker->next;
		}
	}
}

template<typename T>
inline void linked_list<T>::push_front(T value)
{
	node_t *tmpNode = new node_t(value, this->head, nullptr);

	if (head == nullptr)
	{
		this->head = this->tail = tmpNode;
	}
	else
	{
		this->head->prev = tmpNode;
		this->head = tmpNode;
	}

	this->nrOfNodes++;
}

template<typename T>
inline void linked_list<T>::push_back(T value)
{
	node_t *tmpNode = new node_t(value, nullptr, this->tail);

	if (this->tail == nullptr)
	{
		this->head = this->tail = tmpNode;
	}
	else
	{
		this->tail->next = tmpNode;
		this->tail = tmpNode;
	}

	this->nrOfNodes++;
}

template<typename T>
inline T linked_list<T>::front() const
{
	return this->head->value;
}

template<typename T>
inline T linked_list<T>::back() const
{
	return this->tail->value;
}

template<typename T>
inline T linked_list<T>::at(size_t pos) const
{
	T foundValue = 0;
	node_t *walker = head;

	if (pos == 0)
	{
		foundValue = this->head->value;
	}
	else
	{
		for (size_t i = 0; i <= pos; i++, walker = walker->next)
		{
			foundValue = walker->value;
		}
	}
	return foundValue;
}

template<typename T>
inline void linked_list<T>::remove(size_t pos)
{
	node_t *walker = head;
	walker = this->head;

	if (pos == 0)
	{
		this->pop_front();
	}
	else if (pos == this->size())
	{
		this->pop_back();
	}
	else
	{
		for (size_t i = 0; i <= pos && walker != nullptr; i++)
		{
			if (i == pos)
			{
				walker->prev->next = walker->next;
				walker->next->prev = walker->prev;
				walker->next = nullptr;
				walker->prev = nullptr;
				delete walker;
				this->nrOfNodes--;
			}
			else
			{
				walker = walker->next;
			}
		}
	}
}

template<typename T>
inline T linked_list<T>::pop_front()
{
	T popVal = 0;
	node_t *tmpHead = this->head;
	popVal = this->head->value;

	if (this->head->next != nullptr)
	{
		this->head = this->head->next;
		this->head->prev = nullptr;
	}
	else
	{
		this->head = this->tail = nullptr;
	}

	delete tmpHead;
	this->nrOfNodes--;

	return popVal;
}

template<typename T>
inline T linked_list<T>::pop_back()
{
	T popVal = 0;
	node_t *tmpTail = this->tail;
	popVal = this->tail->value;

	if (this->tail->prev != nullptr)
	{
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
	}
	else
	{
		this->head = this->tail = nullptr;
	}

	delete tmpTail;
	this->nrOfNodes--;

	return popVal;
}

template<typename T>
inline size_t linked_list<T>::size() const
{
	return this->nrOfNodes;
}

template<typename T>
inline bool linked_list<T>::is_empty() const
{
	return this->nrOfNodes == 0 ? true : false;
}

template<typename T>
inline bool linked_list<T>::is_order() const
{
	node_t* walker = this->head, *walker_next = this->head->next;
	while (walker_next != nullptr)
	{
		if (walker->value <= walker_next->value)
		{
			walker = walker_next;
			walker_next = walker_next->next;
		}
		else
		{
			return false;
		}
	}
	return true;
}

template<typename T>
inline void linked_list<T>::print() const
{
	if (!this->is_empty())
	{
		int i = 0;
		for (node_t *walker = head; walker != nullptr; walker = walker->next, i++)
		{
			std::cout << walker->value << ", ";
		}
	}
	else
	{
		std::cout << "list is empty\n";
	}
}

template<typename T>
inline void linked_list<T>::print_reverse() const
{
	if (!this->is_empty())
	{
		for (node_t *walker = tail; walker != nullptr; walker = walker->prev)
		{
			std::cout << walker->value << ", ";
		}
	}
	else
	{
		std::cout << "list is empty\n";
	}
}

template<typename T>
inline linked_list<T>& linked_list<T>::merge(linked_list &list1, linked_list &list2)
{
	node_t* walker_1 = list1.head, *walker_2 = list2.head;

	while (walker_1 != nullptr && walker_2 != nullptr)
	{
		if (list1.front() < list2.front())
		{
			walker_1 = walker_1->next;
			this->push_back(list1.pop_front());
		}
		else
		{
			walker_2 = walker_2->next;
			this->push_back(list2.pop_front());
		}
	}
	while (!list1.is_empty())
	{
		this->push_back(list1.pop_front());
	}
	while (!list2.is_empty())
	{
		this->push_back(list2.pop_front());
	}

	return *this;
}