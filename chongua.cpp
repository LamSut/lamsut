#include <stdio.h>
#define MAXLENGTH 100
#define NULL_NODE -1

typedef int Node;
typedef char LabelType;

typedef struct {
    Node      P[MAXLENGTH];
    LabelType L[MAXLENGTH];
    int maxNode;
} Tree;

void makeNull(Tree *pT){
    pT->maxNode=-1;
}

int empty(Tree *pT){
    if(pT->maxNode==-1){
        return 1;
    }
    return 0;
}

Node parent(Node n, Tree *pT){
    if(n<0||n>pT->maxNode||pT->maxNode==-1){
        return NULL_NODE;
    }
    return pT->P[n];
}

LabelType label(Node n, Tree *pT){
    if(n==pT->maxNode+1){
        return 'a';
    }
    else if(n<0||n>pT->maxNode||pT->maxNode==-1){
        return 's';
    }
    return pT->L[n];
}

Node root(Tree *pT){
    if(pT->maxNode==-1){
        return NULL_NODE;
    }
    return 0;
}

Node leftMostChild(Node n, Tree* pT){
    if(n<0)
    return NULL_NODE;
    Node i=n+1;
    while(i<=pT->maxNode){
        if(pT->P[i]==n){
            return i;
        }
        else{
            i++;
        }
    }
    return NULL_NODE;  
}

Node rightSibling(Node n, Tree* pT){
    if(n<0)
    return NULL_NODE;
    Node i=n+1;
    while(i<=pT->maxNode){
        if(pT->P[i]==pT->P[n]){
            return i;
        }
        else{
            i++;
        }
    }
    return NULL_NODE;
}

void preorder(Node n, Tree *pT){
    if(pT->maxNode==-1){
        return;
    }
    else{
        printf("%c ",label(n,pT));
        Node i= leftMostChild(n,pT);
        while(i!=NULL_NODE){
            preorder(i,pT);
            i=rightSibling(i,pT);
        }
    }
    printf("\n");
}

void inorder(Node n, Tree *pT){
    if(pT->maxNode==-1){
        return;
    }
    else{
        Node i= leftMostChild(n,pT);
        if(i!=NULL_NODE){
            inorder(i,pT);
        }
        printf("%c ",label(n,pT));
        i=rightSibling(i,pT);
        while(i!=NULL_NODE){
            inorder(i,pT);
            i=rightSibling(i,pT);
        }
    }
        printf("\n");
}

void postorder(Node n, Tree *pT){
    if(pT->maxNode==-1){
        return;
    }
    else{
        Node i= leftMostChild(n,pT);
        while(i!=NULL_NODE){
            postorder(i,pT);
            i=rightSibling(i,pT);
        }
        printf("%c ",label(n,pT));
    }
        printf("\n");
}

int depth(Node n, Tree *pT){
	if(n<0||n>pT->maxNode){
		return -1;
	}
	int d=0;
    while(n>0&&n<=pT->maxNode){
    	n=pT->P[n];
		d++;
	}
	return d;
}

int height(Node n, Tree *pT){
	if(n<0||n>pT->maxNode){
		return -1;
	}
	int i=0, max=0;
	while(i!=pT->maxNode+1){
		int j = i, x=0;
    	while(j>0&&j<=pT->maxNode){
    		j=pT->P[j];
    		x++;
			if(x>max&&j==n){
				max=x;
				break;
			}
		}
		i++;
	}
	return max;
}
 
int main(){
Tree T;
    int n;
    scanf("%d", &n);    //read number of node
    T.maxNode = n - 1;  //maxNode = n - 1

    for (int i = 0; i < n; i++) //read label of nodes
        scanf(" %c", &T.L[i]);

    T.P[0] = NULL_NODE;         //parent of root is NULL_NODE
    for (int i = 1; i < n; i++) //read parent of other nodes
        scanf("%d", &T.P[i]);
    preorder(0,&T);
	inorder(0,&T);  
	postorder(0,&T);
	int u;
	scanf("%d",&u);
	printf("%d\n",height(u,&T));
	printf("%d",depth(u,&T));
	
	
}

