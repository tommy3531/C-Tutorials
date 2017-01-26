void insertionSort(int list[], int n)
{
	// sort list[0] to list[n-1] in ascending order
	for (int h = 1; h < n; h++)
	{
		int key = list[h];
		
		// Start comparing with previsour item
		int k = h - 1;

		while(k >= 0 && key < list[k])
		{
			list[k + 1] = list[k];
			--k;
		}

		list[k + 1] = key;

	}
}
