#include <iostream>
#include <queue>
using namespace std;

typedef struct adjacency_list {
	int data;
	struct adjacency_list* right;
} adjacency_list;

adjacency_list* createNode(int data) {
	adjacency_list* temp = (adjacency_list*)malloc(sizeof(adjacency_list));
	temp->data = data;
	temp->right = NULL;
	return temp;
}

void display_adjacency_list(adjacency_list** list, int v) {
	for (int i = 0; i < v; i++) {
		cout << i << " -> ";
		adjacency_list* a = list[i]->right;
		int j = 10;
		while (a != NULL && j--) {
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

void topologicalSearch(adjacency_list** list,int v) {
	queue<int> q;
	int indegree[v];
	for (int i = 0; i < v; i++) {
		indegree[i] = 0;
	}
	for (int i = 0; i < v; i++) {
		adjacency_list* node = list[i];
		node = node->right;
		while (node != NULL) {
			indegree[node->data]++;
			node = node->right;
		}
	}
	for(int i=0;i<v;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(q.empty() == false){
		adjacency_list* a = list[q.front()];
		q.pop();
		cout<<a->data<<endl;
		a = a->right;
		while(a != NULL){
			indegree[a->data]--;
			if(indegree[a->data] == 0){
				q.push(a->data);
			}
			a = a->right;
		}
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
	cout.flush();
	topologicalSearch(list, v);
	return 0;
}