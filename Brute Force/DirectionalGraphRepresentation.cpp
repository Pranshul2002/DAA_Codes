#include <iostream>
using namespace std;

typedef struct adjacency_list{
	int data;
	struct adjacency_list* right;
	struct adjacency_list* down;
}adjacency_list;

adjacency_list* createNode(int data){
	adjacency_list* temp = (adjacency_list*)malloc(sizeof(adjacency_list));
	temp->data = data;
	temp->down = NULL;
	temp->right = NULL;
}

adjacency_list* createGraphAdjacencyList(int v,int e,int arr[][2]){
	adjacency_list* node1 = createNode(1);
	adjacency_list* node = node1;
	adjacency_list* temp;
	for(int i=1;i<v;i++){
		node1->down = createNode(i+1);
		node1 = node1->down;
	}
	for(int i=0;i<e;i++){
		adjacency_list* temp = node;
		while(temp != NULL){
			if(temp->data == arr[i][0]){
				adjacency_list* r = temp;
				while(r->right != NULL){
					r = r->right;
				}
				r->right = createNode(arr[i][1]);
				break;
			}else{
				temp = temp->down;
			}

		}
	}
	return node;
}

void display_adjacency_list(adjacency_list* list){
	while(list != NULL){
		adjacency_list* a = list;
		while(a != NULL){
			cout<<a->data<<" -> ";
			cout.flush();
			a = a->right;
		}
		cout<<endl;
		list = list->down;
	}
}

int** createGraphAdjacencyMatrix(int v,int e,int arr[][2]){

	int** martix = (int**)malloc(sizeof(int*)*v);
	for(int i=0;i<v;i++){
		martix[i] = (int*)calloc(v,sizeof(int));
	}
	for(int i=0;i<e;i++){
		martix[arr[i][0]-1][arr[i][1]-1] = 1;
	}
	
	return martix;
}

void display_adjacency_matrix(int** adjacency_matrix,int v){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			cout<<adjacency_matrix[i][j]<<"\t";
			cout.flush();
		}
		cout<<endl;
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

	adjacency_list* list = createGraphAdjacencyList(v,e,arr);
	display_adjacency_list(list);
	cout.flush();
	int** adjacency_matrix = createGraphAdjacencyMatrix(v,e,arr);
	cout.flush();
	display_adjacency_matrix(adjacency_matrix,v);
	return 0;
}