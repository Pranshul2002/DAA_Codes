#include <iostream>
#include <stack>
using namespace std;

typedef struct adjacency_list {
	int data;
	int visit;
	struct adjacency_list* right;
} adjacency_list;

adjacency_list* createNode(int data) {
	adjacency_list* temp = (adjacency_list*)malloc(sizeof(adjacency_list));
	temp->data = data;
	temp->visit = 0;
	temp->right = NULL;
	return temp;
}

void display_adjacency_list(adjacency_list** list, int v) {
	for (int i = 0; i < v; i++) {
		cout << i << " -> ";
		adjacency_list* a = list[i]->right;
		while (a != NULL) {
			cout << a->data << " -> ";
			a = a->right;
		}
		cout << endl;
	}
}

adjacency_list** createGraphAdjacencyList(int v, int e, int arr[][2]) {
	adjacency_list** node = (adjacency_list**)malloc(sizeof(adjacency_list*)*v);
	for (int i = 0; i < v; i++) {
		node[i] = createNode(i);
	}
	for (int i = 0; i < e; i++) {
		int j = 0;
		adjacency_list** temp = node;
		while (j < v) {
			if (temp[j]->data == arr[i][0]) {
				adjacency_list* temp1 = createNode(arr[i][1]);
				temp1->right = temp[j]->right;
				temp[j]->right = temp1;
				break;
			} else {
				j++;
			}
		}
	}
	return node;
}

void topologicalSearch(adjacency_list** list, int v) {
	stack<int> s;
	stack<int> s1;
	s.push(list[0]->data);
	int count = 0;
	adjacency_list* a;
	adjacency_list* b;
	while (count != v) {
		if (s.empty() == false)
		{
			a = list[s.top()];
		}
		else {
			int i = 0;
			while (list[i]->visit != 0) {
				i++;
			}
			a = list[i];
			s.push(a->data);
		}
		b = a;
		if (list[b->data]->visit == 0) {
			list[b->data]->visit = ++count;
		}
		while (a != NULL && list[a->data]->visit != 0) {
			a = a->right;
		}
		if (a != NULL)
		{
			s.push(a->data);
		} else {
			s1.push(s.top());
			s.pop();
		}
	}
	while (s1.empty() == false) {
		cout << s1.top() << endl;
		s1.pop();
	}
}



int main()
{	int v, e;
	cin >> v >> e;
	int arr[e][2];
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}
	adjacency_list** list = createGraphAdjacencyList(v, e, arr);
	display_adjacency_list(list, v);
	topologicalSearch(list, v);
	return 0;
}