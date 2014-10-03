void search(Node* n, char* key){
	if (n == NULL) {
		printf("Key \"%s\" not found.\n", key);
	}
	else {
		if(key == n->value) {
			printf("Found.\nKey: %s\nValue: %s\n", key, n->value);
		}
		else {
			if(strcmp(key, n->value) > 0) { // key comes after n->value, go right
				search(n->right, key);
			}
			else search(n->left, key);
		}
	}
}


void print(Node* n){
	if(n == NULL) return;
	
	print(n->left);
	printf("Key: %s\nValue: %s\n", n->key, n->value);
	print(n->right);
}