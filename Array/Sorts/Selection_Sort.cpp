// selection sort

vector<int> Selection_Sort(vector<int> array)
{

    for (int i = 0; i < array.size() - 1; i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                
            }
        }

    }
    return array;
}
