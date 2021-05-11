#include <iostream>
#include <stack>
using namespace std;

typedef struct adjacency_list{
	int data;
	int visit;
	int weight;
	struct adjacency_list* right;
}adjacency_list;

adjacency_list* createNode(int data,int weight){
	adjacency_list* temp = (adjacency_list*)malloc(sizeof(adjacency_list));
	temp->data = data;
	temp->weight = weight;
	temp->visit = 0;
	temp->right = NULL;
}

void display_adjacency_list(adjacency_list** list,int v){
	for(int i=0;i<v;i++){
		cout<<i<<" -> ";
		adjacency_list* a = list[i]->right;
		int j = 10;
		while(a != NULL && j--){
			cout<<a->weight<<" --> "<<a->data<<" -> ";
			a = a->right;
		}
		cout<<endl;
	}
}

adjacency_list** createGraphAdjacencyList(int v,int e,int arr[][3]){
	adjacency_list** node = (adjacency_list**)malloc(sizeof(adjacency_list*)*v);
	for(int i=0;i<v;i++){
		node[i] = createNode(i,0);
	}
	for(int i=0;i<e;i++){
		int j=0;
		adjacency_list** temp = node;
		while(j<v){
			if(temp[j]->data == arr[i][0]){
				adjacency_list* temp1 = createNode(arr[i][1],arr[i][2]);
				temp1->right = temp[j]->right;
				temp[j]->right = temp1;
				temp1 = createNode(arr[i][0],arr[i][2]);
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
	int weight = 0;
	list[0]->visit = 1;
	cout<<list[0]->data<<endl;
	stack<int> s;
	s.push(list[0]->data);
	while(!s.empty()){
		adjacency_list* a = list[s.top()];
		s.pop();
		a->visit = 1;
		adjacency_list* b = a;
		while(list[a->data]->visit != 0 && a != NULL){
			a = a->right;
		}

		if(a != NULL)
		s.push(b->data);
		s.push(a->data);
	weight += a->weight;
	cout<<"weight: "<<weight<<endl;
	cout<<a->data<<endl;
	}
	cout<<"weight: "<<weight<<endl;
}



int main()
{	int v,e;
	cin>>v>>e;
	int arr[e][3];
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;
	}
	adjacency_list** list = createGraphAdjacencyList(v,e,arr);
	display_adjacency_list(list,v);
	cout.flush();
	depthFirstSearch(list);
	return 0;
}