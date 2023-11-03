struct node
{
    char val;
    struct node* next;
};

void push(struct node** head, char s);
char pop(struct node** head);
char top(struct node* head);
bool isValid(char* s);

void push(struct node** head, char s) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Unable to push");
    } else {
        ptr->val = s;
        ptr->next = *head;
        *head = ptr;
    }
}

char pop(struct node** head) {
    char c;
    struct node* ptr;
    if (*head == NULL) {
        printf("Stack Underflow!");
        return '\0';
    } else {
        c = (*head)->val;
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
        return c;
    }
}

char top(struct node* head) {
    if (head == NULL) {
        return '\0';
    } else {
        return head->val;
    }
}

bool isValid(char* s) {
    int l = strlen(s);
    struct node* head = NULL;  // Static variable to maintain the stack

    for (int i = 0; i < l; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&head, s[i]);
        } else {
            if (top(head) == '\0') {
                return false;
            }
            char ele = pop(&head);
            if ((s[i] == ')' && ele != '(') || (s[i] == '}' && ele != '{') || (s[i] == ']' && ele != '[')) {
                return false;
            }
        }
    }

    // Free the memory allocated for the stack
    //while (head != NULL) {
      //  pop(&head);
    //}

    return (top(head) == '\0');
}
