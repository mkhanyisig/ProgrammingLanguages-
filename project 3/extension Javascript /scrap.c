	
	/*
	for n in l{
		strcpy(list[i].word, n->data);
		list[i].freq=n->freq;
		i++;
	}
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	
	Node* array[l->size];  // array of LL size to hold nodes
	
		Node *root; 

		// root points to a node struct
		root = (Node *) malloc( sizeof(Node) ); 

		// set default values to NULL
		root->next = NULL;  
		root->previous=NULL;
		root->count=-1; // word has occured once
		root->data="x";
	 
	printf("  * count : %d\n",root->count); 
	
	
	
	for (int i = 0; i<(l->size); i++){ 
		array[i]=root; // fill array with my null node(count doesn't make sense)
    }
    printf("done\n");
	
	
	
	ll_mapArray(l,mapArray, array, l->size);
	printf(" \n*count : %d\n\n",array[0]->count);
	
	// sorting LL
	
	Node *r; 

		// root points to a node struct
		r = (Node *) malloc( sizeof(Node) ); 
		
		
		// set default values to NULL
		r->next = NULL;  
		r->previous=NULL;
		r->count=-1; // word has occured once
		r->data="x";
	// quality check	
	for(int i=0; i<(l->size);i++){
		printf("\n  d: %s   c: %d\n",array[i]->data,array[i]->count);
	}
	
	for(int i=0; i<(l->size); i++){
         
         //Place the currently selected element array[i] to its correct place.
         
        for(int j=i+1; j<(l->size); j++){
             
             // Swap if currently selected array element is not at its correct position.
             
             //printf("*swaping\n");
            if((array[i]->count) > (array[j]->count)){
            	// swap
            	printf("swaping\n");
                r     = array[i];
                array[i] = array[j];
                array[j] = r;
            }
        }
    }
	*/
	
	
	
	
	
	
	