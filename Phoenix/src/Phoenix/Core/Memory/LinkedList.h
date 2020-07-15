#pragma once

namespace Phx {

	template <typename T>
	class LinkedList {
	public:
		struct Node {
			T data;
			Node* next;
		};

	public:
		LinkedList() {}

		void insert(Node* previousNode, Node* newNode)
		{
			if (previousNode == nullptr)
			{
				if (m_Head != nullptr)
					newNode->next = m_Head;
				else
					newNode->next = nullptr;
				m_Head = newNode;
			}
			else
			{
				if (previousNode->next == nullptr)
				{
					previousNode->next = newNode;
					newNode->next = nullptr;
				}
				else
				{
					newNode->next = previousNode->next;
					previousNode->next = newNode;
				}
			}
		}


		void remove(Node* previousNode, Node* deleteNode)
		{
			if (previousNode == nullptr)
			{
				if (deleteNode->next == nullptr)
					m_Head = nullptr;
				else
					m_Head = deleteNode->next;
			}
			else
				previousNode->next = deleteNode->next;
		}

	};
	private:
	Node* m_Head;
}