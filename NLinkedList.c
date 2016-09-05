struct ListNode{
	int data;
	struct ListNode *next;
};

void InsertInLinkedList(struct ListNode **head, int data, int index){
	
		struct ListNode *newNode= CreateListNode(data);
	if(index==0){
		newNode->data=data;
		newNode->next=*head;
		**head=*newNode;
	}	
	else{
		for(int i=0;i<index-1;i++){
			top=top->next;
		}
		struct ListNode *node = CreateListNode(data);
		node->next=top->next;
		top->next=node;
	}


}



	
	
	
