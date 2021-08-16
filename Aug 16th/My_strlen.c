input != NULL);
    int count = 0;
    while(*input++){
        count++;
    }
    return count;
}


unsigned int my_strlen_improve(const char* input) {//or size_t my_strlen_improve(const char* input)
	assert(input != NULL);
	int count = 0;
	while (*input++){
		count++;
	}
	return count;
}






int main()
{
    char arr[] = "abcdef";
    printf("%d \n", my_strlen(arr));
    printf("%d \n", my_strlen_one(arr));
    printf("%d \n", my_strlen_improve(arr));
    return 0;
}