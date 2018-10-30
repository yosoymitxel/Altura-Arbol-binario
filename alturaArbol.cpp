#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	struct treeNode{
		int dato;
		treeNode *rightPtr;
		treeNode *leftPtr;
	};
	
	typedef struct treeNode TREENODE;
	typedef TREENODE * TREE;
	
	void insertar (TREE *, int );
	void enOrden (TREE);
	void alturaArbol (TREE, int *, int *);
	void alturaArbol (TREE, int , int *);
	void postOrden (TREE);
	void contar (TREE, int*);
	void altura (TREE, int, int *);
	
	
int main(int argc, char** argv) {
	int x=0, item, n=0, hmax=0, ban=0, him = 999, count = 0, max = 0;
	TREE rootPtr=NULL;
	cout<<"Ingresar un numero, -1: ";
	cin>>item;
	
	while(item!=-1){
		insertar(&rootPtr,item);
	cout<<"Ingresar un numero, -1: ";
	cin>>item;
	}
	alturaArbol(rootPtr, count, &max); 
	cout<<endl;
	cout<<"La altura es: "<<max<<endl;/*enOrden(rootPtr);
	cout<<endl;
	postOrden(rootPtr);
	cout<<endl;*/

	//system ("pause");
	return 1;
	
}
void insertar (TREE *treePtr, int valor){
	if  (*treePtr == NULL){
		*treePtr = new (TREENODE);
		if (*treePtr !=NULL){
			(*treePtr)->dato =valor;
			(*treePtr)->leftPtr =NULL;
			(*treePtr)->rightPtr=NULL;
		}else
			cout<<"No hay memoria"<<endl;
		}
		else
		if (valor < (*treePtr)->dato){
			insertar (&((*treePtr)->leftPtr), valor);
		}else 
		if (valor > (*treePtr)->dato){
			insertar (&((*treePtr)->rightPtr), valor);
		}else 
			cout<<"DUPLICADO"<<endl;
	
}

void alturaArbol(TREE treePtr, int * i, int * max)
{
	if (treePtr != NULL)
	{
		(*i)++;
		//cout<<treePtr->dato<<"->";
		//coutendl;
		alturaArbol(treePtr->leftPtr,i,max);
		alturaArbol(treePtr->rightPtr,i,max);
		cout<<"Aqui finaliza posicion "<<(*i)<<" con el valor: "<<treePtr->dato<<endl;
		*max = (*max)>(*i)? (*max) : (*i);
		//cout<<"El max es: "<<(*max)<<endl;
		(*i)--;
	}
}

void alturaArbol(TREE treePtr, int i, int * max)
{
	if (treePtr != NULL)
	{
		i++;
		alturaArbol(treePtr->leftPtr,i,max);
		alturaArbol(treePtr->rightPtr,i,max);
		cout<<"Aqui finaliza posicion "<<i<<" con el valor: "<<treePtr->dato<<endl;
		*max = (*max)>i? (*max) : i;
	}
}

/*void enOrden(TREE treePtr)
{
	if (treePtr != NULL)
	{
		
		alturaArbol(treePtr->leftPtr);
		cout<<treePtr->dato<<"->";
		alturaArbol(treePtr->rightPtr);
	}
}
void postOrden(TREE treePtr)
{
	if (treePtr != NULL)
	{
		
		alturaArbol(treePtr->leftPtr);
		alturaArbol(treePtr->rightPtr);
		cout<<treePtr->dato<<"->";
	}
}
*/

