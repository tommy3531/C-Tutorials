void selectionSort(int list[], int lo, int hi)
{

	// Sort list[lo] to list[hi] in ascending order
	int getSmallest(int[], int, int);
	void swap(int[], int, int);

	// list = 1 2 3 4 5 6 .. 0
	// lo = 0
	// hi = -1
	for(int h = lo; h < hi; h++)
	{
		int s = getSmallest(list, h, hi);
		swap(list, h, s);
	}
}


int getSmallest(int list[], int lo, int hi)
{
	// return location of smallest from list[lo..hi]
	int small = lo;

	for(int h = lo + 1; h <= hi; h++)
	{
		// 1 <= -1 
		// list[
		if(list[h] < list[small])
		{
			small = h;
		}
	}
	return small;
}

void swap(int list[], int i, int j)
{
	//Swap elements list[i] and list[j]
	int hold = list[i];
	list[i] = list[j];
	list[j] = hold;
}
