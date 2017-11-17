#ifndef C_VECTOR_H
#define C_VECTOR_H

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
	//void (*shan)(struct Vector*, int); 
}Vector;

Vector* newVector();
void push_back(Vector* v, Node node);
void pop_back(Vector* v);
void rmVector(Vector* v, int index);
void freeVector(Vector* v);
#endif
