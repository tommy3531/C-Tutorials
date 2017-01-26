int binarySearch(int key, int list[], int lo, int hi)
{
	// Search for the key in the list[lo] and list[hi]
	// if found returns the location other wise return -1;
	while(lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if(key == list[mid])
		{
			// Found!!!!
			return mid;

		}

		if(key < list[mid])
		{
			hi = mid - 1;

		}

		else
		{
			lo = mid + 1;

		}
	
	}

	return -1;
}
