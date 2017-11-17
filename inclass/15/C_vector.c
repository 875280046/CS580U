/*
use C to achieve Vector function
newVector, readVector, insertVector, deleteVector(removeVector), freeVector
*/

#include<stdio.h>
#include<stdlib.h>
#include"C_vector.h"
/*
typedef struct Node
{
	char array[10];
	int id;
}Node;

typedef struct Vector
{
	int current_size;
	int max_size;
	Node* node;
}Vector;
*/
int main(){
	Vector* v = newVector(3);
	Node node1 = {"one", 101};
	Node node2 = {"two", 102};
	Node node3 = {"three", 103};
	Node node4 = {"four", 104};
	push_back(v, node1);
	push_back(v, node2);
	push_back(v, node3);
	push_back(v, node4);
	rmVector(v, 0);
	pop_back(v);
	int i = 0;
	for(i = 0; i < v->current_size; i++){		//because although current_size if from 0, but push_back(); make current_size++
		printf("%s %d\n", v->node[i].array, v->node[i].id);
	}
	freeVector(v);
	return 0;
}

Vector* newVector(int Max_size){		//new max_size space
	Vector* v = malloc(sizeof(Vector));
	v->current_size = 0;
	v->max_size =  Max_size;
	v->node = malloc(sizeof(Node) * Max_size);

	return v;
}

void push_back(Vector* v, Node node){

	if(v->current_size >= v->max_size){		//current_size begin from 0(just like index), if current_size equal to max_size, overstep the boundary
		v->node = realloc(v->node, sizeof(Node) * 2*(v->max_size));		//when overstep the boundary, extend the malloc space, this time tripled insize
	}
	v->node[v->current_size++] =node;	//put the new node in the end, treat all node as array, use [index] to operate struct node, becaues index from 0,
									//the new node should be v->node[v->current_size], after that ++ make current_size grow 1.  
}

void pop_back(Vector* v){		//remove the last node
	v->current_size--;		
}

void rmVector(Vector* v, int index){		//remove any node
	if(index < v->current_size - 1){		//make sure the node you want to remove is not the last node
		int i;
		for(i = index; i < v->current_size - 1; i++){
			v->node[i] = v->node[i + 1];
		}
		v->current_size--;
	}
	else{
		v->current_size--;		//other situaton treat as pop from back
	}
	
}

void freeVector(Vector* v){
	free(v->node);
	free(v);
}
