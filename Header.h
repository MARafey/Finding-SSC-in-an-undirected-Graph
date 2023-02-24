#pragma once
#include <iostream>
#include<stack>
#include<windows.h>

using namespace std;
template <typename T>
class node_0
{
public:
	T data;
	T data2;
	node_0<T>* next;

	node_0()
	{
		data = data2 = INT_MIN;
		next = nullptr;
	}
	node_0(T d, T d2)
	{
		this->data = d;
		this->data2 = d2;
		next = nullptr;
	}

};
//new nodes are created and are saved in pointer
void insert(node_0<int>*& head, int d, int d2)
{
	node_0<int>* p = new node_0<int>(d, d2);
	if (head->data == INT_MIN && head->data2 == INT_MIN)
	{
		head = p;		//inserting node if head is empty
		return;
	}
	p->next = head;	//going to next index of head of pointer which reduces run time
	head = p;
}

template <typename T>
struct Node
{
	Node<T>* next;
	int data;

	Node(T d)
	{
		data = d;
		next = NULL;
	}
};

template <typename T>
class SLink_List
{
public:
	Node<T>* head;

	SLink_List()
	{
		head = NULL;

	}
	void insertAtHead(T d)
	{
		Node<T>* p = new Node<T>(d);
		p->next = head;
		head = p;
	}
	void delete_head()
	{
		Node<T>* p = head;
		head = head->next;
		delete p;
	}
	T getData()
	{
		return head->data;
	}
	bool search(T s)
	{
		Node<T>* temp2 = head;
		while (temp2 != NULL)
		{
			if (temp2->data == s)
			{
				return true;
			}
			temp2 = temp2->next;
		}
		return false;
	}
	bool IsEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void reverse()
	{
		Node<int>* current = head;
		Node<int>* prev = NULL, * next = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void display()
	{
		Node<T>* temp2 = head;
		while (temp2 != NULL)
		{
			cout << temp2->data << " ";
			temp2 = temp2->next;
		}
		cout << endl;
	}
};

void display_Graph(SLink_List<int>* reverse_graph, int max)
{
	for (int i = 0; i <= max; i++)
	{
		cout << "Links of " << i << "--->";
		if (reverse_graph[i].head == NULL)
		{
			cout << " No Links.\n";
		}
		else
		{
			reverse_graph[i].display();
		}
		cout << "-----------------------" << endl;
	}
}

SLink_List<int>* creating_graph(node_0<int>* data, int max)
{
	SLink_List<int>* graph = new SLink_List<int>[max + 1];
	
	while (data != NULL)
	{
		graph[data->data].insertAtHead(data->data2);
		data = data->next;
	}
	//display_Graph(graph, max);
	//graph->reverse();
	return graph;
}

SLink_List<int>* reverse_of_graph(SLink_List<int>* graph, int max)
{
	SLink_List<int>* reverse_graph = new SLink_List<int>[max + 1];

	for (int i = 0; i <= max; i++)
	{
		/// <summary>
		///  graph[1] ---> 1 2 4
		///  reverse graph[4] --->1
		///  reverse graph[2] --->1
		///  reverse graph[1] --->1 
		/// <returns></returns>
		Node<int>* junk = graph[i].head;
		while (junk)
		{
			reverse_graph[junk->data].insertAtHead(i);
			junk = junk->next;
		}
	}
	//display_Graph(reverse_graph, max);
	return reverse_graph;
}

void revDFS(int start, int size, SLink_List<int>* original, bool* already_visited,long &tempsize)
{

	already_visited[start] = true;
	tempsize += 1;
	Node<int>* traverser = original[start].head;
	Node<int>*& ptr = traverser;
	while (ptr != nullptr)
	{
		if (already_visited[ptr->data] == false && ptr->data >= 0)
		{
			already_visited[ptr->data] = (start >= 0) ? true : false;
			revDFS(ptr->data, size, original, already_visited,tempsize);
		}
		Node<int>* nxt_reacher = ptr->next;
		ptr = nxt_reacher;
	}
}

void Depth_first_Search(int start, int size, SLink_List<int>*& original, bool*& already_visited, stack<int>*& DFS_getter)
{
	already_visited[start] = true;

	Node<int>* traverser = original[start].head;
	Node<int>*& ptr = traverser;
	while (ptr != nullptr)
	{
		if (already_visited[ptr->data] == false && ptr->data >= 0)
		{
			already_visited[ptr->data] = true;
			Depth_first_Search(ptr->data, size, original, already_visited, DFS_getter);
		}
		Node<int>* nxt_reacher = ptr->next;
		ptr = nxt_reacher;
	}
	int& the_index = start;
	DFS_getter->push(the_index);
}

int getstart(SLink_List<int>* original, int max)
{
	for (int i = 0; i <= max; i++)
	{
		if (original->head != NULL)
		{
			return i;
		}
	}
}