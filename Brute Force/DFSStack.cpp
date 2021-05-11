#include <iostream>
#include <stack>
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

void depthFirstSearch(adjacency_list** list){
	stack<int> s;
	s.push(list[0]->data);
	int count = 0;
	while(!s.empty()){
		adjacency_list* a = list[s.top()];
		adjacency_list* b = a;
		if(list[b->data]->visit == 0){
			list[b->data]->visit = ++count;
			cout<<b->data<<endl;
		}
		while(a != NULL && list[a->data]->visit != 0){
			a = a->right;
		}
		if(a != NULL)
		{
			s.push(a->data);
		}else{
			s.pop();
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
	depthFirstSearch(list);
	return 0;
}