#include <iostream>
#include <queue>
using namespace std;

typedef struct adjacency_list{
	int data;
	int visit;
	struct adjacency_list* right;
}adjacency_list;

adjacency_list* createNode(int data){
	adjacency_list* temp = (adjacency_list*)malloc(sizeof(adjacency_list));
	temp->data = data;
	temp->visit = 0;
	temp->right = NULL;
}

void display_adjacency_list(adjacency_list** list,int v){
	for(int i=0;i<v;i++){
		cout<<i<<" -> ";
		adjacency_list* a = list[i]->right;
		int j = 10;
		while(a != NULL && j--){
			cout<<a->data<<" -> ";
			a = a->right;
		}
		cout<<endl;
	}
}

adjacency_list** createGraphAdjacencyList(int v,int e,int arr[][2]){
	adjacency_list** node = (adjacency_list**)malloc(sizeof(adjacency_list*)*v);
	for(int i=0;i<v;i++){
		node[i] = createNode(i);
	}
	for(int i=0;i<e;i++){
		int j=0;
		adjacency_list** temp = node;
		while(j<v){
			if(temp[j]->data == arr[i][0]){
				adjacency_list* temp1 = createNode(arr[i][1]);
				temp1->right = temp[j]->right;
				temp[j]->right = temp1;
				temp1 = createNode(arr[i][0]);
				temp1->right = temp[arr[i][1]]->right;
				temp[arr[i][1]]->right = temp1;
				break;
			}else{
				j++;
			}
		}
	}
	return node;
}

void breadthFirstSearch(adjacency_list** list){
	adjacency_list* current = list[0];
	current->visit = 1;
	cout<<current->data<<endl;
	int count = 1;
	queue<int> q;
	q.push(current->data);
	while(q.empty() == false){
		current = list[q.front()];
		q.pop();

	while(current != NULL){
		current = current->right;

		if(current == NULL){
			break;
		}
		if(list[current->data]->visit != 0 ){
			continue;
		}
		list[current->data]->visit = ++count;
		cout<<current->data<<endl;
		q.push(current->data);
	}
	}
}

int main()
{	int v,e;
	cin>>v>>e;
	int arr[e][2];
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		arr[i][0] = a;
		arr[i][1] = b;
	}
	adjacency_list** list = createGraphAdjacencyList(v,e,arr);
	display_adjacency_list(list,v);
	cout.flush();
	breadthFirstSearch(list);
	return 0;
}