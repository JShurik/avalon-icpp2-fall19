int FindIndex(int data[], int left, int right, int value)
{
	int middle = (left + right) / 2;
	if (data[middle] == value)
	{
		return middle;
	}
	if (data[middle] > value)
	{
		return FindIndex(data, left, middle - 1, value);
	}
	else
	{
		return FindIndex(data, middle + 1, right, value);
	}
}

int FindIndex(int data[], int size, int value)
{
	return FindIndex(data, 0, size - 1, value);
}

int main()
{
	int data[7] = { 2,4,6,8,10,12,14 };
	int index = FindIndex(data, 7, 4);

}