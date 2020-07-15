#pragma once

namespace Phx {

	template <class T>
	class Stack
	{
	public:
		 struct Node {
			 T data;
			Node* next;
		 };

	public:
		Stack() = default;
		Stack(Stack& stackLinkedList) = delete;

		void push(Node* newNode)
		{
			newNode->next = m_Head;
			m_Head = newNode;
		}

		Node* Peak()
		{
			return m_Head;
		}

		Node* pop()
		{
			Node* top = m_Head;
			m_Head = m_Head->next;
			return top;
		}

	private:
		Node* m_Head;

	};

}

