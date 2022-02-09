    else if (GetLength(head)==1){
        temp->prev  = head;
        temp->next = head;
        head->next = temp;
        head->prev = temp;
        head = initial;
        return head;
    }