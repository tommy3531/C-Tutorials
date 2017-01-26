void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;

}

void bubbleSortArray(int arr[], int n)
{
	int i;
	int j;

	for(i = n; i >= 0; i--)
	{
		for(j = 1; j <= i; j++)
		{
			if(arr[j-1] > arr[j])
			{
				swap(&arr[j-1], &arr[j]);
			}
		}
	}
}

void printArray(int arr[], int size)
{

	for(int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

